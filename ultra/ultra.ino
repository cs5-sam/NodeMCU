#include<ESP8266WiFi.h>
#include<FirebaseArduino.h>


#define FIREBASE_AUTH "iot-project1-93a34.firebaseio.com"
#define FIREBASE_PASS "mAoHzvxU1qcjn4OrtaflEXK35VrNehs9p9DHStrh"

#define WIFI_SSID "hopa"
#define WIFI_PASS "12345678"
#define trig 5
#define echo 4
#define DHT_TYPE DHT11


float in=0;
float cm=0;
void setup ()
{
  
  
  
  pinMode(trig,OUTPUT);
  pinMode(echo,INPUT);
Serial.begin(9600);
 WiFi.begin(WIFI_SSID,WIFI_PASS);
 Serial.print("Connecting to WIFI");
 while(WiFi.status()!=WL_CONNECTED)
 {
  Serial.print(".");
  delay(500);
 }
 Serial.print("\nWIFI CONNECTED.");
 Serial.print("\nIP ADDRESS:");
 Serial.print(WiFi.localIP());

 Firebase.begin(FIREBASE_AUTH,FIREBASE_PASS);
 Firebase.setFloat("Inch",0);
 Firebase.setFloat("CM",0); 
 
 delay(1000);
}


void loop()
{
  if(Firebase.failed())
  {
    Serial.print("\nCONNECTION LOST!");
    Serial.print(Firebase.error());
    Serial.print("trying to reconnect...");
    Firebase.begin(FIREBASE_AUTH,FIREBASE_PASS);
    return;
    
  }
digitalWrite(trig,LOW);
delayMicroseconds(2);
digitalWrite(trig,HIGH);
delayMicroseconds(10);
digitalWrite(trig,LOW);
cm = 0.01723 * pulseIn(echo,HIGH);
in = (cm/2.54);


Firebase.setFloat("Inch",in);
 Firebase.setFloat("CM",cm);


 Serial.print("\nInch = ");
 Serial.print(in);
 Serial.print("\t\tCM = ");
 Serial.print(cm);

 delay(500);
 }
