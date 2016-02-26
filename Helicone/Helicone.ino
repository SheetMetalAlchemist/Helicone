/* Helicone Code v0.5 by S. Cusack
Pin layouts are as follows based on VFD params:
Arduino Pin 5 = VFD DI1
Ardunio Pin 6 = VFD DI2
Arduino Pin 7 = VFD DI3
Arduino Pin 8 = VFD DI4
Arduino Pin 9 = VFD DI5

Based on the following settings, VFD pins are set as follows:
P3.01 = 00: DI1 = FWD/STOP, DI2 = REV/STOP
P3.02 = 03: MultiSpeed Bit 1
P3.03 = 04: MultiSpeed Bit 2
P3.04 = 05: MultiSpeed Bit 3
*/

void setup() {
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  delay(3000);
}

void loop() {
  
  //In Helix
  
  dir(1);
  spd(1);
  delay(10000);
  
  //Begin transition to Pinecone
  spd(2);
  delay(5000);
  spd(5);
  delay(8000);
  spd(2);
  delay(4000);
  spd(1);
  delay(3000);
  spd(0);
  delay(3000);
  
  //In Pinecone
  
  dir(2);
  spd(1);
  delay(10000);
  
  //Begin transition to Helix
  
  spd(2);
  delay(5000);
  spd(5);
  delay(8000);
  spd(2);
  delay(3000);
  spd(0);
  delay(8500);

}

void dir(int direction) {
  switch (direction) {
    case 2:
      digitalWrite(5, HIGH);
      digitalWrite(6, LOW);
      break;
    case 1:
      digitalWrite(5, LOW);
      digitalWrite(6, HIGH);
      break;
    default:
      digitalWrite(5, LOW);
      digitalWrite(6, LOW);
      break;
  }
}

void spd(int val) {
  switch (val) {
    case 1:
      digitalWrite(7, HIGH);
      digitalWrite(8, LOW);
      digitalWrite(9, LOW);
      break;

    case 2:
      digitalWrite(7, LOW);
      digitalWrite(8, HIGH);
      digitalWrite(9, LOW);
      break;

    case 3:
      digitalWrite(7, HIGH);
      digitalWrite(8, HIGH);
      digitalWrite(9, LOW);
      break;

    case 4:
      digitalWrite(7, LOW);
      digitalWrite(8, LOW);
      digitalWrite(9, HIGH);
      break;

    case 5:
      digitalWrite(7, HIGH);
      digitalWrite(8, LOW);
      digitalWrite(9, HIGH);
      break;

    case 6:
      digitalWrite(7, LOW);
      digitalWrite(8, HIGH);
      digitalWrite(9, HIGH);
      break;

    case 7:
      digitalWrite(7, HIGH);
      digitalWrite(8, HIGH);
      digitalWrite(9, HIGH);
      break;

    default:
      digitalWrite(5, LOW);
      digitalWrite(6, LOW);
      digitalWrite(7, LOW);
      digitalWrite(8, LOW);
      digitalWrite(9, LOW);
  }
}


