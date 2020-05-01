// Define los puertos y los pines del micro para SPI
#define LOW 0
#define HIGH 1
#define SPI_MOSI    LATDbits.LATD0
#define SPI_MISO    PORTDbits.RD1
#define SPI_SCK     LATDbits.LATD2
#define SPI_CS      LATDbits.LATD3   //SS para uno se puede agregar mas
#define _XTAL_FREQ 8000000UL

void spi_init_master(void);
void spi_init_slave(void);
void spi_write(unsigned char data);
//unsigned uint8_t spi_readwrite(unsigned uint8_t data);
 