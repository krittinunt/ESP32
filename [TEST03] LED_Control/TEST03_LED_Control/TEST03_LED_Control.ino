const int LED_EXT = 15;

const int pwm_freq = 100;
const int pwm_channel = 0;
const int pwm_resolution = 8;
int pwm_dutyCycle = 0;

int sensorValue = 0;
float voltCal = 0.0;

void setup() {
  // put your setup code here, to run once:
  pinMode(LED_EXT, OUTPUT);

  Serial.begin(9600);
  while(!Serial)
  {
    //
  }

  ledcSetup(pwm_channel, pwm_freq, pwm_resolution);
  ledcAttachPin(LED_EXT, pwm_channel);
}

void loop() {
  // put your main code here, to run repeatedly:
  sensorValue = analogRead(A4);
  pwm_dutyCycle = map(sensorValue, 0, 4095, 0, 255);
  Serial.println(pwm_dutyCycle);
  ledcWrite(pwm_channel, pwm_dutyCycle);
  delay(100);
}
