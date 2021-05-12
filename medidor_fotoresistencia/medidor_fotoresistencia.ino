//Guillermo Ortega Vargas
//Medidor analógico con leds y fotoresistencia

int valo_fot = 0; //varaible para almacenar datos de la fotoresistencia 
 
int led1 = 1; //Pines para leds
int led2 = 2; 
int led3 = 3; 
int led4 = 4; 
int led5 = 5;

int pin_fot = A0; //pin analógico para la fotoresistencia

void setup() { 
pinMode(led1, OUTPUT); //Configuramos los pines de  salida para cada led
pinMode(led2, OUTPUT); 
pinMode(led3, OUTPUT); 
pinMode(led4, OUTPUT); 
pinMode(led5, OUTPUT);
}

void loop() { 

valo_fot = analogRead(pin_fot); //leemos el valor de la fotoresistencia

if(valo_fot > 950) { //Condiciones para intervalos de los datos obtenidos por la fotoresistencia
digitalWrite(led1, HIGH); 
digitalWrite(led2, HIGH); 
digitalWrite(led3, HIGH); 
digitalWrite(led4, HIGH); 
digitalWrite(led5, HIGH); }

if((valo_fot >= 800) & (valo_fot < 905)) { 
digitalWrite(led1, HIGH); 
digitalWrite(led2, HIGH); 
digitalWrite(led3, HIGH); 
digitalWrite(led4, HIGH); 
digitalWrite(led5, LOW); }

if((valo_fot >= 600) & (valo_fot < 800)) {
digitalWrite(led1, HIGH); 
digitalWrite(led2, HIGH); 
digitalWrite(led3, HIGH); 
digitalWrite(led4, LOW); 
digitalWrite(led5, LOW); }

if((valo_fot >= 400) & (valo_fot < 600)) { 
digitalWrite(led1, HIGH); 
digitalWrite(led2, HIGH); 
digitalWrite(led3, LOW); 
digitalWrite(led4, LOW); 
digitalWrite(led5, LOW); }

if((valo_fot >= 250) & (valo_fot < 500)) { 
digitalWrite(led1, HIGH); 
digitalWrite(led2, LOW); 
digitalWrite(led3, LOW); 
digitalWrite(led4, LOW); 
digitalWrite(led5, LOW); }

if(valo_fot <150) { 
digitalWrite(led1, LOW); 
digitalWrite(led2, LOW); 
digitalWrite(led3, LOW); 
digitalWrite(led4, LOW); 
digitalWrite(led5, LOW); }

}
