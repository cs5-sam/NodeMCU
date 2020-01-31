void setup(){
  pinMode(4,OUTPUT);
}

void loop(){
  for(int i=0;i<=1023;i++){
    analogWrite(4,i);
    delay(10);
  }
  delay(200);
  for(int j=1023;j>=0;j--){
    analogWrite(4,j);
    delay(10);
  }
  
  
}
