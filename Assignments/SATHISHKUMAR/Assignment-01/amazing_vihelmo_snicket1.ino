
int t = 2;
int e = 3;
int b = 9;
void setup()
{
  pinMode(11, OUTPUT);
  Serial.begin(9600);
  pinMode(t,OUTPUT);
  pinMode(e,INPUT);
  pinMode(b,OUTPUT);
  pinMode(4,INPUT);
  pinMode(13,OUTPUT);
  
}

void loop()
{
  // ultrasonic sensor
  
  digitalWrite(t,LOW);
  digitalWrite(t,HIGH);
  delayMicroseconds(10);
  digitalWrite(t,LOW);
  float dur = pulseIn(e,HIGH);
  float dis = (dur*0.0343)/2;
  Serial.print("Distance :");
  Serial.print(dis);
  Serial.println("cm ");
  if(dis>50)
  digitalWrite(b,HIGH);
  else
    digitalWrite(b,LOW);
    
  int b = map(dis,20,300,0,255);
  Serial.print("map value :");
  Serial.println(b);
  analogWrite(9,b);
  
  // temperture sensor
  
  int a = analogRead(A0);
  Serial.print("Analog Value :");
  Serial.println(a);
  int c = map(a,0,1023,0,255);
  Serial.print("map value :");
  Serial.println(c);
  analogWrite(11,c);
  delay(2000);
  
  //PIR Motion Sensor
  
  int p= digitalRead(4);
  Serial.println(p);
  digitalWrite(13,LOW);
  
  if(p){
    Serial.println("Motion detected!!!");
    digitalWrite(13,HIGH);
  }
  delay(1000);
  
}
