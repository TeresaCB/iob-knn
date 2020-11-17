#include "system.h"
#include "periphs.h"
#include <iob-uart.h>
#include "iob_timer.h"
#include "iob_knn.h"
#include "random.h" //random generator for bare metal
#include <stdint.h>

#define S 12

int main()
{
  //init uart 
  uart_init(UART_BASE,FREQ/BAUD);   
  uart_printf("\n\n\nFilter and rectify\n\n\n");
  //char *a = malloc(10);
  //free(a);
  
  int32_t y[100] = {0};
  int32_t x[100] = {0};
  
  random_init(S);
  
  for(int i=0; i<100; i++) {

    x[i] = (short) cmwc_rand();
    
    if(i==0)
    	y[i] = abs(x[i]);
    else
    	y[i] = y[i-1] + abs(x[i]);

  }
    
  
  for(int j=0; j<100; j++)
  {
  	uart_printf("\n\n x(%d) = %d \n ", j, x[j]);
  	uart_printf("\n y(%d) = %d \n\n ", j, y[j]);
  }
  
  return 0;
  
}
