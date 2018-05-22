# Custom Ableton Live controller

## Inspiration
* [Apollo 13 DIY controller](https://adamdzak.blogspot.de/2012/07/introducingapollo-13.html)
* [Evan Kale 3d print controller](https://www.youtube.com/watch?v=4sopfrr1830)

## General design
The  idea is to 

## Microcontroller choice
The microcontroller must be compatible with a MIDI over USB library. Since MIDI over USB is the main feature (the only one ?) this is the fastest and easiest way to develop the device.

For the moment the only serious candidate is the [Arduino MIDI USB Library](https://www.arduino.cc/en/Reference/MIDIUSB). These library allows any microcontroller with native USB capabilities (atmega32u4 based boards or ARM boards) to appear as a MIDI peripheral over USB to a connected computer.

The library is compatible with PluggableUSB-ready cores (AVR core > 1.6.8, SAM core > 1.6.4, SAMD core > 1.6.1).

The following Arduino boards are compatible with the library :
* [Arduino Leonardo](https://www.arduino.cc/en/Main/Arduino_BoardLeonardo)
* [Arduino Micro](https://www.arduino.cc/en/pmwiki.php?n=Main/arduinoBoardMicro)

Both have 20 I/Os, Micro seems to be more interesting main because of the size (and the format: can easely be plugged into a larger board thanks to connectors).

## Passive components
### Faders, potentiometers and push buttons
* [AlieExpress faders 75mm](https://fr.aliexpress.com/item/5-Pcs-75-MM-Double-B10K-Original-B10KX2-Behringer-Pot-Mixer-Fader/32860718454.html?spm=a2g0w.search0204.3.8.5b3e293fKfCkXj&ws_ab_test=searchweb0_0,searchweb201602_5_10320_10152_10321_10065_10151_10344_10068_5722815_10342_10547_10343_10340_10341_5722915_5722615_10696_10194_10084_10083_10618_10304_10307_10306_10302_5722715_5711215_10059_308_100031_10103_10624_10623_10622_5711315_5722515_10621_10620_10814_10815,searchweb201603_1,ppcSwitch_5_ppcChannel&algo_expid=a4f2b774-d9a6-4d71-8f13-5fea60cd70fc-0&algo_pvid=a4f2b774-d9a6-4d71-8f13-5fea60cd70fc&transAbTest=ae803_1&priceBeautifyAB=0)
* [Farnell RK09 potentiometers](http://fr.farnell.com/alps/rk09k1130ah1/potentiometre-rotatif-10k-17mm/dp/1191725?MER=bn_browse_1TP_MostPopular_2)
* [AlieExpress Push Buttons 10 mm](https://fr.aliexpress.com/item/6pcs-self-reset-Push-Button-Switch-10mm-Self-Return-Momentary-Push-Button-Switch/32814986667.html?spm=a2g0w.search0204.3.237.330e1fdfPRSZHA&ws_ab_test=searchweb0_0,searchweb201602_5_10320_10152_10321_10065_10151_10344_10068_5722815_10342_10547_10343_10340_10341_5722915_5722615_10696_10194_10084_10083_10618_10304_10307_10306_10302_5722715_5711215_10059_308_100031_10103_10624_10623_10622_5711315_5722515_10621_10620_10814_10815,searchweb201603_1,ppcSwitch_5_ppcChannel&algo_expid=ddd49a58-e49d-4ea7-9a1c-c16a629be649-0&algo_pvid=ddd49a58-e49d-4ea7-9a1c-c16a629be649&transAbTest=ae803_1&priceBeautifyAB=0)

## Further development

