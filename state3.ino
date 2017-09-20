/*
state3.ino

ENGR 450 || GROUP D || MILESTONE 1
Ethan T. Daniels & Aidan Bradley

!! Programmed by Ethan T. Daniels !!

Last Edited 2017.9.7 9:12PM
*/
void state3Setup()
{
  currentState = 3;
}

//allows a pending call to be actuated, would pend the next tune to be played
void state3()
{
  unsigned long currentTime = millis();
  
  if(patternPlaying == 1)
  {
    done = tune1(currentTime - patternStartTime);
  }
  if(patternPlaying == 2)
  {
    done = tune2(currentTime - patternStartTime);
  }
  if(done == true)
  {
    state2Setup();
    patternPlaying = patternPending;
  }
}
