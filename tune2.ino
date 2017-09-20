/*
tune2.ino

ENGR 450 || GROUP D || MILESTONE 1
Ethan T. Daniels & Aidan Bradley

!! Programmed by Ethan T. Daniels !!

Last Edited 2017.9.7 9:12PM
*/
//will play the imperial march tune
boolean tune2 (int elapsedTime)
{
  //tune 2 melody
  int imperialMarch [] = 
  {
    NOTE_G2,NOTE_G2,NOTE_G2,NOTE_E2,NOTE_B2,NOTE_G2,NOTE_E2,NOTE_B2,NOTE_G2,
    NOTE_D3,NOTE_D3,NOTE_D3,NOTE_E3,NOTE_B2,NOTE_G2,NOTE_E2,NOTE_B2,NOTE_GS2
  };
  
  //tune 2 duration
  int noteDurations2 [] = 
  {
    2, 2, 2, 2, 4, 2, 2, 4, 1,
    2, 2, 2, 2, 4, 2, 2, 4, 1
  };  

  //will check the when the next note should be played
  if (elapsedTime - priorTime > pauseBetweenNotes) 
  {

    int noteDuration = 1000 / noteDurations2[note2];
    tone(buzz, imperialMarch[note2], noteDuration);

    pauseBetweenNotes = noteDuration * 1.30;
    priorTime = elapsedTime;
    note2++;
  }

  //check if you have iterated through the tune completly or not 
  if(note2 == 18)
  {
    note2 = 1;
    priorTime = 0;
    return true;
  }
  else
  {
    return false;
  }
}
