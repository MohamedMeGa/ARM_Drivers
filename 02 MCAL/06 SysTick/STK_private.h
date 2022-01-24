/************************************************************/
/*   		AUTHOR      : Mohamed	MeGa           		  	*/
/*   		Description : SysTick DRIVER                    */
/*   		DATE        : 15 DEC 2021                   	*/
/*   		VERSION     : V01                            	*/
/************************************************************/

#ifndef	STK_PRIV_H
#define	STK_PRIV_H


/************************************************************/
/**			Register  	DEFINITION							*/
/************************************************************/
typedef	struct{
	volatile	u32	CTRL;
	volatile	u32	LOAD;
	volatile	u32	VAL;
	volatile	u32	CALIB;
}STK_t;


/**			Base Address									*/
#define	STK	((volatile	STK_t *)0xE000E010)
#define	NULL	(void *)0

static void (* STK_CallBack)(void) = NULL;


static u8	STK_u8IntervalMode;

#endif