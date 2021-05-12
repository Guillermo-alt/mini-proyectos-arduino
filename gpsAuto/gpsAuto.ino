
#include <SoftwareSerial.h>
#include <TinyGPS.h>

#define GPS_TX_PIN 6
#define GPS_RX_PIN 3

struct GeoLoc {
  float lat;
  float lon;
};

SoftwareSerial nss(GPS_TX_PIN, GPS_RX_PIN);  
TinyGPS gps;

void setup() {
  // put your setup code here, to run once:
 Serial.begin(4800); //cambiar a 4500
  nss.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
 GeoLoc coolerLoc = checkGPS();
}

GeoLoc checkGPS() {
  Serial.println("Reading onboard GPS: ");
  bool newdata = false;
  unsigned long start = millis();
  while (millis() - start < 1000) {
    if (feedgps())
      newdata = true;
  }
  if (newdata) {
    return gpsdump(gps);
  }

  GeoLoc coolerLoc;
  coolerLoc.lat = 0.0;
  coolerLoc.lon = 0.0;
  
  return coolerLoc;
}

// Get and process GPS data
GeoLoc gpsdump(TinyGPS &gps) {
  float flat, flon;
  unsigned long age;
  
  gps.f_get_position(&flat, &flon, &age);

  GeoLoc coolerLoc;
  coolerLoc.lat = flat;
  coolerLoc.lon = flon;

  Serial.print(coolerLoc.lat, 7); Serial.print(", "); Serial.println(coolerLoc.lon, 7);

  return coolerLoc;
}

// Feed data as it becomes available 
bool feedgps() {
  while (nss.available()) {
    if (gps.encode(nss.read()))
      return true;
  }
  return false;
}
