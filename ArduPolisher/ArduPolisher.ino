#include <Wire.h>
#include <LiquidCrystal.h>

/***   Global variables   ***/
int time=0;
int power=0;
LiquidCrystal lcd(8, 9, 4, 5, 6, 7);

/***   Function declaration   ***/
void printLCD ();
void setParams ();

void setup()
{
  pinMode(A0,INPUT);


  lcd.begin(16, 2);
lcd.clear();



}


void loop()
{
    printLCD();
    setParams();

}

/***   Function definition   ***/
void printLCD () {
  lcd.setCursor(0,0);
  lcd.print(String("Time: ") + String(time));
  lcd.setCursor(0,1);
  lcd.print(String("Power: ") + String(power));
 }
void setParams () {
  printLCD();
  time=analogRead(A0);
  delay(1000);
  printLCD();
 }
