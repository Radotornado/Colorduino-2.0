#include <Wire.h>                                                                         //
#include <LCD.h>                                                                          //Включват се бибилиотекеите за звуковия модул и дисплея
#include <LiquidCrystal_I2C.h>                                                            //
#include <Wtv020sd16p.h>                                                                  //
#define I2C_ADDR 0x27                                                                //Дефинира се уникалният за всеки I2C шестнайдесетичен код
#define Rs_pin 0                                                              //
#define Rw_pin 1                                                              //Дефинират се пиновете, управляващи дисплея чрез I2C мнодулът
#define En_pin 2                                                              //
#define BACKLIGHT_PIN 3                                                              //Дефинира се пинът за задната светлина
#define D4_pin 4                                                              //
#define D5_pin 5                                                              //
#define D6_pin 6                                                              //Дефинират се пиновете, управляващи дисплея чрез I2C мнодулът
#define D7_pin 7                                                              //
const int s0 = 8;                                                                   //
const int s1 = 9;                                                                   //
const int s2 = 12;                                                                  //Задават се променливите и се дефинират пиновете за цветовия сензор
const int s3 = 11;                                                                  //  
const int out = 10;                                                                 //   
int red = 0;                                                                              //
int green = 0;                                                                            //Задават се промеливите за интензитетър на червено, зелено и синьо  
int blue = 0;                                                                             //  
int resetPin = 2;                                                               //
int clockPin = 3;                                                               //Дефинират се пиновете на ардуиното, отговарящи за звуковия модул
int dataPin = 4;                                                                //
int busyPin = 5;                                                                //
LiquidCrystal_I2C lcd(I2C_ADDR,En_pin,Rw_pin,Rs_pin,D4_pin,D5_pin,D6_pin,D7_pin);   //Стартира се библиотеката на LCD-то
Wtv020sd16p wtv020sd16p(resetPin,clockPin,dataPin,busyPin);     //Стартира се библиотеката на звуковият модул
byte a[8] = {
B00000,
B00100,
B01010,
B01010,
B01110,
B01010,
B01010,
B00000
};
byte e[8] = {
B00000,
B01110,
B01000,
B01110,
B01000,
B01000,
B01110,
B00000
};
byte o[8] = {
B00000,
B01110,
B01010,
B01010,
B01010,
B01010,
B01110,
B00000
};
byte i[8] = {
B00000,
B10011,
B10011,
B10101,
B10101,
B10101,
B11001,
B00000
};
byte y[8] = {
B00000,
B11000,
B01000,
B01000,
B01110,
B01010,
B01110,
B00000
};
byte ermalyk[8] = {
B00000,
B01000,
B01000,
B01000,
B01110,
B01010,
B01110,
B00000
};
byte ya[8] = {
B00000,
B01110,
B01010,
B01110,
B00110,
B01010,
B10010,
B00000
};
byte j[8] = {
B00000,
B10101,
B10101,
B10101,
B11111,
B10101,
B10101,
B00000
};
byte v[8] = {
B00000,
B01110,
B01010,
B01111,
B01001,
B01001,
B01111,
B00000
};
byte r[8] = {
B00000,
B01110,
B01010,
B01110,
B01000,
B01000,
B01000,
B00000
};
byte l[8] = {
B00000,
B01110,
B01010,
B01010,
B01010,
B01010,
B10010,
B00000
};
byte t[8] = {
B00000,
B01110,
B00100,
B00100,
B00100,
B00100,
B00100,
B00000
};
byte f[8] = {
B00000,
B00100,
B11111,
B10101,
B11111,
B00100,
B00100,
B00000
};
byte k[8] = {
B00000,
B01001,
B01010,
B01100,
B01100,
B01010,
B01001,
B00000
};
byte ch[8] = {
B00000,
B01010,
B01010,
B01110,
B00010,
B00010,
B00010,
B00000
};
byte c[8] = {
B00000,
B01110,
B01000,
B01000,
B01000,
B01000,
B01110,
B00000
};
byte n[8] = {
B00000,
B01010,
B01010,
B01010,
B01110,
B01010,
B01010,
B00000
};
byte z[8] = {
B00000,
B01110,
B00010,
B01110,
B00010,
B00010,
B01110,
B00000
};
void setup()                                                                              
{  
  lcd.begin (20,2);                                                               //Задаве се на дисплея да бъде с 20 хоризонтални и 2 вертикални колони/реда
  Serial.begin(9600);                                                             //Стартира се серийния монитор
  pinMode(s0, OUTPUT);                                                                 //
  pinMode(s1, OUTPUT);                                                                 //
  pinMode(s2, OUTPUT);                                                                 //Задават се пиновете на цветовия сензор като изходи
  pinMode(s3, OUTPUT);                                                                 //
  pinMode(out, INPUT);                                                                 //
  digitalWrite(s0, HIGH);                                                           
  digitalWrite(s1, HIGH);  
  lcd.setBacklightPin(BACKLIGHT_PIN,POSITIVE);                                    //
  lcd.setBacklight(HIGH);                                                         //Задава се на дисплея да включи постоянно задната светлина
  lcd.home ();                                                                    //
  wtv020sd16p.reset();    
 }  
    
