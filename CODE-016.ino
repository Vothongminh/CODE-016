//VTM   https://www.youtube.com/c/VTMVlogVoThongMinh 
/*Kết nối     HC-SR04              ARDUINO          LCD1602-I2C
 *             Trig                  D8
 *             Echo                  D7
 *                                   D20               SDA
 *                                   D21               SCL
 */
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);
const int trig = 8;
const int echo = 7;
//...............................................
void setup()
{
  Serial.begin(9600);
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("Distance:");
  lcd.setCursor(13, 0);
  lcd.print(" cm");
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
}
//...............................................
void loop()
{
  unsigned long duration;
  int distance;
  digitalWrite(trig, 0);
  delayMicroseconds(2);
  digitalWrite(trig, 1);
  delayMicroseconds(5);
  digitalWrite(trig, 0);
  duration = pulseIn(echo, HIGH);
  distance = int(duration / 2 / 29.412);
  lcd.setCursor(10, 0);
  lcd.print(distance);
  if (distance < 10) {
    lcd.setCursor(11, 0);
    lcd.print("  ");
  }
  else if (distance < 100) {
    lcd.setCursor(12, 0);
    lcd.print(' ');
  }
  delay(200);
}
