#include <avr/sleep.h>
#define leftButton A5
#define midButton A4
#define rightButton A3

int lives = 5;
unsigned long startTime; // the start time for every loop
unsigned long timeout = 2400; // the maximum time bedore losing life
int level = 1;

void setup() {
  // 3 pins for 3 leds
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);
  digitalWrite(10, LOW);
  digitalWrite(11, LOW);
  digitalWrite(12, LOW);

  // 3 pins for 3 buttons
  pinMode(leftButton, INPUT);
  pinMode(midButton, INPUT);
  pinMode(rightButton, INPUT);
 
  // 8 pins for the 7-segments:
  pinMode(2, OUTPUT); //middle
  pinMode(3, OUTPUT); // top left
  pinMode(4, OUTPUT); //top
  pinMode(5, OUTPUT); // top right
  pinMode(6, OUTPUT); // bottom right
  pinMode(7, OUTPUT); // bottom
  pinMode(8, OUTPUT); //bottom left

  // looks like loading
  digitalWrite(3, HIGH);
  delay(100);
  digitalWrite(4, HIGH);
  delay(100);
  digitalWrite(5, HIGH);
  delay(100);
  digitalWrite(6, HIGH);
  delay(100);
  digitalWrite(7, HIGH);
  delay(100);
  digitalWrite(8, HIGH);
  delay(100);

  digitalWrite(3, LOW);
  delay(100);
  digitalWrite(4, LOW);
  delay(100);
  digitalWrite(5, LOW);
  delay(100);
  digitalWrite(6, LOW);
  delay(100);
  digitalWrite(7, LOW);
  delay(100);
  digitalWrite(8, LOW);
  delay(100);



  //choose the level of the game
  while(digitalRead(rightButton) != HIGH){
    switch (level) {
      case 1:
        digitalWrite(2, LOW);
        digitalWrite(3, LOW);
        digitalWrite(4,LOW);
        digitalWrite(5, HIGH);
        digitalWrite(6, HIGH);
        digitalWrite(7, LOW);
        digitalWrite(8, LOW);
        break;
      case 2:
        digitalWrite(2, HIGH);
        digitalWrite(3, LOW);
        digitalWrite(4,HIGH);
        digitalWrite(5, HIGH);
        digitalWrite(6, LOW);
        digitalWrite(7, HIGH);
        digitalWrite(8, HIGH);
        break;
      case 3:
        digitalWrite(2, HIGH);
        digitalWrite(3, LOW);
        digitalWrite(4,HIGH); 
        digitalWrite(5, HIGH);
        digitalWrite(6, HIGH);
        digitalWrite(7, HIGH);
        digitalWrite(8, LOW);
        break;  
    }

    //wait to the player to choose the level he wants
    while (digitalRead(leftButton) == LOW && digitalRead(midButton) == LOW && digitalRead(rightButton) == LOW) {
      delay(50);
      if(digitalRead(leftButton) == HIGH && level > 1){
      level--;
      break;
      }
      if(digitalRead(midButton) == HIGH && level < 3){
        level++;
        break;
      }
      if(digitalRead(rightButton) == HIGH)
        break;
      }
    }
  //define the timeout by the level the player choose
  timeout /= level;

  //start the game with 3 2 1
  //the number 3:
  digitalWrite(2, HIGH);
  digitalWrite(3, LOW);
  digitalWrite(4,HIGH); 
  digitalWrite(5, HIGH);
  digitalWrite(6, HIGH);
  digitalWrite(7, HIGH);
  digitalWrite(8, LOW);
  delay(1000);

  //the number 2:
  digitalWrite(2, HIGH);
  digitalWrite(3, LOW);
  digitalWrite(4,HIGH);
  digitalWrite(5, HIGH);
  digitalWrite(6, LOW);
  digitalWrite(7, HIGH);
  digitalWrite(8, HIGH);
  delay(1000);

  //the number 1:
  digitalWrite(2, LOW);
  digitalWrite(3, LOW);
  digitalWrite(4,LOW);
  digitalWrite(5, HIGH);
  digitalWrite(6, HIGH);
  digitalWrite(7, LOW);
  digitalWrite(8, LOW);
  delay(1000);
}

