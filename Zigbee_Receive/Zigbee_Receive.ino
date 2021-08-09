#include<string.h>
byte buff[2];
int pin = 8;//DSM501A input D8
int ratio = 0;
float concentration = 0;

void setup()
{
  Serial.begin(9600);
}
void loop()
{
   while (!Serial.available()){}
   
   ratio = Serial.read();
   Serial.print("Ratio = ");
   Serial.println(ratio);
  
   concentration = 1.1*pow(ratio,3)-3.8*pow(ratio,2)+520*ratio+0.62;
   Serial.print("Concentration = ");
   Serial.print(concentration);
   Serial.println(" pcs/0.01cf");
   delay(10); //allows all serial sent to be received together
}
