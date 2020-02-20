#include<ESP8266WiFi.h>
#include<ArduinoFirebase.h>

#define WIFI_SSID "DIE"
#define WIFI_PASS "4EDBC567"
#define FIREBASE_HOST "iot-project1-93a34.firebaseio.com/"
#define FIREBASE_AUTH "BOlUFCQjK6LpQ5fKD7LmI5H1x4K2Ki3CcLTxXNco"

int led = 0;

void setup() {
  Serial.begin(9600);
  pinMode(16, OUTPUT);
  WiFi.begin(WIFI_SSID,WIFI_PASS);
  Serial.print("\nConnecting");
  while(WiFi.status()!=WL_CONNECTED){
    delay(500);
    Serial.print(".");
  }
  Serial.print("\nConnected");
  Serial.print("IP Address : ");
  Serial.print(WiFi.localIP());

  Firebase.begin(FIREBASE_HOST,FIREBASE_AUTH);
  Firebase.setInt("IOT_LED",0);
  delay(500);
}

void loop() {
  if(Firebase.failed()){
    Serial.print("\nConnection Lost!");
    Serial.print(Firebase.error());
    Serial.print("\nConnecting...");
    Firebase.begin(FIREBASE_HOST,FIREBASE_AUTH);
    return;
  }

  led = Firebase.getInt("IOT_LED");
  if(led == 0){
    digitalWrite(16,0);
    Serial.print("\nLED turned OFF");
  }
  else if(led == 1){
    digitalWrite(16,1);
    Serial.print("\nLED turned ON");
  }
  delay(100);
}
