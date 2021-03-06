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
  auto finish = std::chrono::high_resolution_clock::now();
  std::chrono::duration<double> elapsed = finish - start;

  FILE *fpr;
  fpr = fopen("Uart_Latency_Read.csv", "w+");
  fprintf(fpr, "Latency[ms]\n");

  for (int i = 0; i<no_of_tests;++i)
  {
    start = std::chrono::high_resolution_clock::now();
    if( com.get_register(0x09) == 0xFE)
    {
      finish = std::chrono::high_resolution_clock::now();
      elapsed = finish - start;
      fprintf(fpr, "%f\n",elapsed.count()*1000);
      good_answers++;

    }
    else
    {
      bad_answers++;
    }
  }
fclose(fpr);
  
// Record end time
 
  com.ping();

  printf("Reading Test Done\n");
  fflush(stdout);

  good_answers = 0;
  bad_answers = 0;

  FILE *fpw;
  fpw = fopen("Uart_Latency_Write.csv", "w+");
  fprintf(fpw, "Latency[ms]\n");


    for (int i = 0; i < no_of_tests; ++i)
  {
    start = std::chrono::high_resolution_clock::now();
    if( com.set_register(0x09,0xFE) == 0x02)
    {
      finish = std::chrono::high_resolution_clock::now();
      elapsed = finish - start;
      fprintf(fpw, "%f\n",elapsed.count()*1000);
      good_answers++;
    }
    else
    {
      bad_answers++;
    }
  }
  fclose(fpw);

  printf("Writing test done\n");

  return 0;
}