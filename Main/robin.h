#ifndef
# define ROBIN_H

int		intqueue[1000];

int		robin;

enum		e_robinstate
{
	READY = 0,
	BLUETOOTH,
	SENSOR_FP1
	SENSOR_FP2,
	SENSOR_LEVEL,
	SENSOR_POWER,
	LED,
};

typedef enum e_robinstate		t_robinstate;

enum	e_intflag
{
	EMPTY = 0,
	UART_RD,
	I2C_RD
};

typedef enum e_intflag			t_intflag;

struct s_input
{
	t_intflag	intflag;
	void		(*read)();
};

typedef struct s_input			t_input;

struct s_module
{
	t_robinstate	robinstate;
	void			(*module)();
}

typedef struct s_module			t_module;
	
#endif
