int trigpin = 2;
int echopin = 3;
float dist = 0;
float speed = 0.034;

void setup()
{
  pinMode(trigpin,OUTPUT);
  pinMode(echopin,INPUT);
  Serial.begin(9600);
  digitalWrite(trigpin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigpin, LOW);
}

void loop()
{
  int t=0;
  digitalWrite(trigpin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigpin, LOW);
  t = pulseIn(echopin,HIGH);
  dist = (speed*t)/2;
  Serial.print(dist);
  Serial.print(" cm  ");
  if(dist <= 150)
  {
    Serial.println("NOT SAFE");
    digitalWrite(7,HIGH);
    digitalWrite(4,LOW);
    digitalWrite(12,HIGH);delay(100);
    digitalWrite(12,LOW);delay(100);
  }
  else if(dist <= 300)
  {
    Serial.println("MID RANGE");
    digitalWrite(7,HIGH);
    digitalWrite(4,HIGH);
    digitalWrite(12,HIGH);delay(1000);
    digitalWrite(12,LOW);delay(1000);
  }
  else
  {
    Serial.println("SAFE");
    digitalWrite(7,LOW);
    digitalWrite(4,HIGH);
    digitalWrite(12,HIGH);
  }  
}