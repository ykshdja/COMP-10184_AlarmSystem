/**
 * STATEMENT OF AUTHORSHIP - I YASH KHANDUJA, 000826385 HERE BY DECLARE THAT THIS IS MY OWN WORK.
 Stage - 4
 * **/

  
#include <Arduino.h>
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

 Stage 4:
 Like stage 3, but if the pushbutton is pressed while the LED is flashing, turn the LED off and wait for another
 motion detection event.


*/

enum alarmState{
    enabled, 
    countdown, 
    active, 
    disabled 
};
int isAlarmActive = enabled;
long countDown = 0;
bool previousPirState = false;
bool lastBtnState = false;

void handleAlarmEnabled(bool isDetected){
    if(isDetected == true){
        isAlarmActive = countdown;
    }
}

bool detectMotion(){
    bool currPirState = digitalRead(PIN_PIR) == HIGH;
    bool motion = (currPirState && !previousPirState);
    previousPirState = currPirState;
    return motion;
}

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
        delay(100);
        _SetLed_(false);
        delay(100);
    }
    isAlarmActive = active;
    Serial.println("*********************************");
    Serial.print("Motion Detected at - ");
    Serial.print(millis()/1000);
    Serial.println(" Seconds");
}

void handlebtnPressOnFlashing(bool btnPushed){
    if(countDown == 0){
        countDown = millis();
    }
    if(btnPushed){
        _SetLed_(false);
        countDown = 0;
        isAlarmActive = enabled;
    Serial.println("****************");
    Serial.print("Button Pushed at - ");
    Serial.print(millis()/1000);
    Serial.println(" Seconds");
    return;
    }
    int timeCountDownStart = millis() - countDown;
    if(timeCountDownStart>(200*40)){
        countDown = 0;
        isAlarmActive = active;
        Serial.println("****************");
        Serial.print("Motion Detected at - ");
        Serial.print(millis()/1000);
        Serial.println(" Seconds");
        return;
    }
    _SetLed_(timeCountDownStart % 200 < 50);

}

void setup() {
  Serial.begin(115200);
  Serial.println();
  Serial.println();
  Serial.println("=========================================");
  Serial.println("---ALARM SYSTEM - STAGE 2---");
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
    bool pushDetected = PushedBtn();
    switch(isAlarmActive){
        case enabled:
        handleAlarmEnabled(detected);
        break;
        case countdown:
         handlebtnPressOnFlashing(pushDetected);
         break;
         case active:
         _SetLed_(true);
         break;
         case disabled:
         break;
    }

}
