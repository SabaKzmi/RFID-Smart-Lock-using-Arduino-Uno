#include <SPI.h>
#include <MFRC522.h>

#define RST_PIN         9          // reset pin - rfid reader
#define SS_PIN          10         // slave selector pin - rfid reader

MFRC522 mfrc522(SS_PIN, RST_PIN);  // MFRC522 instanciation

// known UID
byte knownUID[][4] = {{0x13, 0x24, 0x95, 0xE2}};

void setup() {
    Serial.begin(9600);
    SPI.begin();           // Init SPI bus
    mfrc522.PCD_Init();    // Init MFRC522
    pinMode(2, OUTPUT);    // lock pin
    pinMode(7, OUTPUT);    // green LED
    pinMode(4, OUTPUT);    // red LED
    Serial.println("Scan a RFID card");
}

void loop() {
    // Look for new cards
    if (!mfrc522.PICC_IsNewCardPresent()) {
        return;
    }
    
    // If there is a new card read UID
    if (!mfrc522.PICC_ReadCardSerial()) {
        return;
    }
    
    // Compare the UID with the known ID
    if (compareUIDs(mfrc522.uid.uidByte, mfrc522.uid.size)) {
        Serial.println("Access Granted");
        digitalWrite(7,HIGH);
        digitalWrite(2,HIGH);
        delay(5000);
        digitalWrite(7,LOW);
        digitalWrite(2,LOW);
        delay(1000);
    } else {
        Serial.println("Access Denied");
        digitalWrite(4,HIGH);
        delay(5000);
        digitalWrite(4,LOW);
        delay(1000);
    }
}

// Function to compare the scanned UID with the known UID
bool compareUIDs(byte* scannedUID, byte length) {
  // i is the rows (all known IDs)
  for (byte i = 0; i < sizeof(knownUID)/4; i++){
    if (length == 4 && memcmp(scannedUID, knownUID[i], 4) == 0){
      return true;
    }
  }
  return false;
}
