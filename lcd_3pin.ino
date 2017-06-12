/* Use an LCD with only 3 pins from the Arduino board */
/*                                                    */
/* PIN OUT                                            */
/*                                                    */
/* shift register (SR - 74HC595):                     */
/*  01 -> lcd D7                                      */
/*  02 -> lcd D6                                      */
/*  03 -> lcd D5                                      */
/*  04 -> lcd D4                                      */
/*  05 -> (empty)                                     */
/*  06 -> (empty)                                     */
/*  07 -> lcd RS                                      */
/*  08 -> GND                                         */
/*  09 -> (empty)                                     */
/*  10 -> 5V                                          */
/*  11 -> arduino pin 4 (SR CLOCK)                    */
/*  12 -> arduino pin 3 (SR LATCH)                    */
/*  13 -> GND                                         */
/*  14 -> arduino pin 2 (SR DATA)                     */
/*  15 -> lcd E                                       */
/*  16 -> 5V                                          */
/*                                                    */
/* LCD:                                               */
/*  VSS -> GND                                        */
/*  VDD -> 5V                                         */
/*  V0  -> 4.7k ohm -> GND  (LCD contrast)            */
/*  RS  -> SR pin 07                                  */
/*  RW  -> GND                                        */
/*  E   -> SR pin 15                                  */
/*  D0  -> (empty)                                    */
/*  D1  -> (empty)                                    */
/*  D2  -> (empty)                                    */
/*  D3  -> (empty)                                    */
/*  D4  -> SR pin 04                                  */
/*  D5  -> SR pin 03                                  */
/*  D6  -> SR pin 02                                  */
/*  D7  -> SR pin 01                                  */
/*  A   -> 5V (this is LCD+, LCD brightness)          */
/*  K   -> GND (this is LCD-)                         */

#include <LiquidCrystal595.h>    // include the library
LiquidCrystal595 lcd(2,3,4);     // datapin, latchpin, clockpin

void setup()
{
    lcd.begin(20,4);             // 16 characters, 2 rows

    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Wow. 3 pins!");
    lcd.setCursor(0,1);
    lcd.print("Fabulous");
    lcd.setCursor(0,2);
    lcd.print("Line 3");
    lcd.setCursor(0,3);
    lcd.print("Line 4");    
    
    Serial.begin(9600);
}

void loop()
{
    if(Serial.available() > 0)
    {
        String srow = Serial.readStringUntil(' ');
        String scol = Serial.readStringUntil(' ');
        String string = Serial.readString();
        
        lcd.setCursor(srow.toInt(), scol.toInt());
        lcd.print(string);
    }

    delay(100);
}
