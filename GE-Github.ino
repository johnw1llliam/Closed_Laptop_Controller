#include <SPFD5408_Adafruit_GFX.h>  // Core graphics library  
#include <SPFD5408_Adafruit_TFTLCD.h> // Hardware-specific library  
#include <SPFD5408_TouchScreen.h>  
#include <Keyboard.h>
// Pin assignments for the TFT touch screen  
#define YP  A1  
#define XM  A2  
#define YM  7  
#define XP  6  
// Calibrated values for the TFT touch screen   
#define TS_MINX  178  
#define TS_MINY  75  
#define TS_MAXX  931  
#define TS_MAXY  895  
// Instantiate the ts object  
TouchScreen ts = TouchScreen(XP, YP, XM, YM, 300);  
#define LCD_RD  A0  
#define LCD_WR  A1  
#define LCD_CD  A2  
#define LCD_CS  A3  
#define LCD_RESET A4  
// Instantiate the tft object  
Adafruit_TFTLCD tft(LCD_CS, LCD_CD, LCD_WR, LCD_RD, LCD_RESET);  
// Assign human-readable names to some common 16-bit color values:  
#define BLACK  0x0000  
#define BLUE  0x001F  
#define RED   0xF800
#define GREEN  0x07E0  
#define CYAN  0x07FF  
#define MAGENTA 0xF81F  
#define YELLOW 0xFFE0  
#define WHITE  0xFFFF  
#define BOXSIZE   40  
#define PENRADIUS  3  
#define MINPRESSURE 1
#define MAXPRESSURE 10000  
#define LED_PIN   A5  

void setup() {  
  pinMode(LED_PIN, OUTPUT);  
  digitalWrite(LED_PIN, LOW);  
  Serial.begin(9600);  
  tft.reset();  
  tft.begin(0x9341);  
  tft.setRotation(1);  
  tft.setTextColor(GREEN);  
  tft.setTextSize(2);  
  tft.fillScreen(BLACK);     

  tft.setCursor(5,12);
  tft.println("===========MENU===========");
  tft.setCursor(5, 67);
  tft.println("> Function 1");
  tft.setCursor(165, 67);
  tft.println("> Function 2");
  tft.setCursor(5, 132);
  tft.println("> Function 3");
  tft.setCursor(165, 132);
  tft.println("> Function 4");
  tft.setCursor(5, 197);
  tft.println("> Function 5");
  tft.setCursor(165, 197);
  tft.println("> Function 6");

  pinMode(2, INPUT);
  digitalWrite(2, HIGH);
  Keyboard.begin();
}  

void loop() { 
  int touch = 0;
  // Get the touch points  
  TSPoint p = ts.getPoint();  
  // Restore the mode  
  pinMode(XM, OUTPUT);  
  pinMode(YP, OUTPUT);  
  if (p.z > MINPRESSURE && p.z < MAXPRESSURE) {  
    p.x = map(p.x, TS_MINX, TS_MAXX, 0, tft.width());  
    p.y = map(p.y, TS_MINY, TS_MAXY, 0, tft.height());
    // Touch area for box 1  
    if (p.x > 195 && p.x < 285) {  
      if (p.y > 0 && p.y < 160) {  
        touch = 1;  
      }  
    } 
    // Touch area for box 2  
    if (p.x > 195 && p.x < 260) {  
      if (p.y > 160 && p.y < 320) {  
        touch = 2;  
      }  
    }    
    // // Touch area for box 3
    if (p.x > 110 && p.x < 195) {  
      if (p.y > 0 && p.y < 160) {  
        touch = 3;  
      }  
    }  
    // // Touch area for box 4
    if (p.x > 110 && p.x < 195) {  
      if (p.y > 160 && p.y < 320) {  
        touch = 4;  
      }  
    }
    // Touch area for box 5
    if (p.x > 25 && p.x < 110) {  
      if (p.y > 0 && p.y < 160) {  
        touch = 5;  
      }  
    }
    // Touch area for box 6
    if (p.x > 25 && p.x < 110) {  
      if (p.y > 160 && p.y < 320) {  
        touch = 6;  
      }  
    } 
  }
    // Process the touch in box 1  
  if (touch == 1) {  
    digitalWrite(LED_PIN, HIGH);  
    // Keyboard press something here
    delay(100);
    Keyboard.releaseAll(); 
    delay(100);  
  }  
  // Process the touch in box 2  
  if (touch == 2) {  
    digitalWrite(LED_PIN, HIGH);  
    // Keyboard press something here
    delay(100);
    Keyboard.releaseAll(); 
    delay(100);  
  }  
  // Process the touch in box 3  
  if (touch == 3) {  
    digitalWrite(LED_PIN, HIGH);  
    // Keyboard press something here
    delay(100);
    Keyboard.releaseAll(); 
    delay(100);  
  }  
  // Process the touch in box 4
  if (touch == 4) {  
    digitalWrite(LED_PIN, HIGH);  
    // Keyboard press something here
    delay(100);
    Keyboard.releaseAll(); 
    delay(100);  
  }
  if (touch == 5) {  
    digitalWrite(LED_PIN, HIGH);  
    // Keyboard press something here
    delay(100);
    Keyboard.releaseAll(); 
    delay(100);  
  }
  if (touch == 6) {  
    digitalWrite(LED_PIN, HIGH);  
    // Keyboard press something here
    delay(100);
    Keyboard.releaseAll(); 
    delay(100);  
  }
} 
