/*
tune1.ino

ENGR 450 || GROUP D || MILESTONE 1
Ethan T. Daniels & Aidan Bradley

!! Programmed by Ethan T. Daniels !!

Last Edited 2017.9.7 9:12PM
*/
//this will play the game of thrones tune
boolean tune1 (int elapsedTime)
{
  //tune 1 melody
  int gameOfThrones [] = {
    NOTE_G2, NOTE_C2, NOTE_E2, NOTE_F2, 
    NOTE_G2, NOTE_C2, NOTE_E2, NOTE_F2,
    NOTE_G2, NOTE_C2, NOTE_E2, NOTE_F2, 
    NOTE_G2, NOTE_C2, NOTE_E2, NOTE_F2, NOTE_D2
  };

  //tune 1 note duration
  int noteDurations1 [] = {
    4, 4, 8, 8,
    4, 4, 8, 8,
    4, 4, 8, 8,
    4, 4, 8, 8, 2
  };

  if (elapsedTime - priorTime > pauseBetweenNotes) 
  {

    int noteDuration = 1000 / noteDurations1[note];
    tone(buzz, gameOfThrones[note], noteDuration);

    pauseBetweenNotes = noteDuration * 1.30;
    priorTime = elapsedTime;
    note++;
  }

  // Check if done
  if(note == 17) 
  {
    note = 1;
    priorTime = 0;
    return true;
  }
  else
  {
    return false;
  }
}
