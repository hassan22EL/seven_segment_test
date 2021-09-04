/*
 * File:   testunit.c
 * Author: hassa
 *
 * Created on 03 ??????, 2021, 01:28 ?
 */


#include <xc.h>
#include "../SevenModule.X/module.h"
#define F_CPU 8000000UL

void Init() {
    DDRC |= (1 << PC0); //A pin as output
    DDRC |= (1 << PC1); //B pin as output
    DDRC |= (1 << PC2); //C pin as output
    DDRC |= (1 << PC3); //D  pin as output
    DDRC |= (1 << PC4); //E pin as output
    DDRC |= (1 << PC5); //F pin as output
    DDRC |= (1 << PC6); //G pin as output
    DDRC |= (1 << PC7); //EN pin as output
    DDRB |= (0 << PB0);
    DDRB |= (0 << PB1);
    DDRB |= (0 << PB2);
    DDRD |= (1 << PD0);
    DDRD |= (1 << PD1);
    DDRD |= (1 << PD2);
    DDRD |= (1 << PD3);
    DDRD |= (1 << PD4);
    DDRD |= (1 << PD5);
    DDRD |= (1 << PD6);
    PORTC = 0x3F;


}

void ReadSwitch() {
    MODbits.MOD = PINB;
}

int main(void) {
    Init();

    _7MODULE_State NextState = IDELS();
    _7MODULE_Events event = 0;

    while (1) {
        ReadSwitch();
        event = ReadEvent();
        InterfacingModule(NextState, event , 3);
    }

}


