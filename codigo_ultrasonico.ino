// C++ code
//

int activate = 10;
int b = 6;
int red = 11;
int green = 12;
int trig = 8;
int echo = 7;
int buzz_length;
long duration;
long distance;

long ultrasonic();
void buzz(int d);
void setup()
{
  pinMode(activate, INPUT_PULLUP);
  pinMode(b, OUTPUT);
  pinMode(red, OUTPUT);
  pinMode(green, OUTPUT);
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  Serial.begin(9600);
}

void loop()
{
    digitalWrite(red, LOW);
  	digitalWrite(green, HIGH);
    
  while(digitalRead(activate) == LOW){
    digitalWrite(green, LOW);
 	digitalWrite(red, HIGH);
    distance = ultrasonic();
    buzz(distance);
  }
}


long ultrasonic(){
  digitalWrite(trig, LOW);
  delay(2);
  digitalWrite(trig, HIGH);
  delay(10);
  digitalWrite(trig, LOW);
  duration = pulseIn(echo, HIGH);
  distance = duration * (0.0343/2);
  Serial.println(distance);
  return distance;
}

void buzz(int d){
  buzz_length = map(d, 2, 330, 10, 1000);
  delay(buzz_length);
  tone(b, 2000);
  delay(100);
  noTone(b);
}


