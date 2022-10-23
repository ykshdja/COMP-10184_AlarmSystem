/**
 * STATEMENT OF AUTHORSHIP - I YASH KHANDUJA, 000826385 HERE BY DECLARE THAT THIS IS MY OWN WORK.
 * Stage 1
 * Stage 2
 * Stage 3
 * **/

  
#include <Arduino.h>
// digital input pin definitions
#define PIN_PIR D5
#define PIN_BUTTON D6
#define TIME 100
#define BLINK_NUM 40


/**
 * Stage 1:
  When motion is detected, turn the LED on solid for 10 seconds, then turn it off and wait for another motion 
  event.
  
 * 
Stage 2:
 Like Stage 1, but instead of keeping the LED on solid, blink the LED for 10 seconds (4 blinks per second).

Stage 3:
 Like stage 2, but after 10s, turn on the LED solid and keep it that way. Only by resetting the D1 Mini will the
 program wait for more motion events.


*/

enum alarmState{
    enabled, //0
    countdown, //1
    active, //2
    disabled //3
};

int isAlarmActive = enabled;
void handleAlarmEnabled(bool isDetected){
    if(isDetected == true){
        isAlarmActive = countdown;
    }


}

bool previousPirState = false;
bool detectMotion(){
    bool currPirState = digitalRead(PIN_PIR) == HIGH;
    bool motion = (currPirState && !previousPirState);
    previousPirState = currPirState;
    return motion;
}
bool lastBtnState = false;
bool PushedBtn(){
    bool currBtnState = digitalRead(PIN_BUTTON) == LOW;
    bool pushed = (currBtnState && lastBtnState);
    lastBtnState = currBtnState;
    return pushed;
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

void handleMotionDetection(){
    for(int i=0;i<BLINK_NUM;i++){
        _SetLed_(true);
        delay(50);
        _SetLed_(false);
        delay(200);
    }
    isAlarmActive = active;
    Serial.println("*********************************");
    Serial.print("Motion Detected at - ");
    Serial.print(millis()/1000);
    Serial.println(" Seconds");
}




void setup() {

  Serial.begin(115200);
  Serial.println();
  Serial.println();
  Serial.println("=========================================");
  Serial.println("---ALARM SYSTEM - STAGE 3---");
  Serial.println("Yash Khanduja, 000826385");
  Serial.println("=========================================");
 
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
    bool detected = detectMotion();
    switch(isAlarmActive){
        case enabled:
        handleAlarmEnabled(detected);
        break;
        case countdown:
         handleMotionDetection();
         break;
         case active:
         _SetLed_(true);
         break;

    }







    // _SetLed_(false);
    // bool detected = detectMotion();
    // if(detected){
    //     handleMotionDetection();
    //     delay(TIME);
    //     return;
    // }
    // setLed(true);
    //      delay(100);

}
