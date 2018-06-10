/**
 * @file    abletinController.ino
 * @brief   Main file of the DIY ableton live controller based on arduino
 * @author  valdep
 * version  v0.1
 * date     June 2018
 */

/* Includes -----------------------------------------------------------------*/
#include "MIDIUSB.h"

/* Defines ------------------------------------------------------------------*/
#define ADC_NBR       7
#define CHANNEL_SIZE  8

/* Enums and typedefs -------------------------------------------------------*/

/* Prototypes ---------------------------------------------------------------*/

/* Global variables ---------------------------------------------------------*/
int analogValue[ADC_NBR];
int analogPins[ADC_NBR];
int controllerValues[ADC_NBR][CHANNEL_SIZE];
int controllerValues_OLD[ADC_NBR][CHANNEL_SIZE];


/* Main program =============================================================*/
void setup()
{
  globalVariablesInit();
}

void loop()
{

}

/*===========================================================================*/
/* Function definitions------------------------------------------------------*/
/*...........................................................................*/
/**
 * @fn    void globalVariablesInit(void)
 * @brief This function is used to initialise the global varibles of the
 * application, like the analogValue array.
 */
void globalVariablesInit(void)
{
  int i = 0;
  int j = 0;

  for(i=0 ; i<ADC_NBR ; i++) analogValue = 0;

  for(i=0 ; i<ADC_NBR ; i++)
  {
    for ( j = 0; j < CHANNEL_SIZE; j++)
    {
      controllerValues[i][j] = 0;
      controllerValues_OLD[i][j] = 0;
    }
  }

  /*Assign each analog channel to a pin*/
  analogPins[0] = 0;
  analogPins[1] = 1;
  analogPins[2] = 2;
  analogPins[3] = 3;
  analogPins[4] = 4;
  analogPins[5] = 5;
  analogPins[6] = 6;
  analogPins[7] = 7;
}

/*...........................................................................*/
/**
 * @fn    void controlChange(byte channel, byte control, byte value)
 * @brief This function is used to send a control change message to a midi
 * device over Usb
 * @param channel;  Midi channel to send the message to
 * @param control;  the control associated to the midi channel to change
 * @param value;    value of the new control
 */
void controlChange(byte channel, byte control, byte value)
{
  midiEventPacket_t event = {0x0B, 0xB0 | channel, control, value};
  MidiUSB.sendMIDI(event);
}

/*...........................................................................*/
/**
 * @fn    void readADCs(void)
 * @brief This function is used to update the ADC values. It uses the
 * analogValue global array
 */
 void readADCs(void)
 {
   int i = 0;
   for( i=0 ; i<ADC_NBR ; i++)
   {
     /* division by 8 is for keeping the analog values between 0 and 128 */
     analogValue[i] = analogRead(analogPins[i]) / 8;
   }


 }

/*...........................................................................*/
/*
 * @fn    void updateControllerValues(void)
 * @brief This function is used to update the controllerValues array by calling
 * the readADCs() function for each channel.
 **/
void updateControllerValues(void)
{
  int i = 0;
  int j = 0;

  for( i=0 ; i < CHANNEL_SIZE ; i++ )
  {
    readADCs();
    for ( j=0 ; j<ADC_NBR ; j++) controllerValues[j][i] = analogValue[i];
  }
}



/*...........................................................................*/
void readButtons()
{
  for (int i = 0; i < NUM_BUTTONS; i++)
  {
    if (digitalRead(buttons[i]) == LOW)
    {
      bitWrite(pressedButtons, i, 1);
      delay(50);
    }
    else
      bitWrite(pressedButtons, i, 0);
  }
}


void readIntensity()
{
  int val = analogRead(intensityPot);
  intensity = (uint8_t) (map(val, 0, 1023, 0, 127));
}

void playNotes()
{
  for (int i = 0; i < NUM_BUTTONS; i++)
  {
    if (bitRead(pressedButtons, i) != bitRead(previousButtons, i))
    {
      if (bitRead(pressedButtons, i))
      {
        bitWrite(previousButtons, i , 1);
        noteOn(0, notePitches[i], intensity);
        MidiUSB.flush();
      }
      else
      {
        bitWrite(previousButtons, i , 0);
        noteOff(0, notePitches[i], 0);
        MidiUSB.flush();
      }
    }
  }
}

// First parameter is the event type (0x09 = note on, 0x08 = note off).
// Second parameter is note-on/note-off, combined with the channel.
// Channel can be anything between 0-15. Typically reported to the user as 1-16.
// Third parameter is the note number (48 = middle C).
// Fourth parameter is the velocity (64 = normal, 127 = fastest).

void noteOn(byte channel, byte pitch, byte velocity) {
  midiEventPacket_t noteOn = {0x09, 0x90 | channel, pitch, velocity};
  MidiUSB.sendMIDI(noteOn);
}

void noteOff(byte channel, byte pitch, byte velocity) {
  midiEventPacket_t noteOff = {0x08, 0x80 | channel, pitch, velocity};
  MidiUSB.sendMIDI(noteOff);
}
