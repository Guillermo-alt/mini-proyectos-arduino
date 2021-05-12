

#include <BlynkSimpleSerialBLE.h>
#include <SoftwareSerial.h>
SoftwareSerial bluetoothSerial(3,2);

char auth[] = "_X_R0f2XbG2yvn4eznzvYezi6sYF6iyF";//token para acceso para blynk


void setup()
{
  // Debug console
  Serial.begin(4800);
  bluetoothSerial.begin(9600);//inicualizo puerto de blue
  Blynk.begin(bluetoothSerial, auth);//inicualizo puerto de blue

  Serial.println("Waiting for connections...");
}

void loop()
{
  Blynk.run();
  // You can inject your own code or combine it with other sketches.
  // Check other examples on how to communicate with Blynk. Remember
  // to avoid delay() function!
}
BLYNK_WRITE(V0) {
 Serial.print("************");
}
