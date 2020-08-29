#ifdef ESP32
  #include <WiFi.h>
#else
  #include <ESP8266WiFi.h>
#endif

const int SW_EXT = 5;
const int LED_EXT = 15;

const char* ssid = "ssid";
const char* password = "password";

WiFiServer server(80);

void setup() {
  // put your setup code here, to run once:
  pinMode(LED_EXT, OUTPUT);
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
  
  if (client)
  {
    Serial.println("new client");
    String currentLine = "";
  
    while (client.connected())
    {
      if (client.available()){
        char c = client.read();
        if (c == '\n'){
          if (currentLine.length() == 0)
          {
            String web = "HTTP/1.1 200 OK\r\nContent-Type: text/html\r\n\r\n";
            web += "<html>";
            web += "<head><title>Hardware Monitor&Control</title></head>";
            web += "<body>";
            web += "<h1>Hardware Monitor&Control</h1>";
            
            web += "<br>A/D ch[4] : ";
            web += String( ((analogRead(A4) * 3.3)/4096) );
            web += " volt";

            web += "<br>Switch Ext : ";
            if (digitalRead(SW_EXT) == LOW)
              web += "close";
            else
              web += "open";

            web += "<br>LED Ext : ";
            if (digitalRead(LED_EXT) == HIGH)
              web += "On";
            else
              web += "Off";
            
            web += " <a href=\"/H\">[LED On]</a> |";
            web += " <a href=\"/L\">[LED Off]</a>";
            web += "</body>";
            web += "</html>";
            client.print(web);
            break;
          }
          else
          {
            currentLine = "";
          }
        }
        else if (c!= '\r')
        {
          currentLine += c;
        }
        
        if (currentLine.endsWith("GET /H"))
        {
          digitalWrite(LED_EXT, HIGH);
        }

        if (currentLine.endsWith("GET /L"))
        {
          digitalWrite(LED_EXT, LOW);
        }
      }
    }
    client.stop();
  }
}
