#include <Wire.h>
#include <QMC5883L.h>

QMC5883L compass;

void setup()
{
  Wire.begin();
  compass.init();
  compass.setSamplingRate(50);
  Serial.begin(9600);
}

void loop()
{
  int angulo = compass.readHeading();
  if(angulo==0) {
    /* Still calibrating, so measure but don't print */
  } else {
    Serial.println(angulo);
  }

  if((angulo < 22.5) || (angulo > 337.5 )){
   Serial.println("Sur");
 }
 if((angulo > 22.5) && (angulo < 67.5 )){
   Serial.println("Suroeste");
 }
 if((angulo > 67.5) && (angulo < 112.5 )){
   Serial.println("Oeste");
 }
 if((angulo > 112.5) && (angulo < 157.5 )){
   Serial.println("Noroeste");
 }
 if((angulo > 157.5) && (angulo < 202.5 )){
   Serial.println("Norte");
 }
 if((angulo > 202.5) && (angulo < 247.5 )){
   Serial.println("Noreste");
 }
 if((angulo > 247.5) && (angulo < 292.5 )){
   Serial.println("Este");
 }
 if((angulo > 292.5) && (angulo < 337.5 )){
   Serial.println("Sureste");
 }
 delay(100); 
}
