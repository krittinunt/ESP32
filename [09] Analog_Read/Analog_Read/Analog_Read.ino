int sensorValue = 0;
float voltCal = 0.0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  while (!Serial)
  {
    //
  }
  Serial.println();
  Serial.println();
  Serial.println("==========================");
  Serial.println("Test A/D 12 bits");
  Serial.println("--------------------------");
  Serial.println("Value\t\tVolt");
}

void loop() {
  // put your main code here, to run repeatedly:
  sensorValue = analogRead(A4);
  voltCal = (sensorValue * 3.3)/4096;
  Serial.print(sensorValue);
  Serial.print("\t\t");
  Serial.println(voltCal);
  delay(100);
}
