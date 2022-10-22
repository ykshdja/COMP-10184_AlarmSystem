/**
 * STATEMENT OF AUTHORSHIP - I YASH KHANDUJA, 000826385 HERE BY DECLARE THAT THIS IS MY OWN WORK.
 * **/

  
#include <Arduino.h>
// digital input pin definitions
#define PIN_PIR D5
#define PIN_BUTTON D6
#define TIME 10000
/**
 * Stage 1:
  When motion is detected, turn the LED on solid for 10 seconds, then turn it off and wait for another motion 
  event.
 * 
*/

bool previousPirState = false;
bool detectMotion(){
    bool currPirState = digitalRead(PIN_PIR) == HIGH;
    bool motion = (currPirState && !previousPirState);
    previousPirState = currPirState;
    return motion;
}

void _SetLed_(bool state){
    if(state == true){
        digitalWrite(LED_BUILTIN,LOW);
    }
    if(state == false)
    {
        digitalWrite(LED_BUILTIN,HIGH);
    }
}

bool lastBtnState = false;
bool PushedBtn(){
    bool currBtnState = digitalRead(PIN_BUTTON) == LOW;
    bool pushed = (currBtnState && lastBtnState);
    lastBtnState = currBtnState;
    return pushed;
}


void setup() {
  Serial.begin(115200);

  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(PIN_PIR, INPUT);
  pinMode(PIN_BUTTON, INPUT_PULLUP);
  _SetLed_(false);
  Serial.print("calibrating sensor ");
    for(int i = 0; i <10; i++){
      Serial.print(".");
      delay(1000);
      }
    Serial.println(" done");
    Serial.println("SENSOR ACTIVE");
    delay(50);

}

void loop() {
   
    if(detectMotion()){
        _SetLed_(true);
        Serial.println("------");
        Serial.print("Motion Detected - ");
        Serial.print(millis()/1000);
        Serial.println(" Seconds");
        delay(TIME);
        _SetLed_(false);
    }
    
     delay(100);

}