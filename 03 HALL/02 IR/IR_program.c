/************************************************************/
/* 			AUTHOR      : Mohamed MeGa	                  	*/
/* 			DISCRIPTION : IR DRIVER                     	*/
/* 			DATE        : 21 DEC 2021                       */
/* 			VERSION     : V01                               */
/************************************************************/
volatile u8	u8StartFlag 			= 0;
volatile u8	u8EdgeCounter 			= 0;
volatile u32	u32FrameData[50]	= {0};



void	IR_VoidInit(void)
{
	GPIO_VoidSetPinDirection(LEDMRX_ROW0_PIN, OUTPUT_2MHZ_PP);
}


void	IR_VoidGetFrame(void)
{
	if(u8StartFlag == 0)
	{
		STK_voidSetIntervalSingle(1000000, IR_VoidTakeAction);
		u8StartFlag = 1;
	}
	else
	{
		u32FrameData[u8EdgeCounter] = STK_u32GetElapsedTime;
		STK_voidSetIntervalSingle(1000000, IR_VoidTakeAction);
		u8EdgeCounter++;
	}
	
}



void IR_VoidTakeAction(void)
{
	u8 i 	= 0;
	u8Data 	= 0;
	
	if( (u32FrameData[0] < 10000) && (u32FrameData[0] > 140000) )
	{
	
		for(i=0; i < 8; i++)
		{
			if( (u32FrameData[17 + i] < 2000) && (u32FrameData[17 + i] > 2400) )
			{
				SET_BIT(u8Data, i);
			}
			else
			{
				CLEAR_BIT(u8Data, i);
			}
		}
	}
	
	u8StartFlag 		= 0;
	u8EdgeCounter 		= 0;
	u32FrameData[0]		= 0;
}