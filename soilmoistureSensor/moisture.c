#include <wiringPi.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
  int MO = 0;
  int RL2 = 27;
  wiringPiSetup () ;
 
  pinMode (MO, INPUT) ;
  pinMode (RL2, OUTPUT) ;
  
  FILE *fp;
 
  for(;;)
  {
    if(digitalRead(MO))
     {
       digitalWrite(RL2 , LOW);
       fp = fopen("moisturestatus.txt","w+");
       fputs("MOISTURE LEVEL =============================================== LOW\n",fp);
       fputs("IRRIGATION  ==================================================  ON\n",fp);
       fclose(fp);
       delay(10);
     }
     
     else
     {
       digitalWrite(RL2 , HIGH);
       fp = fopen("moisturestatus.txt","w+");
       fputs("MOISTURE LEVEL ============================================= GOOD\n",fp);
       fclose(fp);
       delay(10);
     }
    
   }


}
