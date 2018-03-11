/*------------------------------------------------------------------------------

  LIDARLite Arduino Library
  GetDistancePwm

  This example shows how to read distance from a LIDAR-Lite connected over the
  PWM interface.

  Connections:
  LIDAR-Lite 5 Vdc (red) to Arduino 5v
  LIDAR-Lite Ground (black) to Arduino GND
  LIDAR-Lite Mode control (yellow) to Arduino digital input (pin 3)
  LIDAR-Lite Mode control (yellow) to 1 kOhm resistor lead 1
  1 kOhm resistor lead 2 to Arduino digital output (pin 2)

  (Capacitor recommended to mitigate inrush current when device is enabled)
  680uF capacitor (+) to Arduino 5v
  680uF capacitor (-) to Arduino GND

  See the Operation Manual for wiring diagrams and more information:
  http://static.garmin.com/pumac/LIDAR_Lite_v3_Operation_Manual_and_Technical_Specifications.pdf

  ------------------------------------------------------------------------------*/

unsigned long pulseWidth;
double count = 0;
boolean light = false;

int led = 2;
int trigger = 1;
int monitorPin = 0;

void setup()
{
  //Serial.begin(115200); // Start serial communications

  pinMode(trigger, OUTPUT); // Set pin 2 as trigger pin
  digitalWrite(trigger, LOW); // Set trigger LOW for continuous read

  pinMode(monitorPin, INPUT); // Set pin 3 as monitor pin

  pinMode(led,OUTPUT);
  
}

void loop()
{
  
  count += 1;
  pulseWidth = pulseIn(monitorPin, HIGH); // Count how long the pulse is high in microseconds

  // If we get a reading that isn't zero, let's print it
    if(pulseWidth > 1) pulseWidth = pulseWidth / 100; // 10usec = 1 cm of distance
    //Serial.println(pulseWidth); // Print the distance
    //pulseWidth += 400;

    pulseWidth += 10;
    if (pulseWidth < 60) pulseWidth = 10;

    if(count >= pulseWidth){
     count = 0;
     if(light){
        digitalWrite(led,HIGH);
     }else digitalWrite(led,LOW);
     light = !light;
     
  }

  
}
