//Guillermo Ortega Vargas
const int led3 =  13;// constantes para los pines leds
const int led2 =  12;
const int led1 =  11;

const int boton1 =  1;// constantes para los pines botones
const int boton2 =  2;
const int boton3 =  3;

int led1State = LOW;       //estados para cada led
int led2State = LOW; 
int led3State = LOW; 

unsigned long tiempo1 = 0; // variable para guardar actualizacion de milisegundos
unsigned long tiempo2 = 0;
unsigned long tiempo3 = 0;

unsigned long tiempo4 = 0;//tiempo para show de leds
unsigned long tiempo5 = 0;//tiempo para show cuando gana

long inter1 = 500; 
long inter2 = 800; // intervalo para el parpadeo de leds
long inter3 = 600; 


void setup() {
  Serial.begin(9600); //sirve para imprimir, se puede quitar, no afecta el funcionamiento
  pinMode(led1, OUTPUT);//inicializa pines leds
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  
  pinMode(boton1,INPUT); //inicializa pines botones
  pinMode(boton2,INPUT);
  pinMode(boton3,INPUT);


}

void loop() {
  show(); //show de parpadeo
  validaBot(); //valida botones

}


void validaBot(){
  //lee los pines de los botones y los guarda en variables
  int stbot1=digitalRead(boton1);
  int stbot2=digitalRead(boton2);
  int stbot3=digitalRead(boton3);
 
  //si es precionado el botón y el estado de led quedo encendido entonces gana, si no si es precionado el botón y el estado de led quedo apado pierde
  if(stbot1==HIGH && led1State==HIGH ){ gana();}else if(stbot1==HIGH && led1State==LOW ){pierde(led1);}
  if(stbot2==HIGH && led2State==HIGH ){ gana();}else if(stbot2==HIGH && led2State==LOW ){pierde(led2);}
  if(stbot3==HIGH && led3State==HIGH ){ gana();}else if(stbot3==HIGH && led3State==LOW ){pierde(led3);}
}
//prende led por 2 segundos
void pierde(int led){
 digitalWrite(led, HIGH);
  delay(2000);
}
//apaga todos los led sin modificar estados
void apagaLeds(){ //apaga todos los led
  digitalWrite(led3, LOW);
  digitalWrite(led2, LOW);
  digitalWrite(led1, LOW); 
}


void gana(){
tiempo5=millis();//actualiza tiempo5 para la duracion de la funci[on ganar
led1State=LOW;//cambia los estados para que parpadeen al mismo tiempo
led2State=LOW;
led3State=LOW;
 while(millis()- tiempo5 <= 4000){//parpadean durante 4s
  if(millis() - tiempo1 >= 200){//intervalo de parpadeo de leds
       tiempo1 = millis(); //actualiza intervalo de parpadeo
       led1State= parpadea(led1State,led1);
       led2State= parpadea(led2State,led2);
       led3State= parpadea(led3State,led3);
 
  }   
 }tiempo4=millis(); //actualiza tiempo4 para volver a jugar
 subeNivel();//aumenta nivel para una mayor velocidad de parpadeos
}


void show(){
 while(millis()- tiempo4 <= 5500){//el show de led dura 5.5 segundos
  
  if(millis() - tiempo1 >= inter1){//cada lede tiene su propio intervalo y tiempo actual
        tiempo1 = millis();
       led1State= parpadea(led1State,led1);// fucni[n para prender o apagar led, depende el estado, y actualiza el estado
    }
     if(millis() - tiempo2 >= inter2){
        tiempo2 = millis();
        led2State=parpadea(led2State,led2);
    }
      if(millis() - tiempo3 >= inter3){
        tiempo3 = millis();
       led3State= parpadea(led3State,led3);
 }
 }
 if(led1State==HIGH && led2State==HIGH && led3State==HIGH ){tiempo4=millis();}//si todos los led se quedan ENCEDIDOS, vuelve a revolver leds
 if(led1State==LOW && led2State==LOW && led3State==LOW ){tiempo4=millis();}//si todos los led se quedan apagados, vuelve a revolver leds
 
 apagaLeds();// despues de 5.5 segundos apaga los led. termina show, se puede quitar, no afecta el funcionamiento.
 }

int subeNivel(){// disminuye el intervalo, mayor velocidad, solo si Están  por arriba de 200 milisegundos, de lo contrario iria muy rapido
if(inter1>200) {inter1 -=125;}
if(inter2>200) {inter2 -=120; }// intervalo de parpadeo diferente para cada led
if(inter3>200){inter3 -=115;} 

  }

int parpadea(int ledState,int ledPin){//cambia el estado del led, encedio o apagado
  if (ledState == LOW) {
      ledState = HIGH;
    } else {
      ledState = LOW;
    }
    digitalWrite(ledPin, ledState);//enciende o apaga el led.
    return ledState;// retorna el estado actual de led
  }
