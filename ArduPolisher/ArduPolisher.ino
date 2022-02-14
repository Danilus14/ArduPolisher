#include <Wire.h>
#include <LiquidCrystal.h>

/***   Global variables   ***/
int select=700;
int up=195;
int down=380;
int left=500;
int right=50;
int none=1500;
LiquidCrystal lcd(8, 9, 4, 5, 6, 7);
int time=0;
int power=0;
int run=0;
int pointer=0;
int read;
int aux;

/***   Function declaration   ***/
void printPointer ();
void blinkPointer ();
void printParams ();
void printValues ();
void setParams ();
void menu ();

void setup()
{
  pinMode(A0,INPUT);







  lcd.begin(16, 2);
lcd.clear();



  read=none;


  aux=read;



}


void loop()
{
    printParams();
    setParams();

}

/***   Function definition   ***/
void printPointer () {
  if (pointer == 0) {
    lcd.setCursor(0,0);
    lcd.print(">");
   }else {
    lcd.setCursor(0,1);
    lcd.print(">");
   }
 }
void blinkPointer () {
  lcd.setCursor(0,0);
  lcd.print(" ");
  lcd.setCursor(0,1);
  lcd.print(" ");
  delay(500);
  printPointer();
  delay(500);
 }
void printParams () {
  lcd.setCursor(1,0);
  lcd.print("Time: ");
  lcd.setCursor(1,1);
  lcd.print("Power: ");
 }
void printValues () {
  lcd.setCursor(7,0);
  lcd.print(time);
  lcd.setCursor(7,1);
  lcd.print(power);
 }
void setParams () {
  while (run == 0) {
    read=analogRead(A0);
    menu();
    printValues();
    blinkPointer();
   }
 }
void menu () {
  if (read != aux) {
    switch (read)
    {
      case select:
      {
        run=1;
        break;
      }
      case right:
      {
        if (pointer == 0) {
          time=time + 60;
         }else {
          power=power + 10;
         }
        break;
      }
      case left:
      {
        if (pointer == 0) {
          time=time - 60;
         }else {
          power=power - 10;
         }
        break;
      }
      case up:
      {
        pointer=0;
        break;
      }
      case down:
      {
        pointer=1;
        break;
      }
    }
    aux=read;
   }
 }
