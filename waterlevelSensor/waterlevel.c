#include <wiringPi.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
  int WA = 7;
  int RL1 = 26;
  wiringPiSetup () ;
 
  pinMode (WA, INPUT) ;
  pinMode (RL1, OUTPUT) ;
  
  FILE *fp;
 
  for(;;)
  {
    if(digitalRead(WA))
     {
       digitalWrite(RL1 , HIGH);
       fp = fopen("waterstatus.txt","w+");
       fputs("WATER LEVEL ============================================= NORMAL\n",fp);
       fclose(fp);
       delay(10);
     }
     
     else
     {
       digitalWrite(RL1 , LOW);
       fp = fopen("waterstatus.txt","w+");
       fputs("WATER LEVEL =============================================== LOW\n",fp);
       fputs("MAIN MOTOR  ===============================================  ON\n",fp);
       fclose(fp);
       for(;;)
       {delay(1000);
        if(digitalRead(WA))
        {break;}
       }
       
       
     }
    
   }


}
