const int LED_EXT = 15;

const int pwm_freq = 100;
const int pwm_channel = 0;
const int pwm_resolution = 8;
int pwm_dutyCycle = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(LED_EXT, OUTPUT);
  ledcSetup(pwm_channel, pwm_freq, pwm_resolution);
  ledcAttachPin(LED_EXT, pwm_channel);
}

void loop() {
  // put your main code here, to run repeatedly:
  pwm_dutyCycle = 0;
  ledcWrite(pwm_channel, pwm_dutyCycle);
  delay(2000);

  pwm_dutyCycle = 64;
  ledcWrite(pwm_channel, pwm_dutyCycle);
  delay(2000);

  pwm_dutyCycle = 128;
  ledcWrite(pwm_channel, pwm_dutyCycle);
  delay(2000);

  pwm_dutyCycle = 192;
  ledcWrite(pwm_channel, pwm_dutyCycle);
  delay(2000);

  pwm_dutyCycle = 255;
  ledcWrite(pwm_channel, pwm_dutyCycle);
  delay(2000);
}
