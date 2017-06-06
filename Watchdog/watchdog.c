void	ConfigureWatchdog(void)
{
	//check FWDTEN configuration bit, if it is set the WDT is always enabled
	if (DEVCFG1bits.FWDEN != 1)
		WDTCONbits.ON = 1;
	//set WDT prescaler	
	DEVCFG1bits.WDTPS = 100;
	
	
