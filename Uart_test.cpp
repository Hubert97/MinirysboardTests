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
  com.ping();
  com.ping();
  com.ping();
  com.ping();
  com.ping();
  com.set_register(0x09,0xFE);
  uint8_t nastaw_wentylatora = com.get_register(0x09);
  
  for (uint8_t i = 0; i< 22; ++i)
  {
    printf("Rejestr: %2d Ma wartosc: %4d \n",i, com.get_register(i));
  }

  return 0;
}