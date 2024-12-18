float temp;
float vout;
float vout1;
int LED = 13;
int gasSensor;
int piezo = 7;

void setup()
{
  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
  pinMode(LED, OUTPUT);
  pinMode(piezo, OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  vout = analogRead(A1);
  vout1 = (vout / 1023.0) * 5000.0;
  temp = (vout1 - 500) / 10.0;
  
  gasSensor = analogRead(A0);
  
  if (temp >= 50)
  {
    digitalWrite(LED, HIGH);
  }
  else
  {
    digitalWrite(LED, LOW);
  }
  
  if (gasSensor >= 90)
  {
    digitalWrite(piezo, HIGH);
  }
  else
  {
    digitalWrite(piezo, LOW);
  }
  
  Serial.print("Temperature (°C) = ");
  Serial.print(temp);
  Serial.print("\tGas Sensor Value = ");
  Serial.println(gasSensor);
  
  delay(1000);
}
