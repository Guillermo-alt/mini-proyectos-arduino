//Guillermo Ortega Vargas
//Medidor analógico con leds y potenciometro

int valo_pot = 0; //varaible para almacenar datos de la potenciometro 
 
int led1 = 1; //Pines para leds
int led2 = 2; 
int led3 = 3; 
int led4 = 4; 
int led5 = 5;

int pin_pot = A1; //pin analógico para la potenciometro

void setup() { 
pinMode(led1, OUTPUT); //Configuramos los pines de  salida para cada led
pinMode(led2, OUTPUT); 
pinMode(led3, OUTPUT); 
pinMode(led4, OUTPUT); 
pinMode(led5, OUTPUT);
}

void loop() { 

valo_pot = analogRead(pin_pot); //leemos el valor de la potenciometro

if(valo_pot > 1000) { //Condiciones para intervalos de los datos obtenidos por la fotoresistencia
digitalWrite(led1, HIGH); 
digitalWrite(led2, HIGH); 
digitalWrite(led3, HIGH); 
digitalWrite(led4, HIGH); 
digitalWrite(led5, HIGH); }

if((valo_pot >= 800) & (valo_pot < 1000)) { 
digitalWrite(led1, HIGH); 
digitalWrite(led2, HIGH); 
digitalWrite(led3, HIGH); 
digitalWrite(led4, HIGH); 
digitalWrite(led5, LOW); }

if((valo_pot >= 600) & (valo_pot < 800)) {
digitalWrite(led1, HIGH); 
digitalWrite(led2, HIGH); 
digitalWrite(led3, HIGH); 
digitalWrite(led4, LOW); 
digitalWrite(led5, LOW); }

if((valo_pot >= 400) & (valo_pot < 600)) { 
digitalWrite(led1, HIGH); 
digitalWrite(led2, HIGH); 
digitalWrite(led3, LOW); 
digitalWrite(led4, LOW); 
digitalWrite(led5, LOW); }

if((valo_pot >= 250) & (valo_pot < 500)) { 
digitalWrite(led1, HIGH); 
digitalWrite(led2, LOW); 
digitalWrite(led3, LOW); 
digitalWrite(led4, LOW); 
digitalWrite(led5, LOW); }

if(valo_pot <100) { 
digitalWrite(led1, LOW); 
digitalWrite(led2, LOW); 
digitalWrite(led3, LOW); 
digitalWrite(led4, LOW); 
digitalWrite(led5, LOW); }

}
