/*
twoTonesDanielsBradley.ino

ENGR 450 || GROUP D || MILESTONE 1
Ethan T. Daniels & Aidan Bradley

!! Programmed by Ethan T. Daniels !!

This program will play two seperate tunes, if you trigger one tune while another tune is playing
the seocnd tune invoked will take president

Last Edited 2017.9.7 9:12PM
*/

//read in note value frequency representations 
#include "pitches.h"

//declare pinouts for I/O
const int yelBut = 2;
const int blueBut = 3;
const int ledPin = 13;
const int buzz = 8;

//declare variables used throughout
int currentState;
int note = 0;
int note2 = 0;
int priorTime = 0;
int pauseBetweenNotes = 400;
int patternPlaying;
int patternPending;

boolean done;

unsigned long patternStartTime;

//setup code, declaring I/O starting program by calling setup
void setup()
{
    pinMode(ledPin, OUTPUT);
    pinMode(yelBut, INPUT);
    pinMode(blueBut, INPUT);
    pinMode(buzz, INPUT);
    state1Setup();
}


//Looping through final solution, switch case selects which state to tranition to next
void loop()
{
  switch(currentState)
  {
    //waiting
    case 1:
    {
      state1();
      break;
    }
    //playing
    case 2:
    {
      state2();
      break; 
    }
    //play-pending
    case 3:
    {
      state3();
      break;
    }
  }
}
