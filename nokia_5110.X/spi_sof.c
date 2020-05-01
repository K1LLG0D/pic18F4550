#include <xc.h>
#include <stdint.h>
#include <stdio.h>
#include "spi_sof.h"

 //aqui define las salidas de pic, pueden cambiarlos
void spi_init_master(void)
{
    // Pines MOSI, SCK y CS como salida, pin MISO como entrada
    TRISDbits.RD0 = 0; // SPI_MOSI
    TRISDbits.RD1 = 1; // SPI_MISO
    TRISDbits.RD2 = 0; // SPI_SCK
    TRISDbits.RD3 = 0; // SPI_CS


}

void spi_init_slave(void){
    TRISDbits.RD0 = 1; // SPI_MOSI cambia a entrada para el esclavo
    TRISDbits.RD1 = 0; // SPI_MISO cambia a salida para el esclavo
    TRISDbits.RD2 = 1; // SPI_SCK recibe el clck
    TRISDbits.RD3 = 1; // SPI_CS activa o desactiva el dispositivo
    
}





void spi_write(uint8_t data) {
    
    for (int i = 0; i < 8; i++)
    {
        // Checa el bit mas significativo y 
        // lo pone en
        // el bus (PIN MOSI)
        if ((data << i) & 0x80){
            SPI_MOSI = HIGH;
        }
        else{
            SPI_MOSI = LOW;
        }
        // Envía pulso de reloj 
        SPI_SCK = LOW;
        __delay_us(100);
        SPI_SCK = HIGH;
        __delay_us(100);
    }
 
   
    
}
 
uint8_t spi_readwrite(uint8_t data)
{
    uint8_t rd = 0;
 
    // Selecciona el dispositivo SPI con CS=0
    SPI_CS = LOW;
 
    for (int i = 0; i < 8; i++)
    {
        rd =  rd <<1;
        // Checa el bit mas significativo y lo pone en
        // el bus (PIN MOSI)
        if ((data << i) & 0x80)
            SPI_MOSI = HIGH;
        else
            SPI_MOSI = LOW;
 
        // Envía pulso de reloj (CHPOL = )
        SPI_SCK = LOW;
        __delay_us(10);
 
        // Lee el bit recibido en MISO
        if (SPI_MISO == 1){
            rd |= 1;
        }
 
        SPI_SCK = HIGH;
        __delay_us(10);
 
    }
 
    // Libera el dispositivo SPI con CS=1
    SPI_CS = HIGH;
 
    return rd;
}
