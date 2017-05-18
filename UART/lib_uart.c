void	OpenUART(void)
{
		//configure Baud rate
		U1BRG = ((FPB/9600) / 16) - 1;

		// set data format as 8-bit data, no parity
		U1MODEbits.PDSEL = 0; 
		// set 1 Stop bit
		U1MODEbits.STSEL = 0;

		//enable receiver
		U1STAbits.URXEN = 1;
		//enable transmitter
		U1STAbits.UTXEN = 1;
}

int		WriteUART(char *buffer)
{
	if (U1STAbits.UTXBF == 1)
		return 1;
		
