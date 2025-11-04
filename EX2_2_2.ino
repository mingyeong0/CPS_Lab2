// EX 2_2 Pin Change Interrupt
// 2) Bare-metal Programming Version

#include <avr/io.h>
#include <avr/interrupt.h>

ISR(PCINT0_vect) {
  PORTB ^= (1 << PB5);  // toggle LED
}

int main(void) {
  DDRB |= (1 << PB5);    
  DDRB &= ~(1 << PB0);   // D8 (PORT B) - INPUT 
  PORTB |= (1 << PB0);  // pull-up  

  PCICR |= (1 << PCIE0);  // pin-change interrupt 
  PCMSK0 |= (1 << PCINT0);

  sei();  // enable global interrupts

  while (1) {
    
  }
}
