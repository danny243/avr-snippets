/**********************************************************/
/* Hello World für AVR                                    */
/* PORTB: LEDs                                            */
/* PORTD: Taster                                          */
/* Für jeden gedrückten Taster leuchtet die entsprechende */
/* LED auf.                                               */
/**********************************************************/

#include <avr/io.h>

int main(void)
{
    // Initialisierung der Ports
    DDRB  = 0xFF;       // PORTB ist Ausgang
    DDRD  = 0x00;       // PORTD ist Eingang
    PORTD = 0xFF;       // Pullup-Widerstände aktivieren
    
    uint8_t temp;       // Variable für Tasterwerte
    
    while (1)
    {
        // Hauptprogramm in Endlosschleife
        temp  = PIND;   // Tasterwerte speichern
        PORTB = temp;   // Tasterwerte an PORTB ausgeben
    }
    
    return(0);
}
