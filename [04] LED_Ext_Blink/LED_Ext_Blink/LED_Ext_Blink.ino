#define LED_EXT       15

void setup() {
  // put your setup code here, to run once:
  pinMode(LED_EXT, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(LED_EXT, HIGH);
  delay(1000);
  digitalWrite(LED_EXT, LOW);
  delay(1000);
}
