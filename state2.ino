/*
state2.ino

ENGR 450 || GROUP D || MILESTONE 1
Ethan T. Daniels & Aidan Bradley

!! Programmed by Ethan T. Daniels !!

Last Edited 2017.9.7 9:12PM
*/
//setup for state 2, declaring state current state and initalizing pattern varaibles
void state2Setup()
{
  currentState = 2;
  patternStartTime = millis();
  
  int patternPlaying;
  int patternPending;
}

//playing the tunes
void state2()
{  
  unsigned long currentTime = millis();
  
  if(patternPlaying == 1)
  {
    done = tune1(currentTime-patternStartTime); 
  }
  if(patternPlaying == 2)
  {
    done = tune2(currentTime-patternStartTime); 
  }

  //checking to see if the second note has played to check for another button press
  if(note > 2 || note2 > 2)
  {
    int yelButState = digitalRead(yelBut);
    int blueButState = digitalRead(blueBut);

    if(yelButState == LOW)
    {
      patternPending = 1;
      state3Setup();
    }
    if(blueButState == LOW)
    {
      patternPending = 2;
      state3Setup();
    }
  }
  if(done == true)
  {
    state1Setup();
  }
}
