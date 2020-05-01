
#define DC LATDbits.LATD4    // conect a DC     
#define RES LATDbits.LATD5   // connected to reset 


void Nokia_Init(void);
void Nokia_SendCommand(char);
void Nokia_SendData(char);
void Nokia_SendString(char *);
void MSdelay(unsigned int);
void Nokia_Clear(void);
void Nokia_PositionXY(char, char);