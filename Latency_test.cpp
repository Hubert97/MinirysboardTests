// SOURCE: https://blog.mbedded.ninja/programming/operating-systems/linux/linux-serial-ports-using-c-cpp/
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

  printf("Latency Test start\n");
  RysCom com;
  while (com.ping() != 0x03)
  {
    printf("Connection Error\n");
    usleep(1000000);
  }
  printf("Connected\n");

  //const int no_of_tests = 2000000; // Two milion Reads so 4 Mbytes of data

  const int no_of_tests = 20000; // Two tousands reads so 4 Kbytes of data
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
  com.ping();
// Record end time
  auto finish = std::chrono::high_resolution_clock::now();
  std::chrono::duration<double> elapsed = finish - start;
  printf("Czytanie :\n         Czas testu: %f, Prędkosc transferu: %f KB/s, Rzeczywista: %f KB/s, Ilosc poprawnych danych: %d Ilosc zlych danych %d \n", elapsed.count(), ((2*no_of_tests)/elapsed.count())/1000,((4*no_of_tests)/elapsed.count())/1000,good_answers,bad_answers );


  good_answers = 0;
  bad_answers = 0;

  start = std::chrono::high_resolution_clock::now();
    for (int i = 0; i<no_of_tests;++i)
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
  printf("Pisanie :\n         Czas testu: %f, Prędkosc transferu: %f KB/s, Rzeczywista: %f KB/s, Ilosc poprawnych danych: %d Ilosc zlych danych %d \n", elapsed.count(), ((2*no_of_tests)/elapsed.count())/1000,((5*no_of_tests)/elapsed.count())/1000,good_answers,bad_answers );



  return 0;
}