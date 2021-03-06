#include<Arduino.h>
#include<math.h>
#include<stdio.h>

/*################ RCWL-0516 Radar Sensor Interface #############
################ Radio Detection AND Ranging      #############

######################## Doppler Effect #######################

If the target is moving, then there will be a change in the frequency which is hitted the moving object that is transmitted
from the Radar. Then the transmitted signal will compared with the recived signal to check is there will be a difference b/w 2 signals.
This effect is known as the Doppler effect.

According to the Doppler effect, we will get the following two possible cases.

1. The frequency of the received signal will increase, when the target moves towards the direction of the Radar.
2. The frequency of the received signal will decrease, when the target moves away from the Radar.

Here we compare the transmited signal with the recived signal to detect any movements.

################ RCWL-0516 Radar Sensor #############

The sensor will give a digital output (Active High) if a movement detected at a range of nearly 7 meters.

################ Tested with Arduino UNO #############


/*Define Input & Out put pins */

#define ladar_detection 8
#define led 9
#define buzzer 10

int detection = 0;

void setup()
{
  /*Intialising Arduino pins */
  pinMode(ladar_detection, INPUT);

  pinMode(led, OUTPUT);
  pinMode(buzzer, OUTPUT);

  digitalWrite(led, HIGH);
  pinMode(buzzer, HIGH);
  delay(1000);
  digitalWrite(led, LOW);
  pinMode(buzzer, LOW);
}

void loop()
{
  detection = digitalRead(ladar_detection);
  alarm();

}

void alarm()
{
  if (detection)
  {
    digitalWrite(led, HIGH);
  }

  else
  {
    digitalWrite(led, LOW);
  }
}
