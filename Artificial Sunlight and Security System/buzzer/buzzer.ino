int x;
int y;
void setup(){
  pinMode(A0,INPUT);
  pinMode(2,INPUT);
  pinMode(12,OUTPUT);
  pinMode(13,OUTPUT);
  pinMode(11,OUTPUT);
  Serial.begin(9600);
}

void loop(){
  led(x);
  pir(y);
}


void led(int a){
  a=analogRead(A0);
  Serial.println("This is led");
  Serial.println(a);
  if(a<50){
    digitalWrite(13,HIGH);
  }
  else{
    digitalWrite(13,LOW);
  }
}


void pir(int b){
  b=digitalRead(2);
  Serial.println("This is pir");
  Serial.println(b);
  if(b==HIGH){
    digitalWrite(12,HIGH);
    digitalWrite(11,HIGH);
    delay(200);
    digitalWrite(11,LOW);
    delay(200);
  }
  else{
    digitalWrite(12,LOW);
    digitalWrite(11,LOW);
  }
  
}
