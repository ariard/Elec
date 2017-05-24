void	OpenUART(void)
{
	//set standard speed mode
	U1MODEbits.BRGH = 0;
	//configure Baud rate
	U1BRG = ((FPB/9600) / 16) - 1;

	// set data format as 8-bit data, no parity
	U1MODEbits.PDSEL = 0; 
	// set 1 Stop bit
	U1MODEbits.STSEL = 0;

	//enable transmitter
	U1STAbits.UTXEN = 1;
	//clear interrupt transmit
	U1STAbits.UTXISEL = 10;

	//enable receiver
	U1STAbits.URXEN = 1;
	//clear interrupt receive
	U1STAbits.URXISEL = 10;

	// enable UART module 
	U1MODEbits.ON = 1;
}

int		WriteUART(char *buffer)
{
	int	i = 0;:

	U1STAbits.TRMT = 0;	
	if (U1STAbits.UTXBF == 1)
		return 1;
	while (i++ < 8 && *buffer)
		U1TXREG = *buffer++;
}

char	ReadUART(char buffer[])
{
	int	i = 0;

	while (DataRdyUART())
		buffer[i++] = U1RXREG;
}
								
void		UARTSendBreak(void)
{
	if (U1STAbits.TRMT != 1)
		return (1);	
	U1STAbits.UTXBRK = 1;
	UT1XREG = 0x10;
	UT1XREG = 0x50;
}

void		CloseUART(void)
{
	U1MODEbits.ON = 0;
}

void		ConfigIntUART()
{
	;
}

int			DataRdyUART()
{
	if (U1STAbits.URXDA == 1)
		return (1);
}


void		EnableIntURX
{
	U1STAbits.URXEN = 1;
}

void		EnableIntUTX
{
	U1STAbits.UTXEN = 1;
}

void		DisableIntURX
{
	U1STAbits.URXEN = 0;
}

void		DisableIntUTX
{
	U1STAbits.UTXEN = 0;
}
