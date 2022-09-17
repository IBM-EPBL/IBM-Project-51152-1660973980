// C++ code
//
void setup()
{
  pinMode(A2, OUTPUT);
  pinMode(A1, INPUT);
  pinMode(1, OUTPUT);
  pinMode(A0, INPUT);
  pinMode(2, OUTPUT);
  pinMode(A4, INPUT);
 Serial.begin(9600);
}

void loop()
{
 int gas=analogRead(A1);
 int b=map(gas,0,1023,0,255);
 if(b>50)
 {
   analogWrite(A2,b*10);
   delay(1000);
   analogWrite(A2,0);
   delay(10);
 }
  
 int temp=analogRead(A0);
 int c=map(temp,30,125,0,255);
 if(c>35)
 {
   digitalWrite(1,HIGH);
 }
 if(c<35)
 {
   digitalWrite(1,LOW);
  
 }
}