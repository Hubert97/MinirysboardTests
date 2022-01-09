#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <errno.h>
#include <termios.h>
#include <unistd.h>

#include <unistd.h>
#include <cstdlib>
#include <signal.h>

#include <time.h> //nanosleep()

#include "RysCom.h"

#include<iostream>
using namespace std;

FILE *fp;
RysCom com;

void signal_callback_handler(int signum) {
   cout << "Caught signal " << signum << endl;
   // Terminate program
   com.ping();
    fclose(fp);
   exit(signum);
}



int main() {   
     signal(SIGINT, signal_callback_handler);

    com.ping();

    com.set_register(0x09,0xFE);
    uint8_t nastaw_wentylatora = com.get_register(0x09);
    uint16_t analogregs[10];

    
    fp = fopen("Rysboard_Analog_Data.csv", "w+");
    fprintf(fp, "VBat1,VBat2,VBat3,TEx1,TEx2,TIn1,TIn2,Curr,5VLine,12VLine,TIn3\n");

    while(1)
    {
        for (uint8_t i = 11; i< 22; ++i)
        {
            fprintf(fp,"%4d,", com.get_register(i));
        }
        fprintf(fp,"\n");
        //usleep(10000);
        com.ping();
        usleep(100000);
    }
    com.ping();
    return 0;
}   