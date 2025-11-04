// EX 2.1 External Interrupt (Button on INT0)
// 2) Bare-Metal Programming Version

#include <avr/io.h>
#include <avr/interrupt.h>

// ISR for INT0 interrupt
ISR(INT0_vect) {
  PORTB ^= (1 << PB5); 
}

int main(void) {
  DDRB |= (1 << PB5);   // D13 - output
  DDRD &= ~(1 << PD2);  // D2 - input
  PORTD |= (1 << PD2);  // pull-up resistor

  EICRA |= (1 << ISC01);  // Falling edge
  EIMSK |= (1 << INT0); 

  sei();  // enable global interrupt

  while (1) {
  }
}
