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
  for (int i=0; i<255; i++)
  {
    pwm_dutyCycle = i;
    ledcWrite(pwm_channel, pwm_dutyCycle);
    delay(100);
  }
  
  for (int i=255; i>0; i--)
  {
    pwm_dutyCycle = i;
    ledcWrite(pwm_channel, pwm_dutyCycle);
    delay(100);
  }
}
