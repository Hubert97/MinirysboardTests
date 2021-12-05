// SOURCE: https://blog.mbedded.ninja/programming/operating-systems/linux/linux-serial-ports-using-c-cpp/
#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <errno.h>
#include <termios.h>
#include <unistd.h>

#include "RysCom.h"

#include<iostream>
using namespace std;

int main() {

    RysCom com;
    com.ping();
    printf("FAN Test\n");
    com.set_register(0x09,0x80);
    if( com.get_register(0x09) != 0x80 )
    {
        printf("Com Err\n");
        exit(0);
    }

    for (uint8_t i = 0; i< 22; ++i)
    {
        printf("Reg: %2d Val: %5d \n",i, com.get_register(i));
    }

    if(com.get_register(0x06) == 0x00)
    {
        printf("Enabling Stepper Motors... ");
        com.set_register(0x03,0x10);
        usleep(100000);
        if( com.get_register(0x06) == 0x02 )
        {
            printf("Enabled\n");
        }    
        else
        {
            printf("Error\n");
            exit(0);
        }

        printf("Enabling TOFs... ");
        com.set_register(0x03,0x80);
        usleep(100000);
        if( com.get_register(0x06) == 0x03 )
        {
            printf("Enabled\n");
        }    
        else
        {
            printf("Error\n");
            exit(0);
        }
        for (uint8_t i = 0; i< 22; ++i)
        {
            printf("Reg: %2d Val: %5d \n",i, com.get_register(i));
        }
    }
    else{

            printf("NONE state is not selected - efectors are probably on.");
    }
    
    return 0;
}