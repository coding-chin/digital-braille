// BlisCare Single Cell Digital Braille Prototype
// ESP32 Firmware

// Actuator GPIO pins (6 dots)
const int dotPins[6] = {13, 12, 14, 27, 26, 25};

String incomingText = "";

// Basic Braille mapping (lowercase letters only for demo)
byte brailleMap[26][6] = {
  {1,0,0,0,0,0}, // a
  {1,1,0,0,0,0}, // b
  {1,0,0,1,0,0}, // c
  {1,0,0,1,1,0}, // d
  {1,0,0,0,1,0}, // e
  {1,1,0,1,0,0}, // f
  {1,1,0,1,1,0}, // g
  {1,1,0,0,1,0}, // h
  {0,1,0,1,0,0}, // i
  {0,1,0,1,1,0}, // j
  {1,0,1,0,0,0}, // k
  {1,1,1,0,0,0}, // l
  {1,0,1,1,0,0}, // m
  {1,0,1,1,1,0}, // n
  {1,0,1,0,1,0}, // o
  {1,1,1,1,0,0}, // p
  {1,1,1,1,1,0}, // q
  {1,1,1,0,1,0}, // r
  {0,1,1,1,0,0}, // s
  {0,1,1,1,1,0}, // t
  {1,0,1,0,0,1}, // u
  {1,1,1,0,0,1}, // v
  {0,1,0,1,1,1}, // w
  {1,0,1,1,0,1}, // x
  {1,0,1,1,1,1}, // y
  {1,0,1,0,1,1}  // z
};

void setup() {
  Serial.begin(115200);

  for(int i=0; i<6; i++){
    pinMode(dotPins[i], OUTPUT);
    digitalWrite(dotPins[i], LOW);
  }
}

void displayBraille(char c) {
  if(c < 'a' || c > 'z') return;

  int index = c - 'a';

  for(int i=0; i<6; i++){
    digitalWrite(dotPins[i], brailleMap[index][i]);
  }
}

void clearCell() {
  for(int i=0; i<6; i++){
    digitalWrite(dotPins[i], LOW);
  }
}

void loop() {
  if(Serial.available()){
    incomingText = Serial.readStringUntil('\n');
    incomingText.toLowerCase();

    for(int i=0; i<incomingText.length(); i++){
      displayBraille(incomingText[i]);
      delay(1000); // display duration
      clearCell();
      delay(300);
    }
  }
}
