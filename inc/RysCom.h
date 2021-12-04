/*
 * msm_runtime.h
 *
 *  Created on: 03 gru 2021
 *      Author:  Hubert Kowalski
 */

#ifndef RYS_COM_H_
#define RYS_COM_H_
#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <fcntl.h>
#include <errno.h>
#include <termios.h>
#include <unistd.h>

union COM_Data{
	uint8_t buf8[2];
	uint16_t buf16;
};



class RysCom {
public:
RysCom(){
serial_port = open("/dev/ttyS0", O_RDWR);  
tcgetattr(serial_port, &tty);

  
tty.c_cflag &= ~PARENB;
tty.c_cflag &= ~CSTOPB;
tty.c_cflag &= ~CSIZE;
tty.c_cflag |= CS8;
tty.c_cflag &= ~CRTSCTS;
tty.c_cflag |= CREAD | CLOCAL;  tty.c_lflag &= ~ICANON;

tty.c_lflag &= ~ECHO;
tty.c_lflag &= ~ECHOE;
tty.c_lflag &= ~ECHONL;
tty.c_lflag &= ~ISIG;
tty.c_iflag &= ~(IXON | IXOFF | IXANY);
tty.c_iflag &= ~(IGNBRK|BRKINT|PARMRK|ISTRIP|INLCR|IGNCR|ICRNL);  tty.c_oflag &= ~OPOST;
tty.c_oflag &= ~ONLCR;  tty.c_cc[VTIME] = 10;
tty.c_cc[VMIN] = 0;  

//cfsetispeed(&tty, B9600);
//cfsetospeed(&tty, B9600);  

cfsetispeed(&tty, B576000);
cfsetospeed(&tty, B576000);  

tcsetattr(serial_port, TCSANOW, &tty);


}
~RysCom(){
    close(serial_port);
}

uint8_t ping()
{

unsigned char msg[1];
msg[0] = 0x03;

write(serial_port, msg , 1);
char read_buf [1];  
memset(&read_buf, '\0', sizeof(read_buf));

int num_bytes = read(serial_port, &read_buf, 1);
    
    if (num_bytes < 0) {
        printf("Error reading: %s", strerror(errno));
    }  

//printf("Read %i bytes. Received mesydz: %x \n", num_bytes, read_buf[0]);  
return read_buf[0];
}

uint8_t set_register(uint8_t reg, uint16_t data)
{
    //send data
    union COM_Data translator;
    translator.buf16 = data;        
    uint8_t msg[5];
    msg[0] = 0x02; msg[1] = reg; msg[2] = translator.buf8[0];  msg[3] = translator.buf8[1]; msg[4] = 0x02;
    write(serial_port, msg , 5);

    //check response
    char read_buf [1];  
    int num_bytes = read(serial_port, &read_buf, 1);
        if (num_bytes < 0) {
        printf("Error reading: %s", strerror(errno));
    }  
 //   printf("Read %i bytes. Received mesage: %x \n", num_bytes, read_buf[0]);  
    return read_buf[0];

}


uint16_t get_register(uint8_t reg)
{
    //send data
    union COM_Data translator;
    uint8_t msg[3];
    msg[0] = 0x01; msg[1] = reg; msg[2] = 0x01;
    write(serial_port, msg , 5);

    //check response
    uint8_t read_buf [4]; 
    read_buf [0] = 0x00; 
    read_buf [1] = 0x00; 
    read_buf [2] = 0x00; 
    read_buf [3] = 0x00; 

    //usleep(10000); //for 9600
    usleep(600); //for B576000
    int num_bytes = read(serial_port, &read_buf, 4);
        if (num_bytes < 0) {
        printf("Error reading: %s", strerror(errno));
    }  

    //printf("Read %i bytes. Received mesage: <%x> <%x> <%x> <%x>\n", num_bytes, read_buf[0], read_buf[1], read_buf[2],read_buf[3]);  
    translator.buf8[0] = read_buf[1];
    translator.buf8[1] = read_buf[2];
    return translator.buf16;

}


private:
int serial_port;
struct termios tty; 


};


#endif /* RYS_COM_H_ */