int sensorPin=A0;
int sensorValue;
int sensor_pin = A1;
int output_value;
int tempPin = A2;
int temp;
const int aPin=9;
const int bPin=12;
const int cPin=8;
void setup(){
  Serial.begin(9600);
  Serial.println("Reading from the sensor...");
  delay(2000);
  pinMode(aPin,OUTPUT);
  pinMode(bPin,OUTPUT);
  pinMode(cPin,OUTPUT);
}
void loop()
{
  sensorValue=analogRead(sensorPin);
  Serial.print("LDR value:");
  Serial.println(sensorValue);
  delay(100);
  if(sensorValue=0){
    digitalWrite(aPin,HIGH);
  }
  else{
    digitalWrite(aPin,LOW);
  }
  output_value=analogRead(sensor_pin);
  output_value=map(output_value,550,0,0,100);
  Serial.print("Moisture:");
  Serial.print(output_value);
  Serial.println("%");
  delay(1000);
  if(output_value<0){
    digitalWrite(bPin,HIGH);
  }
  else{
    digitalWrite(bPin,LOW);
  }
  temp = analogRead(tempPin);
temp = temp * 0.48828125;
Serial.print("TEMPERATURE = ");
Serial.print(temp); 
Serial.print("*C");
Serial.println();
delay(1000); 
if(temp>48){
    digitalWrite(cPin,HIGH);
  }
  else{
    digitalWrite(cPin,LOW);
  }
}
