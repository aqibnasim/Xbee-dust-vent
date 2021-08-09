#include<string.h>
byte buff[2];
int pin = 8;//DSM501A input D8
unsigned long duration;
unsigned long starttime;
unsigned long endtime;
unsigned long sampletime_ms = 2000;
unsigned long lowpulseoccupancy = 0;
float ratio = 0;
float concentration = 0;

void setup()
{
  Serial.begin(9600);
  pinMode(pin,INPUT);
  starttime = millis(); 
}
void loop()
{
 
 duration = pulseIn(pin, LOW);
  lowpulseoccupancy += duration;
  endtime = millis();
  if ((endtime-starttime) > sampletime_ms)
  {
  ratio = lowpulseoccupancy/(sampletime_ms*10.0); 
  
  //Serial.print("Ratio = ");
  
   Serial.write((int)ratio);
   //Serial.println(ratio);

   //concentration = 1.1*pow(ratio,3)-3.8*pow(ratio,2)+520*ratio+0.62;
   //Serial.print("Concentration = ");
   //Serial.print(concentration);
   //Serial.println(" pcs/0.01cf");
   
   lowpulseoccupancy = 0;
   
   starttime = millis();
   delay(500);
   
  }
}