// Function to check if we have exceeded the allowed time
boolean checkTimeoutAndUpdateLives(int &lives, int randomNumber){
   if (millis() - startTime >= timeout) {
          lives--;
          digitalWrite(randomNumber, LOW); // turn the led off
          delay(100);
          return true;
   }
   return false;
}

// print the number of lives we have
void printLives(){
  switch (lives) {
  case 5:
    digitalWrite(2, HIGH);
    digitalWrite(3, HIGH);
    digitalWrite(4,HIGH);
    digitalWrite(5, LOW);
    digitalWrite(6, HIGH);
    digitalWrite(7, HIGH);
    digitalWrite(8, LOW);
    break;

  case 4:
    digitalWrite(2, HIGH); //middle
    digitalWrite(3, HIGH); // top left
    digitalWrite(4, LOW); //top
    digitalWrite(5, HIGH); // top right
    digitalWrite(6, HIGH); // bottom right
    digitalWrite(7, LOW); // bottom
    digitalWrite(8, LOW); //bottom left
    break;

  case 3:
    digitalWrite(2, HIGH);
    digitalWrite(3, LOW);
    digitalWrite(4,HIGH); 
    digitalWrite(5, HIGH);
    digitalWrite(6, HIGH);
    digitalWrite(7, HIGH);
    digitalWrite(8, LOW);
    break;

  case 2:
    digitalWrite(2, HIGH);
    digitalWrite(3, LOW);
    digitalWrite(4,HIGH);
    digitalWrite(5, HIGH);
    digitalWrite(6, LOW);
    digitalWrite(7, HIGH);
    digitalWrite(8, HIGH);
    break;

  case 1:
    digitalWrite(2, LOW);
    digitalWrite(3, LOW);
    digitalWrite(4,LOW);
    digitalWrite(5, HIGH);
    digitalWrite(6, HIGH);
    digitalWrite(7, LOW);
    digitalWrite(8, LOW);
    break;

  case 0:
    digitalWrite(2, LOW);
    digitalWrite(3, HIGH);
    digitalWrite(4, HIGH);
    digitalWrite(5, HIGH);
    digitalWrite(6, HIGH);
    digitalWrite(7, HIGH);
    digitalWrite(8, HIGH);
    break;
  }
}

// if the player lost, turn off the microcontroller
void turnOffMicrocontroller(){
  digitalWrite(10, LOW);
    digitalWrite(11, LOW);
    digitalWrite(12, LOW);
    //leds blink to inform that the game ended
    for(int i = 0; i<4; i++){
      digitalWrite(10, HIGH);
      digitalWrite(11, HIGH);
      digitalWrite(12, HIGH);
      delay(600);
      digitalWrite(10, LOW);
      digitalWrite(11, LOW);
      digitalWrite(12, LOW);
      delay(600);
    }

    //turn off all the exits and then put the microcontroller to sleep
    for (int i = 0; i < 19; i++) {
    pinMode(i, INPUT);
    digitalWrite(i, LOW);
    }
    set_sleep_mode(SLEEP_MODE_PWR_DOWN);
    sleep_enable();
    sleep_cpu();
}

void loop() {
  printLives();
  delay(150);
  if(lives == 0)
    turnOffMicrocontroller();
    
  int randomNumber = random(10, 13);  // random number between 10 to 12
  digitalWrite(randomNumber, HIGH);

  // save the time that the led turn on
  startTime = millis();
  int correctButton;
  switch (randomNumber) {
    case 10:
      digitalWrite(11, LOW);
      digitalWrite(12, LOW);
      correctButton = left`;
      break;

    case 11:
      digitalWrite(10, LOW);
      digitalWrite(12, LOW);
      correctButton = midButton;
      break;

    case 12:
      digitalWrite(10, LOW);
      digitalWrite(11, LOW);
      correctButton = rightButton;
      break;
  }

  while (true) {
    // Check timeout condition
    if (checkTimeoutAndUpdateLives(lives, randomNumber)) {
      break;
    }

    // Check Button presses
    if (digitalRead(leftButton) == HIGH || digitalRead(midButton) == HIGH || digitalRead(rightButton) == HIGH) {
      if (digitalRead(correctButton) == HIGH) {
        digitalWrite(randomNumber, LOW);
        delay(100);
        break;
      }
      
      else {
        lives--; // Deduct life only once for the wrong Button press
        break;
      }
    }
  }
}
