
#include "seven_segment.h"

void SevenSegmentCommonAnode_INIT(void)
{
	SET_BIT(DDRB, 0);
	SET_BIT(DDRB, 1);
	SET_BIT(DDRB, 2);
	SET_BIT(DDRB, 4);

	SET_BIT(DDRB, 5);
	SET_BIT(DDRB, 6);
	SET_BIT(DDRA, 2);
	SET_BIT(DDRA, 3);
}

void SevenSegmentCommonAnode(u8 num,u8 EN)
{	
      switch(EN)
      {
      case 1:
		 SET_BIT(PORTB, 5);
		 CLR_BIT(PORTB, 6);
		 SET_BIT(PORTA, 2);
		 SET_BIT(PORTA, 3);
      	 
		 break;
      case 2:
       	 CLR_BIT(PORTB, 5);
		 SET_BIT(PORTB, 6);
		 SET_BIT(PORTA, 2);
		 SET_BIT(PORTA, 3);
       	 break;
      case 3:
       	 SET_BIT(PORTB, 5);
       	 SET_BIT(PORTB, 6);
       	 CLR_BIT(PORTA, 2);
       	 SET_BIT(PORTA, 3);
		break;
      case 4:
       	 SET_BIT(PORTB, 5);
		 SET_BIT(PORTB, 6);
		 SET_BIT(PORTA, 2);
		 CLR_BIT(PORTA, 3);
       	 break;
      case 5:
        SET_BIT(PORTB, 5);
   	    SET_BIT(PORTB, 6);
  	    SET_BIT(PORTA, 2);
		SET_BIT(PORTA, 3);
      	break;
      }
      switch(num)
      {
      case 0:
     	 CLR_BIT(PORTB, 0);
		 CLR_BIT(PORTB, 1);
		 CLR_BIT(PORTB, 2);
		 CLR_BIT(PORTB, 4);
		 
         break;
      case 1:
     	 SET_BIT(PORTB, 0);
		 CLR_BIT(PORTB, 1);
		 CLR_BIT(PORTB, 2);
		 CLR_BIT(PORTB, 4);
         break;
      case 2:
     	 CLR_BIT(PORTB, 0);
		 SET_BIT(PORTB, 1);
		 CLR_BIT(PORTB, 2);
		 CLR_BIT(PORTB, 4);
         break;
      case 3:
     	 SET_BIT(PORTB, 0);
		 SET_BIT(PORTB, 1);
		 CLR_BIT(PORTB, 2);
		 CLR_BIT(PORTB, 4);
         break;
      case 4:
     	 CLR_BIT(PORTB, 0);
         CLR_BIT(PORTB, 1);
         SET_BIT(PORTB, 2);
         CLR_BIT(PORTB, 4);
		 break;
      case 5:
     	 SET_BIT(PORTB, 0);
		 CLR_BIT(PORTB, 1);
		 SET_BIT(PORTB, 2);
		 CLR_BIT(PORTB, 4);
         break;
      case 6:
     	 CLR_BIT(PORTB, 0);
		 SET_BIT(PORTB, 1);
		 SET_BIT(PORTB, 2);
		 CLR_BIT(PORTB, 4);
         break;
      case 7:
     	 SET_BIT(PORTB, 0);
		 SET_BIT(PORTB, 1);
		 SET_BIT(PORTB, 2);
		 CLR_BIT
		 (PORTB, 4);
         break;
      case 8:
     	 CLR_BIT(PORTB, 0);
		 CLR_BIT(PORTB, 1);
		 CLR_BIT(PORTB, 2);
		 SET_BIT(PORTB, 4);
         break;
      case 9:
     	 SET_BIT(PORTB, 0);
		 CLR_BIT(PORTB, 1);
		 CLR_BIT(PORTB, 2);
		 SET_BIT(PORTB, 4);
         break;

      }
}
void set_int0(void)
{
	SET_BIT(DDRD, 2);
	SET_BIT(MCUCR, ISC00);
	SET_BIT(GICR, INT0);
	//sei();

}
void set_int1(void)
{
	SET_BIT(DDRD, 4);
	SET_BIT(MCUCR,  ISC10);
	SET_BIT(GICR, INT1);
	//sei();

}
