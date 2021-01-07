#ifndef _EX_INT_PRIVATE_H_
#define _EX_INT_PRIVATE_H_
typedef struct
{
	volatile u32 IMR;
	volatile u32 EMR;	
	volatile u32 RTSR;	
	volatile u32 FTSR;	
	volatile u32 SWIER;	
	volatile u32 PR;	
}EXIT_Type;

#define EXTI	((volatile EXIT_Type *)0x40010400)








#endif
