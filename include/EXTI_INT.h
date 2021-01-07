#ifndef _EX_INT_INTERFACE_H_
#define _EX_INT_INTERFACE_H_
//sense mode
#define	EXTI_FALLING	0
#define	EXTI_RISING	1
#define	EXTI_IOC		2
//lines
typedef enum
{
	EXTI_Line0 ,
	EXTI_Line1 ,
	EXTI_Line2 ,
	EXTI_Line3,
	EXTI_Line4 ,
	EXTI_Line5 ,
	EXTI_Line6 ,
	EXTI_Line7 ,
	EXTI_Line8 ,
	EXTI_Line9 ,
	EXTI_Line10,
	EXTI_Line11,
	EXTI_Line12,
	EXTI_Line13,
	EXTI_Line14,
	EXTI_Line15

}EXTI_Line;

void MEXTI_VidSetSignalLatch	  (u8 Copy_u8LineID,u8 Copy_u8SenseMode);
void MEXTI_VidEnable	  (u8 Copy_u8LineID);
void MEXTI_VidDisable	  (u8 Copy_u8LineID);
void MEXTI_VidSetSoftwareTrigger(u8 Copy_u8LineID);

void MEXTI0_SetCollBack(void (*LocPFunc) (void));
void MEXTI1_SetCollBack(void (*LocPFunc) (void));
void MEXTI8_SetCollBack(void (*LocPFunc) (void));






#endif
