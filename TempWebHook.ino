// This #include statement was automatically added by the Particle IDE.
#include <Adafruit_DHT.h>
#define DHTPIN D2
#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);
int loopCount;

void setup() {
    pinMode(D4, OUTPUT);
    Particle.publish("state", "DHT11 test start");
    dht.begin();
	loopCount = 0;
	delay(2000);
}

void loop() {
    digitalWrite(D7, HIGH);
    
    float t = dht.getTempCelcius();     // Need to read temp as float
    String temp = String(t);            // Convert to string
    
    Particle.publish("temp", temp, PRIVATE);
    delay(30000);
    
    digitalWrite(D7, LOW);
    delay(30000);
    
    loopCount++;
    
	if(loopCount >= 11){
	    Particle.publish("state", "Going to sleep for 5 minutes");
	    delay(1000);
	    System.sleep(SLEEP_MODE_DEEP, 300);
    }
}
