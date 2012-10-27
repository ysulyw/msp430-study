#include <msp430.h>
#include <stdio.h>

#define LED0 BIT0 // 0b00000001
#define LED1 BIT6 // 0b01000000

#define LED0_ON P1OUT |= LED0
#define LED0_OFF P1OUT &=~ LED0
#define LED0_TOGGLE P1OUT ^= LED0
#define LED1_ON P1OUT |= LED1
#define LED1_OFF P1OUT &=~ LED1
#define LED1_TOGGLE P1OUT ^= LED1

/** wait 1 sec **/
void delay(unsigned int d) {
  unsigned int i;
  for (; d > 0; d--) {
    for(i = 0; i < 32767; i++){
        nop(); nop(); nop(); nop(); nop();
        nop(); nop(); nop(); nop(); nop();
        nop(); nop(); nop(); nop(); nop();
        nop(); nop(); nop(); nop(); nop();
        nop(); nop(); nop(); nop(); nop();
        nop(); nop(); nop(); nop(); nop();
    }
  }
}

int main(void) {
  WDTCTL = WDTPW + WDTHOLD;
  P1DIR |= LED0 + LED1;
  
  while(1) {
    LED0_ON;
    LED1_OFF;
    delay(1);
    LED0_OFF;
    LED1_ON;
    delay(1);
  }
}
