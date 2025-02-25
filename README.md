# RFID Smart Lock using Arduino Uno
This Arduino project implements a smart lock system using an RFID reader (MFRC522). When a registered RFID card is scanned, the lock is activated and an LED indicates access granted.
If the card is unrecognized, access is denied, and a different LED indicates the failure.
## How to Configure
- Green LED : pin 7
- Red LED : pin 4
- Lock (yellow wire) : pin 2
- RST : pin 9
- SPI SS : pin 10
- SPI MOSI : pin 11
- SPI MISO : pin 12
- SPI SCK : 13
<p align="center">
  <img src="https://github.com/SabaKzmi/RFID-Smart-Lock-using-Arduino-Uno/blob/49b6291550c703c551bcd46845d6de2f7427d005/pictures/config.png" alt="configurations" width=500 />
</p>  
