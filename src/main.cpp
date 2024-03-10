#include <Arduino.h>
#include <LiquidCrystal_I2C.h>
#include <WiFi.h>
#include "env.h"
#include <HTTPClient.h> 
#include <ArduinoJson.h>


LiquidCrystal_I2C lcd(0x27,16,2);  // set the LCD address to 0x27 for a 16 chars and 2 line display

void setup() {

Serial.begin(9600); 

  WiFi.begin(ssid, password);
  Serial.println("Connecting");
  while(WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.print("Connected to WiFi network with IP Address: ");
  Serial.println(WiFi.localIP());

  lcd.init();     
  lcd.backlight();      // Make sure backlight is on
  
 
}

void loop() 
{

 HTTPClient http; 
  
  http.begin(endpoint.c_str());  
  http.addHeader("api-key",api_key);

  int httpResponseCode = http.GET(); 

  if (httpResponseCode >0) {
    Serial.print("HTTP Response code: ");
    Serial.println(httpResponseCode);
    String responseBody = http.getString();
    Serial.println(responseBody);
    

      JsonDocument doc;

      DeserializationError error = deserializeJson(doc, responseBody);

        if (error){
          Serial.print("deserializeJson()failed: ");
          Serial.println(error.c_str());
          return;
        }
        String message1 = doc["line_1"];
        String message2 = doc["line_2"];

        
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print(message1);
        lcd.setCursor(0, 1);
        lcd.print(message2);


       
      }
      http.end();
      delay(1000);  
}
     
