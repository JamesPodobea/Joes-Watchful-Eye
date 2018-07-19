/*
Author: Joe Michaels
Company: Brute Softworks
Date: 5/24/2017
 */


#include <stdio.h>
#include <stdlib.h>
#include <wiringPi.h>


#define PIR 0
#define ISRDelay 1000 // 1 second delay

volatile int t;

void ISR(void);
		
int main(void)
{
  //gcc -Wall -o Eye watchfulEye.c -lwiringPi

  wiringPiSetup();
	  
  if (wiringPiISR(PIR, INT_EDGE_RISING, &ISR) < 0)
  {
    printf("unable to setup ISR.\n");
  }else
  {
    printf("ISR setup complete.\n");
  }
  
   while(1)
  {
   
  }

  //system("sudo ./../../webcam/webcam.sh"); 
	
  return 0;
}

void ISR(void)
{
  if(millis() - t >= ISRDelay)
  {
    t = millis();
    system("sudo ./webcam/webcam.sh"); 
  }
}
