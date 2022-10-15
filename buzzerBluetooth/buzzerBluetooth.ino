#define buzzer 2
#include <SoftwareSerial.h>

SoftwareSerial blueTooth(0, 1);
String cmdS;
String cmdT;

void setup() {
  // put your setup code here, to run once:
  pinMode(buzzer, OUTPUT);
  Serial.begin(9600);
  blueTooth.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  while (blueTooth.available()){
    delay(10);
    char c = blueTooth.read();
    cmdT += c;
    cmdS = cmdT;
    if (c == "#"){break;}
  }
  cmdT = "";
  if (cmdS.length() > 0){
    Serial.println(cmdS);
    if(cmdS == "on"){
      Serial.println("IT INSIDE");
      tone(buzzer, 1000);
      delay(500);
      noTone(buzzer);
      delay(500);
    }
    else if (cmdS == "off"){
      noTone(buzzer);
    }
  }
}
