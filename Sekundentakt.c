/**********************************************************/
/* Sekundentakt mit AVR-Timer                             */
/* Berechnung des Takts:                                  */
/* 65536 - (Zeit * Taktrate / Prescaler)                  */
/* Beispiel:                                              */
/* 65536 - (1s * 16.000.000 Hz / 1024) = 49911            */
/**********************************************************/

#include <avr/io.h>
#include <avr/interrupt.h>

ISR(TIMER1_OVF_vect) 
{
    TCNT1 = 49911;         // Vorladewert
    PORTD ^= (1 << PD0);   // LED umschalten
}

int main(void)
{
    DDRD |= (1 << PD0);    // PD2 ist LED Ausgang
    
    // Timerdefinitionen
    // Timer 1 (16-Bit-Timer)
    // Prescaler = 1024
    TIMSK  |= (1<<TOIE1);
    TCCR1B |= (1<<CS10) |  (1<<CS12);     
    TCNT1 = 0xFFFF;        // Vorladewert zum Start des Timers
    
    sei();                 // Interrupts aktivieren
    
    while (1) 
    {
        // Hauptprogramm
        // Endlosschleife
    }
    
    return(0);
}
