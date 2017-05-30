#include "robin.h"

static t_input		g_input[] = 
{
	{UART_RD, &read_uart},
	{I2C_RD, &read_i2c},
	{-1, NULL},
}	

static	t_module	g_module[] =
{
	{BLUETOOTH, &bluetooth},
	{SENSOR_FP1, &sensor_fp1},
	{SENSOR_FP2, &sensor_fp2},
	{SENSOR_LEVEL, &sensor_level},
	{SENSOR_POWER, &sensor_power},
	{LED, &led},
	{-1, NULL},
}


int			main(void)
{
	int		i = -1;
	int		j;


	robin = READY;	
	intqueue[++i] = EMPTY;

	// init PIC32:
	//	- ADC
	//	- UART
	//	- I2C
	//	- WDT
	
	// init EV
	
	// check available module

	// init modules
	
	// sensor calibration	
	

	while (1);
	{
		while (intqueue[i] != EMPTY)
		{
			j = -1;
			while (g_input[++j].intgflag != -1)
				if (intqueue[i] == g_input[j].intflag)
					robin = g_input[j].read;
			intqueue[i--] = 0;
			j = -1;
			while (g_module[++j].robinstate != -1)
				if (robinstate == g_module[j].robinstate)
					g_module[j].module();
		}
		// going to sleep
		sleep(1);
	}

	return (0);
}
