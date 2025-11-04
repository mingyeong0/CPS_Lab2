// EX 2.3 Timer Interrupt 

#include <avr/io.h>
#include <avr/interrupt.h>

#include <avr/io.h>
#include <avr/interrupt.h>

ISR(TIMER1_COMPA_vect) {
  PORTB ^= (1 << PB5);  // Toggle LED (D13)
}

int main(void) {
  DDRB |= (1 << PB5);   // D13 (PB5) - output (LED)

  TCCR1B |= (1 << WGM12);  // Set Timer1 to CTC mode

  OCR1A = 15625;  // Compare match occurs every 1 second

  TIMSK1 |= (1 << OCIE1A);  //  Enable compare interrupt

  TCCR1B |= (1 << CS12) | (1 << CS10); // Set prescaler to 1024

  sei();  // Enable global interrupt

  while (1) {
 
  }
}

