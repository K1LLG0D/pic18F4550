#pragma config FOSC = INTOSCIO_EC// Oscillator Selection bits (Internal oscillator, port function on RA6, EC used by USB (INTIO))
#pragma config PWRT = ON        // Power-up Timer Enable bit (PWRT enabled)
#pragma config BOR = OFF        //  Brown-out Reset Enable bits (Brown-out Reset disabled in hardware and software)
#pragma config WDT = OFF        // Watchdog Timer Enable bit (WDT disabled (control is placed on the SWDTEN bit))
#pragma config CCP2MX = OFF     // CCP2 MUX bit (CCP2 input/output is multiplexed with RB3)
#pragma config PBADEN = OFF      // PORTB A/D Enable bit (PORTB<4:0> pins are configured as analog input channels on Reset)
#pragma config MCLRE = ON       // MCLR Pin Enable bit (MCLR pin enabled; RE3 input pin disabled)
#pragma config LVP = OFF        // Single-Supply ICSP Enable bit (Single-Supply ICSP disabled)
#pragma config BORV = 3         // Brown-out Reset Voltage bits (Minimum setting 2.05V)


#include <xc.h>
#include "spi_sof.h"
#include "Nokia_Font.h"
#include "lib_nokia.h"
#define _XTAL_FREQ 8000000UL


void main(void){
    OSCCON = 0X72; 
    TRISD = 0;                  /* set PORT as output port*/
    spi_init_master();          /* initialize SPI master*/
    Nokia_Init();               /* initialize Nokia 5110 display */
    Nokia_Clear();              /* clear Nokia display */
    //Nokia_PositionXY(0,0);      /* set X and Y position for printing */
    //Nokia_SendString("KILLGOD");
    Nokia_PositionXY(0,1);      /* set X and Y position for printing */
    Nokia_SendString("DOS LIBRERIA NACEN");
    Nokia_PositionXY(0,2);      /* set X and Y position for printing */
    Nokia_SendString("1 SPI POR SOFTWRE");
    Nokia_PositionXY(0,3);      /* set X and Y position for printing */
    Nokia_SendString("2 LIBRERIA PARA ");
    Nokia_PositionXY(0,4);      /* set X and Y position for printing */
    Nokia_SendString("Nokia 5110");
    
    
    
    
    while(1){
        __delay_ms(3000);
        Nokia_Clear();
        Nokia_PositionXY(0,2);      /* set X and Y position for printing */
        Nokia_SendString("Adios pic18f4550");
    
    }
}