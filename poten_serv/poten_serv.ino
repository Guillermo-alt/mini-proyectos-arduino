#include <Servo.h> // Incluimos la biblioteca Servo

Servo servo_1;  // Definimos los servos que vamos a utilizar

int potenciometro_1 = 0;  // Pin usado para conectar el potenciómeto
const int pinBuzzer = 11;
int pos_ser=0;
Servo servoMotor;
int valor_potenciometro_1;    // Esta variable definirá la posición del servo



void setup() {
servo_1.attach(9);  // Difinimos el pines de señal para el servo
servoMotor.attach(12);
 servoMotor.write(50);
 Serial.begin(9600);
}

void loop() {
valor_potenciometro_1 = analogRead(potenciometro_1);
// leemose valor del potenciometro (valor entre 0 y 1023)
valor_potenciometro_1 = map(valor_potenciometro_1, 0, 1023, 0, 180);
// valor proporcional a la escala del servomotor (valor entre 0 y 180)
servo_1.write(valor_potenciometro_1);

Serial.println(pos_ser);

if(HIGH == digitalRead(10)){
  tone(pinBuzzer, 200);
  delay(500);
  //detener tono durante 500ms  
  noTone(pinBuzzer);
  delay(500);


   if (pos_ser == 0) {
      pos_ser = 1;
    } else {
      pos_ser = 0;
    }


  
  if(pos_ser==1){
  // Desplazamos a la posición 180º
  servoMotor.write(180);
  // Esperamos 1 segundo
  delay(500);
  }
  
  if(pos_ser==0){
  servoMotor.write(50);
  // Esperamos 1 segundo
  delay(500);
  }
}
if(HIGH == digitalRead(13)){
  tone(pinBuzzer, 350);
  delay(500);
  //detener tono durante 500ms  
  noTone(pinBuzzer);
  delay(500);
}

delay(10);
// Esperamos para reiniciar el bucle
}
