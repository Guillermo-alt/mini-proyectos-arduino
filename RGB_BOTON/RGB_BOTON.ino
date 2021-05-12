
const int BOTON=2;
const int BOTON2=3;

#define pinLed1 11   // Pin 11 a R
#define pinLed2 10  // Pin 10 a G
#define pinLed3 9  // Pin 10 a B
int val=0;
int it=0;
int intensidad=1;

void setup() {
  pinMode(pinLed1, OUTPUT);
  pinMode(pinLed2, OUTPUT);
  pinMode(pinLed3, OUTPUT);
  pinMode(BOTON,INPUT);
  Serial.begin(9600);
}

void loop() {

if(digitalRead(BOTON)==HIGH){
  delay(500);
   it++; 
}
if(digitalRead(BOTON2)==HIGH){
  delay(400);
   intensidad+=50; 
   Serial.print(intensidad);
}
if(intensidad>255 ){
  intensidad=1;
 }

  switch (it) {
  case 0: // Azul
    digitalWrite(pinLed1, LOW);
    analogWrite(pinLed2, intensidad);
    digitalWrite(pinLed3, LOW);
    break;
  case 1: // Rojo
    digitalWrite(pinLed1, LOW);
    digitalWrite(pinLed2, LOW);
    analogWrite(pinLed3, intensidad);
    break;
  case 2:// Verde
    analogWrite(pinLed1, intensidad);
    digitalWrite(pinLed2, LOW);
    digitalWrite(pinLed3, LOW);
    break;
  case 3: //Violeta
    analogWrite(pinLed1, intensidad);
    digitalWrite(pinLed2, LOW);
    analogWrite(pinLed3, intensidad);
    break;
  case 4: //Amarillo
     analogWrite(pinLed1, intensidad);
    analogWrite(pinLed2, intensidad);
    digitalWrite(pinLed3, LOW);
    break;
  case 5://Azul Marino 
    digitalWrite(pinLed1, LOW);
    analogWrite(pinLed2, intensidad);
    analogWrite(pinLed3, intensidad);
    break;
  case 6://Blanco 
    analogWrite(pinLed1, intensidad);
    analogWrite(pinLed2, intensidad);
    analogWrite(pinLed3, intensidad);
    break;
  case 7://Blanco 
    it=0;
    break;
  default:
    // statements
  break;
}
 
}
