/******************************************************************/
/*             >>DATE:2/1/2021                                    */
/*             >>AUTHOR:ELSAYED MANSOUR SHALABY                   */
/*             >>VERSION:0.1                                      */
/******************************************************************/
#include"STD_TYPES.h"
#include"BIT_MATH.h"

#include"EXTI_INT.h"
#include"EXTI_Priv.h"
#include"EXTI_Config.h"



void (* EXTI0_CallBack) (void) =NULL;
void (* EXTI1_CallBack) (void) =NULL;
void (* EXTI8_CallBack) (void) =NULL;
/*************************/
void MEXTI0_SetCollBack(void (*LocPFunc) (void))
{
	EXTI0_CallBack=LocPFunc;
}
/*************************/
void MEXTI1_SetCollBack(void (*LocPFunc) (void))
{
	EXTI1_CallBack=LocPFunc;
}
/*************************/
void MEXTI8_SetCollBack(void (*LocPFunc) (void))
{
	EXTI8_CallBack=LocPFunc;
}
void MEXTI_VidSetSignalLatch(u8 Copy_u8LineID	,u8 Copy_u8SenseMode)
{
	switch(Copy_u8SenseMode)
	{
	case EXTI_FALLING:	SET_BIT(EXTI->FTSR,Copy_u8LineID);
						CLR_BIT(EXTI->RTSR,Copy_u8LineID);break;
	case EXTI_RISING :  SET_BIT(EXTI->RTSR,Copy_u8LineID);
						CLR_BIT(EXTI->FTSR,Copy_u8LineID);break;
	case EXTI_IOC    :	SET_BIT(EXTI->FTSR,Copy_u8LineID);
						SET_BIT(EXTI->RTSR,Copy_u8LineID);break;
	
	}
	CLR_BIT(EXTI->IMR,Copy_u8LineID);
}
void MEXTI_VidEnable	(u8 Copy_u8LineID)
{
	SET_BIT(EXTI->IMR,Copy_u8LineID);
}
void MEXTI_VidDisable	(u8 Copy_u8LineID)
{
	CLR_BIT(EXTI->IMR,Copy_u8LineID);
}
void MEXTI_VidSetSoftwareTrigger(u8 Copy_u8LineID)
{
	SET_BIT(EXTI->SWIER,Copy_u8LineID);
}
void EXTI0_IRQHandler(void)
{
	
	if(EXTI0_CallBack!=NULL)
	{
		EXTI0_CallBack();
		/*TO CLEAR FLAG IN LINE 0*/
		SET_BIT(EXTI->PR,EXTI_Line0);
	}
}
void EXTI1_IRQHandler(void)
{
	
	if(EXTI1_CallBack!=NULL)
	{
		EXTI1_CallBack();
		/*TO CLEAR FLAG IN LINE 1*/
		SET_BIT(EXTI->PR,EXTI_Line1);
	}	
}
void EXTI9_5_IRQHandler(void)
{

	if(EXTI8_CallBack!=NULL)
	{
		EXTI8_CallBack();
		/*TO CLEAR FLAG IN LINE 8*/
		SET_BIT(EXTI->PR,EXTI_Line8);
	}
}
