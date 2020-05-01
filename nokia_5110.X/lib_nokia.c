#include <xc.h>
#include "spi_sof.h"
#include "Nokia_Font.h"
#include "lib_nokia.h"


void Nokia_SendCommand(char cmd)
{
    DC = LOW;         /* Data/Command pin, D/C=1 - Data, D/C = 0 - Command*/
    SPI_CS = LOW;         /* enable chip */
    spi_write(cmd); /* write command to the Nokia 5110 */
    SPI_CS = HIGH;         /* disable chip */
}
void Nokia_SendData(char dat)
{   
    char i;
    DC = HIGH;         /* Data/Command pin, D/C=1 - Data, D/C = 0 - Command*/
    SPI_CS = LOW;         /* enable chip */
    for(i=0;i<5;i++){
        spi_write(font[(dat) - (0x20)][i]); /* write data to the Nokia 5110 */ 
    }
    SPI_CS = HIGH;         /* disable chip */
    
void Nokia_SendString(char *data)
{
    char i;
    while((*data)!=0)
    {   
        Nokia_SendData(*data);
        data++;
    }
    
}
void Nokia_PositionXY(char X, char Y)
{
    Nokia_SendCommand(0x80 | X);    /* set X position */
    Nokia_SendCommand(0x40 | Y);    /* set Y position */  
}

void Nokia_Init(void)
{
    /*apply 100 ms reset(low to high) pulse */
    RES = 0;                    /* enable reset */
    
    __delay_ms(100);
    
    RES = 1;                    /* disable reset */
    Nokia_SendCommand(0x21);    /* display extended commands*/
    Nokia_SendCommand(0x13);    /* select Bias voltage*/
    Nokia_SendCommand(0x07);    /* set temperature coefficient*/
    Nokia_SendCommand(0xC0);    /* set LCD Vop for contrast */   
    Nokia_SendCommand(0x20);    /* display basic commands */    
    Nokia_SendCommand(0x0C);    /* set normal mode */
   
}

void Nokia_Clear(void)
{
    char i,j;
    SPI_CS = LOW;
    DC = HIGH;
    for(i=0;i<6;i++)
    {   
        for(j=0;j<84;j++)
            spi_write(0);       /*write 0 to clear display */
    }      
    SPI_CS = HIGH;
    
}


