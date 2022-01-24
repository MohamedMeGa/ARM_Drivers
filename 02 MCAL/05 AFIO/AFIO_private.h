/************************************************************/
/*   		AUTHOR      : Mohamed	MeGa           		  	*/
/*   		Description : AFIO DRIVER                     	*/
/*   		DATE        : 13 DEC 2021                   	*/
/*   		VERSION     : V01                            	*/
/************************************************************/

#ifndef	AFIO_PRIV_H
#define	AFIO_PRIV_H


/************************************************************/
/**			Register  	DEFINITION							*/
/************************************************************/
typedef	struct{
	volatile	u32	EVCR;
	volatile	u32	MAPR;
	volatile	u32	EXTICR[4];
	volatile	u32	MAPR2;
}AFIO_t;


/**			Base Address									*/
#define	AFIO	((volatile	AFIO_t *)0x40010000)




#endif