#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>

// Wi-Fi credentials
const char* ssid = "Mali_Wifi";
const char* password = "Mali$1234";

// ThingSpeak credentials
const char* tsServer = "api.thingspeak.com";
const char* tsApiKey = "PBS3LTV8K59XDAOK";
// const int Field1 = 1; // Field number in your ThingSpeak channel
// const int Field2 = 2;
// const int Field3 = 3;
// const int Field4 = 4;
// const int Output = 5;

int flexValue1 = 0;
int flexValue2 = 0;
int flexValue3 = 0;
int flexValue4 = 0;

WiFiClient client;

void setup() {
  Serial.begin(9600);
  delay(10);

  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("");
  Serial.print("WiFi connected: ");
  Serial.println(ssid);
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());
}

void loop() {
  char buffer1[20] = "";
  if (Serial.available() > 0) {
    Serial.readBytesUntil('\n', buffer1, 20);
    flexValue1 = atoi(buffer1)+11;
    Serial.print("FlexValue1 READING: ");
    Serial.println(flexValue1);

    Serial.readBytesUntil('\n', buffer1, 20);
    flexValue2 = atoi(buffer1)+11;
    Serial.print("FlexValue2 READING: ");
    Serial.println(flexValue2);

    Serial.readBytesUntil('\n', buffer1, 20);
    flexValue3 = atoi(buffer1)+20;
    Serial.print("FlexValue3 READING: ");
    Serial.println(flexValue3);

    Serial.readBytesUntil('\n', buffer1, 20);
    flexValue4 = atoi(buffer1)+18;
    Serial.print("FlexValue4 READING: ");
    Serial.println(flexValue4);

    

    // Conditions
    // String output="";
    // if(flexValue1<210 && flexValue2<316 && flexValue3<=302 && flexValue4<=287){
    //   output+="Help";
    // }else if(flexValue2<316 && flexValue3<=301 && flexValue4<=287){
    //   output+="Washroom";
    // }else if(flexValue3<297 && flexValue4<=287){
    //   output+="Water";
    // }else if(flexValue4<=287){
    //   output+="Food";
    // }else{
    //   output+="Nothing";
    // }

    // Serial.println(output);

    Serial.println();

    // Create an HTTPClient object
    HTTPClient http;

    // Construct the URL for ThingSpeak
    String url = "http://";
    url += tsServer;
    url += "/update?api_key=";
    url += tsApiKey;
    url += "&field1=";
    url += String(flexValue1);
    url += "&field2=";
    url += String(flexValue2);
    url += "&field3=";
    url += String(flexValue3);
    url += "&field4=";
    url += String(flexValue4);

    // Send the GET request to ThingSpeak
    http.begin(client, url); // Updated line

    int httpResponseCode = http.GET();

    if (httpResponseCode == HTTP_CODE_OK) {
      Serial.println("Data sent to ThingSpeak successfully");
    } else {
      Serial.print("Error sending data to ThingSpeak. HTTP response code: ");
      Serial.println(httpResponseCode);
    }

    http.end();
  }
}
