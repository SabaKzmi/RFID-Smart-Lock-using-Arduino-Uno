# RFID Smart Lock using Arduino Uno
This Arduino project implements a smart lock system using an RFID reader (MFRC522). When a registered RFID card is scanned, the lock is activated and an LED indicates access granted.
If the card is unrecognized, access is denied, and a different LED indicates the failure.
## How to Use
Start by installing the MFRC522 library in the Arduino IDE. Next, run the DumpInfo example code from the Examples menu. You can then retrieve a card's ID by holding it in front of the RFID reader. To register and grant access, add the ID to the knownUID array in the code.
### Configuration
|Green LED | pin 7|
|Red LED | pin 4|
|Lock (yellow wire) | pin 2|
|RST(MFRC522) | pin 9|
|SPI SS(MFRC522) | pin 10|
|SPI MOSI(MFRC522) | pin 11|
|SPI MISO(MFRC522) | pin 12|
|SPI SCK(MFRC522) | 13|

**lock configuration:**
<p align="center">
  <img src="https://github.com/SabaKzmi/RFID-Smart-Lock-using-Arduino-Uno/blob/49b6291550c703c551bcd46845d6de2f7427d005/pictures/config.png" alt="configurations" width=500 />
</p>  
