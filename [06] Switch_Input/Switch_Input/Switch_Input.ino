const int LED_EXT = 15;
const int SW_EXT = 5;

void setup() {
  // put your setup code here, to run once:
  pinMode(LED_EXT, OUTPUT);
  pinMode(SW_EXT, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (digitalRead(SW_EXT) == LOW)
  {
    digitalWrite(LED_EXT, !digitalRead(LED_EXT));
  }
}
