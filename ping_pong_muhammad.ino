/*
  Makes an advanced ping pong circut, with the goal to turn on the orang led.
*/
//Sets up score leds for player 2(The 32 is there to )
int P2SCORELEDS[] = {32, 9, 8, 7, 6, 5, A0};
int P1SCORELEDS[] = {32, A5, A4, A3, A2, A1, A0};
int P1SCORE = 2;
int P2SCORE = 2;
int LedPins[] = {2, 3, A5, A4, A3, A2, A1, A0, 5, 6, 7, 8, 9, 10, 11};
bool ON_STATE = false;
void setup() {
  //sets up both buttons
  pinMode(12, 0);
  pinMode(4, INPUT_PULLUP);
  //Uses our Array and a For loop to intilazie our pins
  for (int i = 0; i < 18; i++) {
    pinMode(LedPins[i], 1);
  }
  //Starts our serial moniter at 9600 bits
  Serial.begin(9600);
}
//sets up a function to check score
void ScoreChecker() {
  //Checks if the yellow or red led is on
  if (digitalRead(2) == 1) {
    // if it is, checks if the button is pressed
    if (digitalRead(4) == 0) {
      //adds 1 to player 1 score
      P1SCORE = P1SCORE  + 1;
      //Shows player 1's score via the green leds on the board
      digitalWrite(P1SCORELEDS[P1SCORE], 1);
      // prints p1's score in serial moniter
      Serial.println(P1SCORE);

    }
  }
  //Checks if the yellow or red led is on
  if (digitalRead(3) == 1) {
    // if it is, checks if the button is pressed
    if (digitalRead(4) == 0) {
      //adds 1 to player 1 score
      P1SCORE = P1SCORE + 1;
      //Shows player 1's score via the green leds on the board
      digitalWrite(P1SCORELEDS[P1SCORE], 1);
    }
  }
  //Checks if the yellow or red led is on
  if (digitalRead(10) == 1) {
    // if it is, checks if the button is pressed
    if (digitalRead(12) == 1) {
       //adds 1 to player 2 score
      P2SCORE = P2SCORE + 1;
      //Shows player 2's score via the green leds on the board
      digitalWrite(P2SCORELEDS[P2SCORE], 1);

    }
  }
  //Checks if the yellow or red led is on
  if (digitalRead(11) == 1) {
    // if it is, checks if the button is pressed
    if (digitalRead(12) == 1) {
      //adds 1 to player 2 score
      P2SCORE = P2SCORE + 1;
      //Shows player 2's score via the green leds on the board
      digitalWrite(P2SCORELEDS[P2SCORE], 1);

    }
  }
}
void loop() {
  //checks if the button on P1's side is pressed
  if (digitalRead(12) == 1) {
    //checks if the button on P2's side is pressed
    if (digitalRead(4) == 0) {
      //makes the state on, letting the game start
      ON_STATE = true;
    }
  }
  //checks if the state is on
  if (ON_STATE == true) {
    //call back to our function to check score
    ScoreChecker();
    //for loop to cycle through our led pins
    for (int i = 0; i < 18; i++) {
      //calls to our array to cycle through our pins going forward
      digitalWrite(LedPins[i], 1);
      //call back to our function to check score
      ScoreChecker();
      // adds a 250 milisecond delay
      delay (250);
      //call back to our function to check score
      ScoreChecker();
      //turns off the led pins going forawrd
      digitalWrite(LedPins[i], 0);
    }
    //call back to our function to check score
    ScoreChecker();
    //goes backwards through our array, so it goes from left to right
    for (int x = 15; x > -1; x--) {
      //calls back to our array to go backwards
      digitalWrite(LedPins[x], 1);
      //call back to our function to check score
      ScoreChecker();
      // adds a 250 milisecond delay
      delay (250);
      //call back to our function to check score
      ScoreChecker();
      //calls back to our array to go backwards and turn the leds off
      digitalWrite(LedPins[x], 0);
    }
    //call back to our function to check score
    ScoreChecker();
    //If player 1 gets a score of six
    if (P1SCORE >= 6) {
      //makes the on state off so the game halts
      ON_STATE = false;
      //resets score for player 1
      P1SCORE = 0;
      //resets score for player 2
      P2SCORE = 0;
      //If player 1 gets a score of six
    } else if (P2SCORE >= 6) {
      //makes the on state off so the game halts
      ON_STATE = false;
      //resets score for player 1
      P1SCORE = 0;
      //resets score for player 2
      P2SCORE = 0;
    }
    //if the reset button is pressed than
    if (digitalRead(13) == 1) {
      //halts the game
      ON_STATE = false;
      //resets score for p1
      P1SCORE = 0;
      //resets score for p2
      P2SCORE = 0;
    }
  }
}
