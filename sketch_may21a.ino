#include <LiquidCrystal.h>


const int aPin  = 22; 
const int bPin  = 23; 
const int cPin  = 24;
const int dPin  = 25;
const int ePin  = 26;
const int fPin  = 27;
const int gPin  = 28;
const int dP    = 22;


const int gnd1 = 33; 
const int gnd2 = 34; 
const int gnd3 = 35; 
const int gnd4 = 36; 


int dig1 = 0; 
int dig2 = 0; 
int dig3 = 0; 
int dig4 = 0; 

unsigned long sonSayimZamani = 0;
unsigned long sonMuxZamani = 0;
int aktifHane = 1; 


LiquidCrystal lcd(36, 37, 26, 27, 28, 29);


void setup() {
  
  pinMode(aPin, OUTPUT); pinMode(bPin, OUTPUT); pinMode(cPin, OUTPUT);
  pinMode(dPin, OUTPUT); pinMode(ePin, OUTPUT); pinMode(fPin, OUTPUT);
  pinMode(gPin, OUTPUT); pinMode(dP, OUTPUT);

  
  pinMode(gnd1, OUTPUT); pinMode(gnd2, OUTPUT);
  pinMode(gnd3, OUTPUT); pinMode(gnd4, OUTPUT);

  
  lcd.begin(16, 2);
  lcd.setCursor(0, 0);
  lcd.print("Counter:");
}


void loop() {
  unsigned long simdikiZaman = millis();

  
  if (simdikiZaman - sonSayimZamani >= 1000) {
    sonSayimZamani = simdikiZaman;
    incrementCounter();
    updateLCD(); 
  }

  
  if (simdikiZaman - sonMuxZamani >= 4) {
    sonMuxZamani = simdikiZaman;
    displayMultiplex();
  }
}


void incrementCounter() {
  dig1++;
  if (dig1 >= 10) {
    dig1 = 0;
    dig2++;
    if (dig2 >= 10) {
      dig2 = 0;
      dig3++;
      if (dig3 >= 10) {
        dig3 = 0;
        dig4++;
        if (dig4 >= 10) {
          dig4 = 0; 
        }
      }
    }
  }
}


void displayMultiplex() {
 
  digitalWrite(gnd1, LOW);
  digitalWrite(gnd2, LOW);
  digitalWrite(gnd3, LOW);
  digitalWrite(gnd4, LOW);

  
  switch (aktifHane) {
    case 1:
      rakamBas(dig1);
      digitalWrite(gnd1, HIGH); 
      aktifHane = 2;
      break;
    case 2:
      rakamBas(dig2);
      digitalWrite(gnd2, HIGH);
      aktifHane = 3;
      break;
    case 3:
      rakamBas(dig3);
      digitalWrite(gnd3, HIGH);
      aktifHane = 4;
      break;
    case 4:
      rakamBas(dig4);
      digitalWrite(gnd4, HIGH);
      aktifHane = 1;
      break;
  }
}


void rakamBas(int num) {
  digitalWrite(dP, LOW); 
  
  switch (num) {
    case 0:
      digitalWrite(aPin, HIGH); digitalWrite(bPin, HIGH); digitalWrite(cPin, HIGH);
      digitalWrite(dPin, HIGH); digitalWrite(ePin, HIGH); digitalWrite(fPin, HIGH);
      digitalWrite(gPin, LOW);
      break;
    case 1: 
      digitalWrite(aPin, LOW);  digitalWrite(bPin, HIGH); digitalWrite(cPin, HIGH);
      digitalWrite(dPin, LOW);  digitalWrite(ePin, LOW);  digitalWrite(fPin, LOW);
      digitalWrite(gPin, LOW);
      break;
    case 2:
      digitalWrite(aPin, HIGH); digitalWrite(bPin, HIGH); digitalWrite(cPin, LOW);
      digitalWrite(dPin, HIGH); digitalWrite(ePin, HIGH); digitalWrite(fPin, LOW);
      digitalWrite(gPin, HIGH);
      break;
    case 3:
      digitalWrite(aPin, HIGH); digitalWrite(bPin, HIGH); digitalWrite(cPin, HIGH);
      digitalWrite(dPin, HIGH); digitalWrite(ePin, LOW);  digitalWrite(fPin, LOW);
      digitalWrite(gPin, HIGH);
      break;
    case 4:
      digitalWrite(aPin, LOW);  digitalWrite(bPin, HIGH); digitalWrite(cPin, HIGH);
      digitalWrite(dPin, LOW);  digitalWrite(ePin, LOW);  digitalWrite(fPin, HIGH);
      digitalWrite(gPin, HIGH);
      break;
    case 5:
      digitalWrite(aPin, HIGH); digitalWrite(bPin, LOW);  digitalWrite(cPin, HIGH);
      digitalWrite(dPin, HIGH); digitalWrite(ePin, LOW);  digitalWrite(fPin, HIGH);
      digitalWrite(gPin, HIGH);
      break;
    case 6:
      digitalWrite(aPin, HIGH); digitalWrite(bPin, LOW);  digitalWrite(cPin, HIGH);
      digitalWrite(dPin, HIGH); digitalWrite(ePin, HIGH); digitalWrite(fPin, HIGH);
      digitalWrite(gPin, HIGH);
      break;
    case 7:
      digitalWrite(aPin, HIGH); digitalWrite(bPin, HIGH); digitalWrite(cPin, HIGH);
      digitalWrite(dPin, LOW);  digitalWrite(ePin, LOW);  digitalWrite(fPin, LOW);
      digitalWrite(gPin, LOW);
      break;
    case 8:
      digitalWrite(aPin, HIGH); digitalWrite(bPin, HIGH); digitalWrite(cPin, HIGH);
      digitalWrite(dPin, HIGH); digitalWrite(ePin, HIGH); digitalWrite(fPin, HIGH);
      digitalWrite(gPin, HIGH);
      break;
    case 9:
      digitalWrite(aPin, HIGH); digitalWrite(bPin, HIGH); digitalWrite(cPin, HIGH);
      digitalWrite(dPin, HIGH); digitalWrite(ePin, LOW);  digitalWrite(fPin, HIGH);
      digitalWrite(gPin, HIGH);
      break;
  }
}


void updateLCD() {
  lcd.setCursor(0, 0);
  lcd.print("Counter: ");
  lcd.print(dig4);
  lcd.print(dig3);
  lcd.print(dig2);
  lcd.print(dig1);
  lcd.print("    "); 
}