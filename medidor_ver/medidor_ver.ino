//Guillermo Ortega Vargas
int led13 = 13; //variables para pin de cada led
int led11 = 11;
int led10 = 10;
int led9 = 9;
int led6 = 6;

int inten13;// variables para guardar la intensidad de cada led
int inten11;
int inten10;
int inten9;
int inten6;

int pot = A1;//Variables para pin del potenciómetro  y valor
int val_pot = 0;

void setup() {// inicializa pines de entrada y salida
pinMode(led13, OUTPUT); 
pinMode(led11, OUTPUT); 
pinMode(led10, OUTPUT); 
pinMode(led9, OUTPUT); 
pinMode(led6, OUTPUT); 
pinMode(pot,INPUT);

}

void loop() {
val_pot = analogRead(pot);// lee el valor del potenciómetro  analogo
inten6 =  map (val_pot, 0,204, 0, 255); 
inten9 =  map (val_pot, 204,408, 0, 255); //realiza una escala para los leds a partir los intervalos del potenciometro
inten10 = map (val_pot, 408,612, 0, 255); //1023/5 = 204 intervalo escalado 255
inten11 = map (val_pot, 612,816, 0, 255); 
inten13 = map (val_pot, 816,1023, 0, 255);

    if(val_pot >= 0 && val_pot<204){// para cada intervalo del valor del potenciómetro  prendera el led con su intesidad escalda
      analogWrite(led6,inten6);
     }
     if(val_pot >= 204 && val_pot<408){
      analogWrite(led9,inten9);
      }
     if(val_pot >=408  && val_pot<612){
      analogWrite(led10,inten10);
     }
     if(val_pot >=612  && val_pot<816){
      analogWrite(led11,inten11);
      }
     if(val_pot >=816  && val_pot<1024){
        analogWrite(led13,inten13);
     }
}
