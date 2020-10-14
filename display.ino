#include <LiquidCrystal.h>

const int rs = 11, en = 10, d4 = 12, d5 = 13, d6 = 19, d7 = 9;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup_lcd()
{
  lcd.begin(16, 2);
  //lcd.print("Flywheels");
}
void welcome_screen()
{
  lcd.setCursor(0, 0);
  lcd.print("   Flywheels   ");
  lcd.setCursor(0, 1);
  lcd.print(" Sanitizer Disp ");
}

void object()
{
  lcd.setCursor(0, 0);
  lcd.print("   Flywheels   ");
  lcd.setCursor(0, 1);
  lcd.print("ObjectDetected");
}

void stby()
{
  lcd.setCursor(0, 0);
  lcd.print("   Flywheels   ");
  lcd.setCursor(0, 1);
  lcd.print("    Standby    ");
}

void tank_low()
{
  lcd.setCursor(0, 0);
  lcd.print("   Flywheels   ");
  lcd.setCursor(0, 1);
  lcd.print(" Sanitizer LOW ");
}
void tank_full()
{
  lcd.setCursor(0, 0);
  lcd.print("   Flywheels   ");
  lcd.setCursor(0, 1);
  lcd.print(" SanitizerFULL ");
}
void tank_empty()
{
  lcd.setCursor(0, 0);
  lcd.print("   Flywheels   ");
  lcd.setCursor(0, 1);
  lcd.print(" SanitizerEMPTY");
}
void set_object()
{
  lcd.setCursor(0, 0);
  lcd.print("  SET  OBJECT  ");
  lcd.setCursor(0, 1);
  lcd.print("               ");
}
void disp_param(int dist)
{
  lcd.setCursor(0, 1);
  lcd.print(dist);
  lcd.print("      cms");
}

void set_san_full()
{
  lcd.setCursor(0, 0);
  lcd.print("   SET  FULL   ");
  lcd.setCursor(0, 1);
  lcd.print("               ");
}
void set_san_low()
{
  lcd.setCursor(0, 0);
  lcd.print("    SET LOW    ");
  lcd.setCursor(0, 1);
  lcd.print("               ");
}
void set_san_empty()
{
  lcd.setCursor(0, 0);
  lcd.print("   SET EMPTY   ");
  lcd.setCursor(0, 1);
  lcd.print("               ");
}
void set_delay()
{
  lcd.setCursor(0,0);
  lcd.print(" DISPENSE TIME ");
  lcd.setCursor(0,1);
  lcd.print("                 ");
}
void disp(int key)
{
  lcd.setCursor(10, 0);
  lcd.print(key);
}
void disp_param1(int dis)
{
  lcd.setCursor(0, 1);
  lcd.print(dis);
  lcd.print("    milliseconds");
}