void loop() 
{  
  
  color();                                                                            //Извиква се функцията color
  Serial.print("R Intensity:");                                                           //
  Serial.print(red, DEC);                                                                 //
  Serial.print(" G Intensity: ");                                                         //  
  Serial.print(green, DEC);                                                               //Изкарват се стойностите на червено, зелено и синьо
  Serial.print(" B Intensity : ");                                                        //
  Serial.print(blue, DEC);                                                                //

     if (red==20 || red==18 || red==29 && green==28 || green==27 || green==27 && blue==27 || blue==28 || blue==26)      //условният оператор if следи дали интензитетите отговарят на кафяво
  {                                                                                                                     //
   wtv020sd16p.playVoice(2);                                                                                            //ако е така - изпълнява се петия музикален файл - изговарящ кафяво
   lcd.createChar(0, a);
lcd.createChar(1, o);
lcd.createChar(2, ya);
lcd.createChar(3, v);
lcd.createChar(4, f);
lcd.createChar(5, k);
lcd.setCursor(0,0);
lcd.write((byte)5);
lcd.setCursor(1,0);
lcd.write((byte)0);
lcd.setCursor(2,0);
lcd.write((byte)4);
lcd.setCursor(3,0);
lcd.write((byte)2);
lcd.setCursor(4,0);
lcd.write((byte)3);
lcd.setCursor(5,0);
lcd.write((byte)1);                                                                                                 //и показва за 5 секунди на диспля "кафяво"
   delay (3500);                                                                                                        //
   lcd.clear ();                                                                                                        //след това се изчиства
  }
  if (red==8 || red==9 || red==10 && green==7 || green==8 || green==9 && blue==13 || blue==14 || blue==15)              //условният оператор if следи дали интензитетите отговарят на зелно
  {                                                                                                                     //
   wtv020sd16p.playVoice(4);                                                                                            //ако е така - изпълнява се петия музикален файл - изговарящ зелено
   lcd.createChar(0, z);
   lcd.createChar(1, e);
   lcd.createChar(2, l);
   lcd.createChar(3, n);
   lcd.createChar(4, o);
   lcd.setCursor(0,0);
   lcd.write((byte)0);
   lcd.setCursor(1,0);
   lcd.write((byte)1);
   lcd.setCursor(2,0);  
   lcd.write((byte)2);
   lcd.setCursor(3,0);
   lcd.write((byte)1);
   lcd.setCursor(4,0);
   lcd.write((byte)3);
   lcd.setCursor(5,0);
   lcd.write((byte)4);
   delay(3500);
   lcd.clear();                                                                                                  //и показва за 5 секунди на диспля "зелено"                                                                                                       //след това се изчиства
  }
  
   
  
if (red==19 || red==20 || red==21 && green==17 || green==18 || green==19 && blue==10 || blue==11 || blue==12)           //условният оператор if следи дали интензитетите отговарят на синьо
  {                                                                                                                     //
   wtv020sd16p.playVoice(3);                                                                                            //ако е така - изпълнява се петия музикален файл - изговарящ синьо
   lcd.createChar(0, c);
   lcd.createChar(1, i);
   lcd.createChar(2, n);
   lcd.createChar(3, ermalyk);
   lcd.createChar(4, o);
   lcd.setCursor(0,0);
   lcd.write((byte)0);
   lcd.setCursor(1,0);
   lcd.write((byte)1);
   lcd.setCursor(2,0);  
   lcd.write((byte)2);
   lcd.setCursor(3,0);
   lcd.write((byte)3);
   lcd.setCursor(4,0);
   lcd.write((byte)4);
   delay(3500);
   lcd.clear();                                                                                                   //и показва за 5 секунди на диспля "синьо"                                                                                                        //след това се изчиства
  }
  
  

 if (red==6 || red==5 || red==7 && green==20 || green==19 || green==21 && blue==17 || blue==18 || blue==16)             //условният оператор if следи дали интензитетите отговарят на червено
  {                                                                                                                     //
  wtv020sd16p.playVoice(0);                                                                                            //ако е така - изпълнява се петия музикален файл - изговарящ червено
  lcd.createChar(0, ch);
  lcd.createChar(1, e);
  lcd.createChar(2, r);
  lcd.createChar(3, v);
  lcd.createChar(4, n);
  lcd.createChar(5, o);
  lcd.setCursor(0,0);
  lcd.write((byte)0);
  lcd.setCursor(1,0);
  lcd.write((byte)1);
  lcd.setCursor(2,0);
  lcd.write((byte)2);
  lcd.setCursor(3,0);
  lcd.write((byte)3);
  lcd.setCursor(4,0);
  lcd.write((byte)1);
  lcd.setCursor(5,0);
  lcd.write((byte)4);
  lcd.setCursor(6,0);
  lcd.write((byte)5);
  delay(3500);
  lcd.clear();                                                                                                  //и показва за 5 секунди на диспля "червено"                                                                                                       //след това се изчиства
  }

  
 if (red==3 || red==4 || red==5 && green==6 || green==7 || green==8 && blue==9 || blue==10 || blue==11)                 //условният оператор if следи дали интензитетите отговарят на жълто
  {                                                                                                                     //
  wtv020sd16p.playVoice(1);                                                                                            //ако е така - изпълнява се петия музикален файл - изговарящ жълто
  lcd.createChar(0, j);
  lcd.createChar(1, y);
  lcd.createChar(2, l);
  lcd.createChar(3, t);
  lcd.createChar(4, o);
  lcd.setCursor(0,0);
  lcd.write((byte)0);
  lcd.setCursor(1,0);
  lcd.write((byte)1);
  lcd.setCursor(2,0);  
  lcd.write((byte)2);
  lcd.setCursor(3,0);
  lcd.write((byte)3);
  lcd.setCursor(4,0);
  lcd.write((byte)4);
  delay(3500);
  lcd.clear();                                                                                                //и показва за 5 секунди на диспля "жълто"                                                                                                       //след това се изчиства
  }
  
  
  else{                                                                                                                 //
  Serial.println();                                                                                                     //ако не намери цвят покзва само интензитетите на серийният монитор и продължава да търси цвят през 300 милисекунди
  }                                                                                                                     //
  delay(300);                                                                                                           //
 
 }  
    
void color()                                                                                                            //функцията color
{    
  digitalWrite(s2, LOW);                                                                                                //
  digitalWrite(s3, LOW);                                                                                                //
  red = pulseIn(out, digitalRead(out) == HIGH ? LOW : HIGH);                                                            //
  digitalWrite(s3, HIGH);                                                                                               //Тук намира интензитета на червено, зелено и синьо и ги предава на променливите red, green и blue
  blue = pulseIn(out, digitalRead(out) == HIGH ? LOW : HIGH);                                                           //
  digitalWrite(s2, HIGH);                                                                                               //
  green = pulseIn(out, digitalRead(out) == HIGH ? LOW : HIGH);                                                          //
}
