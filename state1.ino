/*
state1.ino
 
ENGR 450 || GROUP D || MILESTONE 1
Ethan T. Daniels & Aidan Bradley

!! Programmed by Ethan T. Daniels !!

Last Edited 2017.9.7 9:12PM
*/

//setup which invokes current state and intializes the pattern variables
void state1Setup()
{
  currentState = 1;
  int patternPlaying = 0;
  int patternPending = 0;
}

//waiting for a user input
void state1()
{
  int yelButState = digitalRead(yelBut);
  int blueButState = digitalRead(blueBut);
  
  if(yelButState == LOW)
  {
    patternPlaying = 1;
    state2Setup(); 
  }
  if(blueButState == LOW)
  {
    patternPlaying = 2;
    state2Setup(); 
  }
}
