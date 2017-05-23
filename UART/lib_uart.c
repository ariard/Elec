void	OpenUART(void)
{
		//configure Baud rate
		U1BRG = ((FPB/9600) / 16) - 1;

		// set data format as 8-bit data, no parity
		U1MODEbits.PDSEL = 0; 
		// set 1 Stop bit
		U1MODEbits.STSEL = 0;

		//enable transmitter
		U1STAbits.UTXEN = 1;
		//clear interrupt transmit
		U1TXIFbits.UTXISEL = 10;

		//enable receiver
		U1STAbits.URXEN = 1;

		// enable UART module 
		U1MODEbits.ON = 1;
}

int		WriteUART(char *buffer)
{
	int	i = 0;:

	U1STAbits.TRMT = 0;	
	if (U1STAbits.UTXBF == 1)
		return 1;
	while (i++ < 8)
}
								
void		UARTSendBreak(void)
{
	if (U1STAbits.TRMT != 1)
		return 1;		
	U1STAbits.UTXBRK = 1;
//	WRITE dummy on U1TXREG
//	WRITE 0x55 on U1TXREG
