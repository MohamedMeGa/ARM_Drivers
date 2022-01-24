/************************************************************/
/*   		AUTHOR      : Mohamed	MeGa           		  	*/
/*   		Description : NVIC DRIVER                     	*/
/*   		DATE        : 12 DEC 2021                   	*/
/*   		VERSION     : V01                            	*/
/************************************************************/

#ifndef	NVIC_PRIV_H
#define	NVIC_PRIV_H


/************************************************************/
/**			Register  	DEFINITION							*/
/************************************************************/
#define	NVIC_ISER0		*((u32 	*)0xE000E100)
#define	NVIC_ISER1		*((u32	*)0xE000E104)

#define	NVIC_ICER0		*((u32	*)0xE000E180)
#define	NVIC_ICER1		*((u32	*)0xE000E184)

#define	NVIC_ISPR0		*((u32	*)0xE000E200)
#define	NVIC_ISPR1		*((u32	*)0xE000E204)

#define	NVIC_ICPR0		*((u32	*)0xE000E280)
#define	NVIC_ICPR1		*((u32	*)0xE000E284)

#define	NVIC_IABR0		*((volatile u32	*)0xE000E300)
#define	NVIC_IABR1		*((volatile	u32	*)0xE000E304)
#define	NVIC_IPR		((volatile	u8	*)0xE000E100 + 0x300)
#define	SCB_AIRCR		*((volatile	u32	*)0xE000ED00 + 0x0C)





#endif