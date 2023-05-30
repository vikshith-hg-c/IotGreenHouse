#include <wiringPi.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
  int GA = 2;
  int RL3 = 28;
  wiringPiSetup () ;
 
  pinMode (GA, INPUT) ;
  pinMode (RL3, OUTPUT) ;
  
  FILE *fp;
 
  for(;;)
  {
    if(digitalRead(GA))
     {
       digitalWrite(RL3 , HIGH);
       fp = fopen("gasstatus.txt","w+");
       fputs("GAS LEVEL ============================================== NORMAL\n",fp);
       fclose(fp);
       delay(10);
     }
     
     else
     {
       digitalWrite(RL3 , LOW);
       fp = fopen("gasstatus.txt","w+");
       fputs("GAS LEVEL(co2)============================================= HIGH\n",fp);
       fputs("VENTILATION   =============================================   ON\n",fp);
       fclose(fp);
       delay(10);
       
     }
    
   }


}
