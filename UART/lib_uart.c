int		ft_strcmp(const char *s1, const char *s2)
{
	while (*s1 != '\0' || *s2 != '\0')
	{
		if (*s1 != *s2)
			return ((unsigned char)*s1 - (unsigned char)*s2);
		s1++;
		s2++;
	}
	return (0);
}

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

	//check if buffer is full
	if (U1STAbits.UTXBF == 1)
		return 1;
	while (i++ < 8 && *buffer)
		U1TXREG = *buffer++;
	return (0);
}

void	ReadUART(char buffer[])
{
	int	i = 0;

	// check data ready in buffer, then read
	while (DataRdyUART())
		buffer[i++] = U1RXREG;
}
								
void		UARTSendBreak(void)
{
	if (U1STAbits.TRMT != 1)
		return (1);	
	U1STAbits.UTXBRK = 1;
	// dummy read
	UT1XREG = 0x10;
	UT1XREG = 0x50;
}

void		CloseUART(void)
{
	U1MODEbits.ON = 0;
}

void		ConfigIntUART()
{
	// see interrupt section
}

int			DataRdyUART()
{
	//data ready, return 1
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

int			main(void)
{
	char	*send = "hello";
	char	response[];	

	TRISDbits.TRISD0 = 0;
	TRISDbits.TRISD1 = 0;
	TRISDbits.TRISD2 = 0;

	LATD = 0x00;

	OpenUART();
	WriteUART(test);
	ReadUART(response);
	if (strcmp("ok", response))
		LATD = 0x04;			
	while (1);
	return (0);
}
