#include "keypad.h"

void keypad_init (void){
        TRISB = 0xF0;
        PORTB = 0xFF;
        // open internal pull-up resistor on PORTB
        CLEAR_BIT(OPTION_REG,7);
}
/**
 *  @return : this function returns the character co-responding to the key entered
 *  @note: if nothing is entered should return 0
*/
unsigned char keypad_get_key(void){
     //### First ROW ###
     PORTB = 0xFF;  //initial state of the port
     CLEAR_BIT(PORTB,0) ; //turn first row on
     //delay_ms(300);   //-for testing
     //check the inputs
     if (GET_BIT_STATUS(PORTB,4) == 0 ){
        while(GET_BIT_STATUS(PORTB,4) == 0);
        return '7' ;
     }else if (GET_BIT_STATUS(PORTB,5) == 0){
         while(GET_BIT_STATUS(PORTB,5) == 0);
         return '8' ;
     }else if (GET_BIT_STATUS(PORTB,6) == 0){
         while(GET_BIT_STATUS(PORTB,6) == 0);
         return '9' ;
     }else if (GET_BIT_STATUS(PORTB,7) == 0){
         while(GET_BIT_STATUS(PORTB,7) == 0);
         return '/' ;
     }
     //### Second ROW ###
     PORTB = 0xFF;  //initial state of the port
     CLEAR_BIT(PORTB,1) ; //turn first row on

     //delay_ms(300);   //-for testing
     if (GET_BIT_STATUS(PORTB,4) == 0 ){
        while(GET_BIT_STATUS(PORTB,4) == 0);
        return '4' ;
     }else if (GET_BIT_STATUS(PORTB,5) == 0){
         while(GET_BIT_STATUS(PORTB,5) == 0);
         return '5' ;
     }else if (GET_BIT_STATUS(PORTB,6) == 0){
         while(GET_BIT_STATUS(PORTB,6) == 0);
         return '6' ;
     }else if (GET_BIT_STATUS(PORTB,7) == 0){
         while(GET_BIT_STATUS(PORTB,7) == 0);
         return '*' ;
     }
     //### Third ROW ###
     PORTB = 0xFF;  //initial state of the port
     CLEAR_BIT(PORTB,2) ; //turn first row on
     //delay_ms(300);   //-for testing
     
      if (GET_BIT_STATUS(PORTB,4) == 0 ){
        while(GET_BIT_STATUS(PORTB,4) == 0);
        return '1' ;
     }else if (GET_BIT_STATUS(PORTB,5) == 0){
         while(GET_BIT_STATUS(PORTB,5) == 0);
         return '2' ;
     }else if (GET_BIT_STATUS(PORTB,6) == 0){
         while(GET_BIT_STATUS(PORTB,6) == 0);
         return '3' ;
     }else if (GET_BIT_STATUS(PORTB,7) == 0){
         while(GET_BIT_STATUS(PORTB,7) == 0);
         return '-' ;
     }
     //### Fourth ROW ###
     PORTB = 0xFF;  //initial state of the port
     CLEAR_BIT(PORTB,3) ; //turn first row on

     //delay_ms(300);   //-for testing
     if (GET_BIT_STATUS(PORTB,4) == 0 ){
        while(GET_BIT_STATUS(PORTB,4) == 0);
        return 'c' ;
     }else if (GET_BIT_STATUS(PORTB,5) == 0){
         while(GET_BIT_STATUS(PORTB,5) == 0);
         return '0' ;
     }else if (GET_BIT_STATUS(PORTB,6) == 0){
         while(GET_BIT_STATUS(PORTB,6) == 0);
         return '=' ;
     }else if (GET_BIT_STATUS(PORTB,7) == 0){
         while(GET_BIT_STATUS(PORTB,7) == 0);
         return '+' ;
     }
     return '\0' ;
}
