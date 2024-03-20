#include <LiquidCrystal.h>

// select the pins used on the LCD panel
LiquidCrystal lcd(8, 9, 4, 5, 6, 7);

void setup()
{
  lcd.begin(16, 2);              // start the library
  lcd.setCursor(0,0);
  lcd.print("Holi Poli"); // print the first message on the first line
  lcd.setCursor(0,1);
  lcd.print("Soy Gaby"); // print the second message on the second line
}

void loop()
{
  // No necesitamos ninguna acción en el loop para este ejemplo
}




