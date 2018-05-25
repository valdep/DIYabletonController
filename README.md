# Custom Ableton Live controller

The idea is to develop a custom Ableton Live controller that fits personnal needs. The main purpose is to use the final device in an electronic music live context.

## Inspiration
* [Apollo 13 DIY controller](https://adamdzak.blogspot.de/2012/07/introducingapollo-13.html)
* [Evan Kale 3d print controller](https://www.youtube.com/watch?v=4sopfrr1830)
* [Stephen Bodzin's PO10 controller](https://www.youtube.com/watch?v=Hv_oF2ol_Ks&t=2316s)
* [Arduino 8 steps sequencer (see the pot wiring in this case)](https://www.youtube.com/watch?v=9oGlCfwCoCw)

## General design
Sections of the controller :
* 1 Drums
    * faders
    *  effect pots
* 1 Percussion
    * 1 fader
    * 3 effect pots
* 1 Bass
    * 1 fader
    * effect pots
* 1 Lead
    * 1 fader
    * effect pots
* 4 Other
    * 1 fader (volume of the track)
    * 3 effect pots

### Electronic requirements
* Each track must have 4,8 or 16 analog components. this will help the regroupment of tracks for multiplexing the analog signals.
* Don't forget to add a diode on the sig pin of each pot. This will prevents the current to go in the wrong direction.

### Casing
* The top of the controller will be printed with a 3d printer.
* The 3d printer can print 200 x 200mm objects. The maximum size of the controller will be 400 x 200mm (2 panels). 
* Other parts like PCB supports will be printed with the same printer.
* The rest of the case will be made of wood (?)
* The top of the case will be transparent (?)

### Other
* [Bakelyte MF-AOX _Moog Style_ Knobs](https://fr.aliexpress.com/item/5Pcs-MF-A01-MF-A02-MF-A03-MF-A04-MF-A05-Potentiometer-Knob-WH118-WX050-Rotary/32863008984.html?spm=a2g0w.search0104.3.131.2e8f79f9ArqRCu&ws_ab_test=searchweb0_0,searchweb201602_5_10320_10152_10321_10065_10151_10344_10068_5722815_10342_10547_10343_10340_10341_5722915_5722615_10696_10194_10084_10083_10618_10304_10307_10306_10302_5722715_5711215_10059_308_100031_10103_10624_10623_10622_5711315_5722515_10621_10620_10814_10815,searchweb201603_25,ppcSwitch_4&algo_expid=3713f69c-d8db-470e-818c-062a083249c2-19&algo_pvid=3713f69c-d8db-470e-818c-062a083249c2&priceBeautifyAB=0)
* 


### Microcontroller choice
The microcontroller must be compatible with a MIDI over USB library. Since MIDI over USB is the main feature (the only one ?) this is the fastest and easiest way to develop the device.

For the moment the only serious candidate is the [Arduino MIDI USB Library](https://www.arduino.cc/en/Reference/MIDIUSB). These library allows any microcontroller with native USB capabilities (atmega32u4 based boards or ARM boards) to appear as a MIDI peripheral over USB to a connected computer.

The library is compatible with PluggableUSB-ready cores (AVR core > 1.6.8, SAM core > 1.6.4, SAMD core > 1.6.1).

The following Arduino boards are compatible with the library :
* [Arduino Leonardo](https://www.arduino.cc/en/Main/Arduino_BoardLeonardo)
* [Arduino Micro](https://www.arduino.cc/en/pmwiki.php?n=Main/arduinoBoardMicro)

Both have 20 I/Os, Micro seems to be more interesting main because of the size (and the format: can easely be plugged into a larger board thanks to connectors).

Moreover the library is bi-directionnal, thanks to _void sendMIDI(midiEventPacket_t event);_ you can send MIDI to the DAW and with _midiEventPacket_t read(void);_ you can receive MIDI from the DAW.

### Electronic components

__Active components__
* [Opto-isolator 6N136](https://fr.aliexpress.com/item/10PCS-6N136-DIP8-DIP-photoelectric-coupler-new-and-original/32544590113.html?spm=a2g0w.search0204.3.35.6b9d3ea9XM8OFM&ws_ab_test=searchweb0_0,searchweb201602_5_10152_10065_10151_10344_10068_5722815_10342_10343_10340_10341_5722915_5722615_10696_10084_10083_10618_10305_10304_10307_10306_10302_5722715_5711215_10059_308_100031_10103_10624_10623_10622_5711315_5722515_10621_10620_10814_10815,searchweb201603_25,ppcSwitch_4_ppcChannel&algo_expid=cdf69f2d-b7dc-4eca-90dc-7539c82506eb-4&algo_pvid=cdf69f2d-b7dc-4eca-90dc-7539c82506eb&priceBeautifyAB=0)
* [NOT gate 74LS14 (?)](https://fr.aliexpress.com/item/in-stock-can-pay-SN74LS14N-74LS14N-74LS14-DIP14/32820697583.html?spm=a2g0w.search0204.3.51.7a8a6de0ihCEoc&ws_ab_test=searchweb0_0,searchweb201602_5_10152_10065_10151_10344_10068_5722815_10342_10343_10340_10341_5722915_5722615_10696_10084_10083_10618_10305_10304_10307_10306_10302_5722715_5711215_10059_308_100031_10103_10624_10623_10622_5711315_5722515_10621_10620_10814_10815,searchweb201603_25,ppcSwitch_4_ppcChannel&algo_expid=3365fb83-e542-4494-8d62-b7651955ce1d-7&algo_pvid=3365fb83-e542-4494-8d62-b7651955ce1d&priceBeautifyAB=0)
* [Analog Multiplexer 4051](https://fr.aliexpress.com/item/10PCS-LOT-CD4051BE-CD4051-4051BE-4051-DIP16/32837745800.html?spm=a2g0w.search0204.3.49.42a57b4663YuMU&ws_ab_test=searchweb0_0,searchweb201602_5_10152_10065_10151_10344_10068_5722815_10342_10343_10340_10341_5722915_5722615_10696_10084_10083_10618_10305_10304_10307_10306_10302_5722715_5711215_10059_308_100031_10103_10624_10623_10622_5711315_5722515_10621_10620_10814_10815,searchweb201603_25,ppcSwitch_4_ppcChannel&algo_expid=c11c592d-039d-4d0a-a1d9-42d6cc3b5ee0-7&algo_pvid=c11c592d-039d-4d0a-a1d9-42d6cc3b5ee0&priceBeautifyAB=0)

__Faders, potentiometers and push buttons__
* [AlieExpress faders 75mm](https://fr.aliexpress.com/item/5-Pcs-75-MM-Double-B10K-Original-B10KX2-Behringer-Pot-Mixer-Fader/32860718454.html?spm=a2g0w.search0204.3.8.5b3e293fKfCkXj&ws_ab_test=searchweb0_0,searchweb201602_5_10320_10152_10321_10065_10151_10344_10068_5722815_10342_10547_10343_10340_10341_5722915_5722615_10696_10194_10084_10083_10618_10304_10307_10306_10302_5722715_5711215_10059_308_100031_10103_10624_10623_10622_5711315_5722515_10621_10620_10814_10815,searchweb201603_1,ppcSwitch_5_ppcChannel&algo_expid=a4f2b774-d9a6-4d71-8f13-5fea60cd70fc-0&algo_pvid=a4f2b774-d9a6-4d71-8f13-5fea60cd70fc&transAbTest=ae803_1&priceBeautifyAB=0)
* [potentiometers](https://fr.aliexpress.com/item/Free-shipping-100pcs-15mm-20mm-WH148-1k-2k-5k-10k-20k-50k-100k-250k-500k-1M/1871247535.html?spm=a2g0w.search0204.3.2.31982bb2Zf5YHL&s=p&ws_ab_test=searchweb0_0%2Csearchweb201602_5_10152_10065_10151_10344_10068_5722815_10342_10343_10340_10341_5722915_5722615_10696_10084_10083_10618_10305_10304_10307_10306_10302_5722715_5711215_10059_308_100031_10103_10624_10623_10622_5711315_5722515_10621_10620_10814_10815%2Csearchweb201603_25%2CppcSwitch_4_ppcChannel&priceBeautifyAB=0)
* [AlieExpress Push Buttons 10 mm](https://fr.aliexpress.com/item/6pcs-self-reset-Push-Button-Switch-10mm-Self-Return-Momentary-Push-Button-Switch/32814986667.html?spm=a2g0w.search0204.3.237.330e1fdfPRSZHA&ws_ab_test=searchweb0_0,searchweb201602_5_10320_10152_10321_10065_10151_10344_10068_5722815_10342_10547_10343_10340_10341_5722915_5722615_10696_10194_10084_10083_10618_10304_10307_10306_10302_5722715_5711215_10059_308_100031_10103_10624_10623_10622_5711315_5722515_10621_10620_10814_10815,searchweb201603_1,ppcSwitch_5_ppcChannel&algo_expid=ddd49a58-e49d-4ea7-9a1c-c16a629be649-0&algo_pvid=ddd49a58-e49d-4ea7-9a1c-c16a629be649&transAbTest=ae803_1&priceBeautifyAB=0)

__Connectors__
* [MIDI connector](https://fr.aliexpress.com/item/20pcs-4P-5P-6P-7P-8P-DIN-S-Terminal-Connector-Midi-Cable-Lead-Audio-Plug-Female/32843864182.html?spm=a2g0w.search0104.3.71.1b6222dfTU29ua&ws_ab_test=searchweb0_0,searchweb201602_5_10320_10152_10321_10065_10151_10344_10068_5722815_10342_10547_10343_10340_10341_5722915_5722615_10696_10194_10084_10083_10618_10304_10307_10306_10302_5722715_5711215_10059_308_100031_10103_10624_10623_10622_5711315_5722515_10621_10620_10814_10815,searchweb201603_25,ppcSwitch_4&algo_expid=f8774b94-0b66-4360-afd0-9cbdfbefd872-10&algo_pvid=f8774b94-0b66-4360-afd0-9cbdfbefd872&priceBeautifyAB=0)
* [USB type B connector]()
* [Ribbon cable connectors (10 wires ?)]()

## Further development

* The controller will feature several MIDI Thru outputs. These outputs will be completely derived from the MIDI input, this feature consists only of hardware. Most schematics includes an opto-isolator in order to isolate the signal comming from the MIDI in and NOT logic gates that are used has buffer for MIDI Thru outputs. An exemple of Midi Thru : [midi thru box](https://moroccodave.com/2017/10/04/diy-midi-thru-box-version-2/)
* The controller will feature an input for plug in a footswitch. For exemple some commands will be trigger by this footswitch.
