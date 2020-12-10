
#include <ESP8266WiFi.h>                                                
#include <FirebaseArduino.h>                                            
                                                         

#define FIREBASE_HOST "iot-based-agrology-default-rtdb.firebaseio.com"                        
#define FIREBASE_AUTH "lLBCpXNk2UV9qgPYie5rwiXEntKP3R9TyUIbsChf"            

#define WIFI_SSID "Sindhu"                                            
#define WIFI_PASSWORD "Sagar@14"                                    
 
                                                    
void setup() {
// Open serial communications and wait for port to open:
Serial.begin(115200);
while (!Serial) {
; // wait for serial port to connect. Needed for native USB port only
}
WiFi.begin(WIFI_SSID, WIFI_PASSWORD);                                     //try to connect with wifi
  Serial.print("Connecting to ");
  Serial.print(WIFI_SSID);
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print("."); 
    delay(500);
  }
  Serial.println();
  Serial.print("Connected to ");
  Serial.println(WIFI_SSID);
  Serial.print("IP Address is : ");
  Serial.println(WiFi.localIP());                                            //print local IP address
  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
}

void firebasereconnect()
{
  Serial.println("Trying to reconnect");
  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
  Serial.println();
}

void loop() { // run over and over
if (Firebase.failed()) {
      Serial.print("Failed to connect");
      Serial.println(Firebase.error());
      Serial.println();
      Serial.println();
      firebasereconnect();
      return;
}
if (Serial.available()) {
String fireb=Serial.readString();
Serial.println(fireb);
Firebase.setString("/PhotoResistor/MoistureContent", String(fireb));
Serial.println("Database updated");
Serial.println();
delay(5000);
}
}
