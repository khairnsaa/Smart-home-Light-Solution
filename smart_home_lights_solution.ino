int redLed = 13;
int yellowLed = 12;
int limeLed = 11;
int blueLed = 10;

int redBtn = 9;
int yellowBtn = 8;
int limeBtn = 7;
int blueBtn = 6;

int redLedState = LOW;
int yellowLedState = LOW;
int limeLedState = LOW;
int blueLedState = LOW;

int lastRedBtnState;
int lastYellowBtnState;
int lastLimeBtnState;
int lastBlueBtnState;

int currentRedBtnState;
int currentYellowBtnState;
int currentLimeBtnState;
int currentBlueBtnState;

bool playAgain = true;
String motion;
int votingTime;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  
  pinMode(redLed, OUTPUT);
  pinMode(yellowLed, OUTPUT);
  pinMode(limeLed, OUTPUT);
  pinMode(blueLed, OUTPUT);
  
  pinMode(redBtn, INPUT_PULLUP);
  pinMode(yellowBtn, INPUT_PULLUP);
  pinMode(limeBtn, INPUT_PULLUP);
  pinMode(blueBtn, INPUT_PULLUP);

  currentRedBtnState = digitalRead(redBtn);
  currentYellowBtnState = digitalRead(yellowBtn);
  currentLimeBtnState = digitalRead(limeBtn);
  currentBlueBtnState = digitalRead(blueBtn);

  Serial.println("--- SMART HOME : LIGHTS SOLUTION ---");
  Serial.println("By: Khairunnisa");
  Serial.println("BM 5B");
  Serial.println("1803421047");
  Serial.println("--------------------------------------------");
}

void loop() {
  // put your main code here, to run repeatedly:
  lastRedBtnState    = currentRedBtnState;  
  lastYellowBtnState = currentYellowBtnState;  
  lastLimeBtnState   = currentLimeBtnState;  
  lastBlueBtnState   = currentBlueBtnState;  
     
  currentRedBtnState = digitalRead(redBtn);
  currentYellowBtnState = digitalRead(yellowBtn);
  currentLimeBtnState = digitalRead(limeBtn);
  currentBlueBtnState = digitalRead(blueBtn);

  if(lastRedBtnState == HIGH && currentRedBtnState == LOW){
      redLedState = !redLedState;
      digitalWrite(redLed, redLedState);
      delay(500);
      if(redLedState ==HIGH){
         Serial.println("Lampu kamar 1 menyala");
      }
      if(redLedState == LOW){
        Serial.println("Lampu kamar 1 mati");
      }
    } else if(lastYellowBtnState == HIGH && currentYellowBtnState == LOW){
      
      yellowLedState = !yellowLedState;
      digitalWrite(yellowLed, yellowLedState);
      
      if(yellowLedState ==HIGH){
         Serial.println("Lampu kamar 2 menyala");
      }
      if(yellowLedState == LOW){
        Serial.println("Lampu kamar 2 mati");
      }
      
    } else if(lastLimeBtnState == HIGH && currentLimeBtnState == LOW){
      
      limeLedState = !limeLedState;
      digitalWrite(limeLed, limeLedState);
      
      if(limeLedState ==HIGH){
         Serial.println("Lampu kamar mandi menyala");
      }
      if(limeLedState == LOW){
        Serial.println("Lampu kamar mandi mati");
        
      }
    } else if(lastBlueBtnState == HIGH && currentBlueBtnState == LOW){
      
      blueLedState = !blueLedState;
      digitalWrite(blueLed, blueLedState);
      
      if(blueLedState ==HIGH){
         Serial.println("Lampu ruang keluarga menyala");
      }
      if(blueLedState == LOW){
        Serial.println("ruang keluarga mati");
      }
    }
}
