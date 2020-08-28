#ifdef ESP32
  #include <WiFi.h>
#else
  #include <ESP8266WiFi.h>
#endif

const int SW_EXT = 5;

const char* ssid = "ssid";
const char* password = "password";

WiFiServer server(80);

void setup() {
  // put your setup code here, to run once:
  pinMode(SW_EXT, INPUT);
  
  Serial.begin(9600);
  while(!Serial)
  {
    //
  }
  Serial.println(""); Serial.println("");
  Serial.print("Connecting to ");
  Serial.println(ssid);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected");
  server.begin();
  Serial.println("Server started");
  Serial.print("IP address : ");
  Serial.println(WiFi.localIP());

  server.begin();
}

void loop() {
  // put your main code here, to run repeatedly:
  WiFiClient client = server.available();
  //Serial.println(analogRead(A4));
  
  if (client)
  {
    Serial.println("new client");
  
    while (client.connected())
    {
      String web = "HTTP/1.1 200 OK\r\nContent-Type: text/html\r\n\r\n";
      web += "<html>";
      web += "<head><title>Hardware monitor</title></head>";
      web += "<body>";
      web += "<h1>Hardware monitor</h1>";
      
      web += "<br>A/D ch[4] : ";
      web += String( ((analogRead(A4) * 3.3)/4096) );
      web += " volt";
      
      web += "<br>Switch Ext : ";
      if (digitalRead(SW_EXT) == LOW)
        web += "close";
      else
        web += "open";
      
      web += "</body>";
      web += "</html>";
      client.print(web);
      client.stop();
    }
  }
  delay(10);
}
