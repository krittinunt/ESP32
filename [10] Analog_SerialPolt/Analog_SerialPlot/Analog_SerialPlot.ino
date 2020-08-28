int sensorValue = 0;
float voltCal = 0.0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  while (!Serial)
  {
    //
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  sensorValue = analogRead(A4);
  voltCal = (sensorValue * 3.3)/4096;
  Serial.print(voltCal);
  Serial.println();
  delay(100);
}
