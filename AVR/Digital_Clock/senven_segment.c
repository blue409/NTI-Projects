
#include "seven_segment.h"



void SevenSegmentCommonAnode_Init(void)
{
	  DIO_setupPinDirection(PORTB_ID ,PIN0_ID , PIN_OUTPUT);
	  DIO_setupPinDirection(PORTB_ID ,PIN1_ID , PIN_OUTPUT);
 	  DIO_setupPinDirection(PORTB_ID ,PIN2_ID , PIN_OUTPUT);
      DIO_setupPinDirection(PORTB_ID ,PIN4_ID , PIN_OUTPUT);

	  DIO_setupPinDirection(PORTB_ID ,PIN5_ID , PIN_OUTPUT);
	  DIO_setupPinDirection(PORTB_ID ,PIN6_ID , PIN_OUTPUT);
 	  DIO_setupPinDirection(PORTA_ID ,PIN2_ID , PIN_OUTPUT);
 	  DIO_setupPinDirection(PORTA_ID ,PIN3_ID , PIN_OUTPUT);
}
void SevenSegmentCommonAnode(uint8 num,uint8 EN)
{

      switch(EN)
      {
      case 1:
      	 DIO_writePin(PORTB_ID,PIN5_ID , 1);
      	 DIO_writePin(PORTB_ID,PIN6_ID , 0);
      	 DIO_writePin(PORTA_ID,PIN2_ID , 1);
      	 DIO_writePin(PORTA_ID,PIN3_ID , 1);
      	 break;
      case 2:
       	 DIO_writePin(PORTB_ID,PIN5_ID , 0);
       	 DIO_writePin(PORTB_ID,PIN6_ID , 1);
       	 DIO_writePin(PORTA_ID,PIN2_ID , 1);
       	 DIO_writePin(PORTA_ID,PIN3_ID , 1);
       	 break;
      case 3:
       	 DIO_writePin(PORTB_ID,PIN5_ID , 1);
       	 DIO_writePin(PORTB_ID,PIN6_ID , 1);
       	 DIO_writePin(PORTA_ID,PIN2_ID , 0);
       	 DIO_writePin(PORTA_ID,PIN3_ID , 1);
       	 break;
      case 4:
       	 DIO_writePin(PORTB_ID,PIN5_ID , 1);
       	 DIO_writePin(PORTB_ID,PIN6_ID , 1);
       	 DIO_writePin(PORTA_ID,PIN2_ID , 1);
       	 DIO_writePin(PORTA_ID,PIN3_ID , 0);
       	 break;
      case 5:/*switching off the 7 segment*/
        	 DIO_writePin(PORTB_ID,PIN5_ID , 1);
        	 DIO_writePin(PORTB_ID,PIN6_ID , 1);
        	 DIO_writePin(PORTA_ID,PIN2_ID , 1);
        	 DIO_writePin(PORTA_ID,PIN3_ID , 1);
        	 break;
      }
      switch(num)
      {
      case 0:
     	 DIO_writePin(PORTB_ID,PIN0_ID , 0);
     	 DIO_writePin(PORTB_ID,PIN1_ID , 0);
     	 DIO_writePin(PORTB_ID,PIN2_ID , 0);
     	 DIO_writePin(PORTB_ID,PIN4_ID , 0);
         break;
      case 1:
     	 DIO_writePin(PORTB_ID,PIN0_ID , 1);
     	 DIO_writePin(PORTB_ID,PIN1_ID , 0);
     	 DIO_writePin(PORTB_ID,PIN2_ID , 0);
     	 DIO_writePin(PORTB_ID,PIN4_ID , 0);
         break;
      case 2:
     	 DIO_writePin(PORTB_ID,PIN0_ID , 0);
     	 DIO_writePin(PORTB_ID,PIN1_ID , 1);
     	 DIO_writePin(PORTB_ID,PIN2_ID , 0);
     	 DIO_writePin(PORTB_ID,PIN4_ID , 0);
         break;
      case 3:
     	 DIO_writePin(PORTB_ID,PIN0_ID , 1);
     	 DIO_writePin(PORTB_ID,PIN1_ID , 1);
     	 DIO_writePin(PORTB_ID,PIN2_ID , 0);
     	 DIO_writePin(PORTB_ID,PIN4_ID , 0);
         break;
      case 4:
     	 DIO_writePin(PORTB_ID,PIN0_ID , 0);
     	 DIO_writePin(PORTB_ID,PIN1_ID , 0);
     	 DIO_writePin(PORTB_ID,PIN2_ID , 1);
     	 DIO_writePin(PORTB_ID,PIN4_ID , 0);
         break;
      case 5:
     	 DIO_writePin(PORTB_ID,PIN0_ID , 1);
     	 DIO_writePin(PORTB_ID,PIN1_ID , 0);
     	 DIO_writePin(PORTB_ID,PIN2_ID , 1);
     	 DIO_writePin(PORTB_ID,PIN4_ID , 0);
         break;
      case 6:
     	 DIO_writePin(PORTB_ID,PIN0_ID , 0);
     	 DIO_writePin(PORTB_ID,PIN1_ID , 1);
     	 DIO_writePin(PORTB_ID,PIN2_ID , 1);
     	 DIO_writePin(PORTB_ID,PIN4_ID , 0);
         break;
      case 7:
     	 DIO_writePin(PORTB_ID,PIN0_ID , 1);
     	 DIO_writePin(PORTB_ID,PIN1_ID , 1);
     	 DIO_writePin(PORTB_ID,PIN2_ID , 1);
     	 DIO_writePin(PORTB_ID,PIN4_ID , 0);
         break;
      case 8:
     	 DIO_writePin(PORTB_ID,PIN0_ID , 0);
     	 DIO_writePin(PORTB_ID,PIN1_ID , 0);
     	 DIO_writePin(PORTB_ID,PIN2_ID , 0);
     	 DIO_writePin(PORTB_ID,PIN4_ID , 1);
         break;
      case 9:
     	 DIO_writePin(PORTB_ID,PIN0_ID , 1);
     	 DIO_writePin(PORTB_ID,PIN1_ID , 0);
     	 DIO_writePin(PORTB_ID,PIN2_ID , 0);
     	 DIO_writePin(PORTB_ID,PIN4_ID , 1);
         break;

      }
}
