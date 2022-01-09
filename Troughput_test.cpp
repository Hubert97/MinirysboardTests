#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <errno.h>
#include <termios.h>
#include <unistd.h>

#include <chrono>  // for high_resolution_clock

#include "RysCom.h"

#include<iostream>
using namespace std;

int main() {

  printf("Speed Test start\n");
  RysCom com;
  while (com.ping() != 0x03)
  {
    printf("Connection Error\n");
    usleep(1000000);
  }
  printf("Connected\n");

 // const int no_of_tests = 2000000; // Two Milion tousand Reads so 4 Mbytes of data
  const int no_of_tests = 200000; // Two hundred tousand Reads so 400 Kbytes of data

  //const int no_of_tests = 20000; // Twenty tousands reads so 40 Kbytes of data
  int good_answers = 0;
  int bad_answers = 0;
  com.set_register(0x09,0xFE);
  auto start = std::chrono::high_resolution_clock::now();
  for (int i = 0; i<no_of_tests;++i)
  {
    if( com.get_register(0x09) == 0xFE)
    {
      good_answers++;
    }
    else
    {
      bad_answers++;
    }
  }
  
// Record end time
  auto finish = std::chrono::high_resolution_clock::now();
  com.ping();
  std::chrono::duration<double> elapsed = finish - start;
  printf("Reading :\n        Test Time: %f, Transfer speed: %f KB/s, Real: %f KB/s, Good reads: %d Bad reads %d \n", elapsed.count(), ((2*no_of_tests)/elapsed.count())/1000,((4*no_of_tests)/elapsed.count())/1000,good_answers,bad_answers );
  fflush(stdout);

  good_answers = 0;
  bad_answers = 0;

  start = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < no_of_tests; ++i)
  {
    if( com.set_register(0x09,0xFE) == 0x02)
    {
      good_answers++;
    }
    else
    {
      bad_answers++;
    }
  }
  finish = std::chrono::high_resolution_clock::now();
  elapsed = finish - start;
  printf("Writing :\n        Test Time: %f, Transfer speed: %f KB/s, Real: %f KB/s, Good reads: %d Bad reads %d \n", elapsed.count(), ((2*no_of_tests)/elapsed.count())/1000,((5*no_of_tests)/elapsed.count())/1000,good_answers,bad_answers );



  return 0;
}