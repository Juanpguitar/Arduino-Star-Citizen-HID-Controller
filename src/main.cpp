#include <Arduino.h>
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define OLED_RESET 4 
Adafruit_SSD1306 display(OLED_RESET);

uint8_t buf[8]= {0};
int Out[] = {2};
int Ins[] = {16, 17, 4, 3, 14, 15, 10, 11, 12};
int SwitchState0 = 0;
int SwitchState1 = 0;
int SwitchState2 = 0;
int SwitchState3 = 0;
int SwitchState4 = 0;
int ButtonState0 = 0;
int ButtonState1 = 0;
int ButtonState2 = 0;
int ButtonState3 = 0;
int LSwitchState0 = 0;
int LSwitchState1 = 0;
int LSwitchState2 = 0;
int LSwitchState3 = 0;
int LSwitchState4 = 0;
int MODESTATE = 0;
int SCMMODESATE = 0;
int NAVMODESATE = 0;

void setup() {
    Serial.begin(9600);
    display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
    display.clearDisplay();

    pinMode(Out[0], OUTPUT);

    for (int i; i < 10; i++)
    {
        pinMode(Ins[i], INPUT);
    }
    digitalWrite(Out[0], HIGH);
}

void releaseKey() {
    buf[0] = 0;
    buf[2] = 0;
    Serial.write(buf, 8);
}
void SystemsReady() {
    display.setTextSize(2);
    display.setTextColor(WHITE);
    display.setCursor(24,0);
    display.setTextWrap(true);
    display.println("SYSTEMS    READY");
    display.display();
}
void FlightReady(){
    display.setTextSize(2);
    display.setTextColor(WHITE);
    display.setCursor(24,0);
    display.setTextWrap(true);
    display.println("FLIGHT    READY");
    display.display();
}
void EnginesOnline(){
    display.setTextSize(2);
    display.setTextColor(WHITE);
    display.setCursor(24,0);
    display.setTextWrap(true);
    display.println("ENGINES   ONLINE");
    display.display();
}
void EnginesOff(){
    display.setTextSize(2);
    display.setTextColor(WHITE);
    display.setCursor(24,0);
    display.setTextWrap(true);
    display.println("ENGINES     OFF");
    display.display();
}
void LandingDown(){
    display.setTextSize(2);
    display.setTextColor(WHITE);
    display.setCursor(24,0);
    display.setTextWrap(true);
    display.println("LANDING   LOWERED");
    display.display();
}
void LandingUp(){
    display.setTextSize(2);
    display.setTextColor(WHITE);
    display.setCursor(24,0);
    display.setTextWrap(true);
    display.println("LANDING   RAISED");
    display.display();
}
void LightsOn(){
    display.setTextSize(2);
    display.setTextColor(WHITE);
    display.setCursor(24,0);
    display.setTextWrap(true);
    display.println("LIGHTS      ON");
    display.display();
}
void LightsOff(){
    display.setTextSize(2);
    display.setTextColor(WHITE);
    display.setCursor(24,0);
    display.setTextWrap(true);
    display.println("LIGHTS     OFF");
    display.display();
}
void VTOLOn(){
    display.setTextSize(2);
    display.setTextColor(WHITE);
    display.setCursor(24,0);
    display.setTextWrap(true);
    display.println("VTOL      ON");
    display.display();
}
void VTOLOff(){
    display.setTextSize(2);
    display.setTextColor(WHITE);
    display.setCursor(24,0);
    display.setTextWrap(true);
    display.println("VTOL      OFF");
    display.display();
}
void CruiseOn(){
    display.setTextSize(2);
    display.setTextColor(WHITE);
    display.setCursor(24,0);
    display.setTextWrap(true);
    display.println("CRUISE    ONLINE");
    display.display();
}
void CruiseOff(){
    display.setTextSize(2);
    display.setTextColor(WHITE);
    display.setCursor(24,0);
    display.setTextWrap(true);
    display.println("CRUISE   OFFNLINE");
    display.display();    
}
void SCMMode(){
    display.setTextSize(2);
    display.setTextColor(WHITE);
    display.setCursor(24,0);
    display.setTextWrap(true);
    display.println("  SCM       SCM");
    display.display();
}
void NAVMode(){
    display.setTextSize(2);
    display.setTextColor(WHITE);
    display.setCursor(24,0);
    display.setTextWrap(true);
    display.println("  NAV       NAV");
    display.display();    
}
void QTM(){
    display.setTextSize(2);
    display.setTextColor(WHITE);
    display.setCursor(24,0);
    display.setTextWrap(true);
    display.println("  NAV       QTM");
    display.display();
}
void SCAN(){
    display.setTextSize(2);
    display.setTextColor(WHITE);
    display.setCursor(24,0);
    display.setTextWrap(true);
    display.println("  NAV     S C A N");
    display.display();
}
void FLIGHT(){
    display.setTextSize(2);
    display.setTextColor(WHITE);
    display.setCursor(24,0);
    display.setTextWrap(true);
    display.println("  NAV     FLIGHT");
    display.display();    
}
void WEAPONS(){
    display.setTextSize(2);
    display.setTextColor(WHITE);
    display.setCursor(24,0);
    display.setTextWrap(true);
    display.println("  SCM     WEAPONS");
    display.display();    
}
void MSL(){
    display.setTextSize(2);
    display.setTextColor(WHITE);
    display.setCursor(24,0);
    display.setTextWrap(true);
    display.println("  SCM     MISSLES");
    display.display();
}
void UTIL(){
    display.setTextSize(2);
    display.setTextColor(WHITE);
    display.setCursor(24,0);
    display.setTextWrap(true);
    display.println("  SCM    UTILITIES");
    display.display();
}
void FLARE(){
    display.setTextSize(2);
    display.setTextColor(WHITE);
    display.setCursor(24,0);
    display.setTextWrap(true);
    display.println("FLARES    FLARES");
    display.display();
}
void NOISE(){
    display.setTextSize(2);
    display.setTextColor(WHITE);
    display.setCursor(24,0);
    display.setTextWrap(true);
    display.println(" NOISE     NOISE");
    display.display();
}

void loop() {
    SwitchState0 = digitalRead(Ins[0]);
    SwitchState1 = digitalRead(Ins[1]);
    SwitchState2 = digitalRead(Ins[2]);
    SwitchState3 = digitalRead(Ins[3]);
    SwitchState4 = digitalRead(Ins[8]);
    ButtonState0 = digitalRead(Ins[4]);
    ButtonState1 = digitalRead(Ins[5]);
    ButtonState2 = digitalRead(Ins[6]);
    ButtonState3 = digitalRead(Ins[7]);

    SystemsReady();

    switch (SwitchState0)
    {
    case 0:
        if (SwitchState0 != LSwitchState0)
        {
            display.clearDisplay();
            buf[2] = 12;
            Serial.write(buf, 8);
            releaseKey();
            digitalWrite(Out[0], HIGH);
            EnginesOff();
            delay(1000);
            display.clearDisplay();
            LSwitchState0 = SwitchState0;
        }
        break;
    case 1:
        if (SwitchState0 != LSwitchState0)
        {
            display.clearDisplay();
            buf[2] = 12;
            Serial.write(buf, 8);
            releaseKey();
            buf[0] = 230;
            digitalWrite(Out[0], LOW);
            buf[2] = 21;
            Serial.write(buf, 8);
            releaseKey();
            FlightReady();
            delay(1000);
            display.clearDisplay();
            EnginesOnline();
            delay(1000);
            display.clearDisplay();
            LSwitchState0 = SwitchState0;
        }
        break;
        }
    switch (SwitchState1)
    {
    case 0:
        if (SwitchState1 != LSwitchState1)
        {
            display.clearDisplay();
            buf[2] = 17;
            Serial.write(buf, 8);
            releaseKey();
            LandingDown();
            delay(1000);
            display.clearDisplay();  
            LSwitchState1 = SwitchState1;
        }
        break;
    case 1:
        if (SwitchState1 != LSwitchState1)
        {
            display.clearDisplay();
            buf[2] = 17;
            Serial.write(buf, 8);
            releaseKey();
            LandingUp();
            delay(1000);
            display.clearDisplay();
            LSwitchState1 = SwitchState1;
        }
        break;
    }
    switch (SwitchState2)
    {
    case 0:
        if (SwitchState2 != LSwitchState2)
        {
            display.clearDisplay();
            buf[2] = 15;
            Serial.write(buf, 8);
            releaseKey();
            LightsOff();
            delay(1000);
            display.clearDisplay();
            LSwitchState2 = SwitchState2;
        }
        break;
    case 1:
        if (SwitchState2 != LSwitchState2)
        {
            display.clearDisplay();
            buf[2] = 15;
            Serial.write(buf, 8);
            releaseKey();
            LightsOn();
            delay(1000);
            display.clearDisplay();  
            LSwitchState2 = SwitchState2;
        }
        break;
    }
    switch (SwitchState3)
    {
    case 0:
        if (SwitchState3 != LSwitchState3)
        {
            display.clearDisplay();
            buf[2] = 14;
            Serial.write(buf, 8);
            releaseKey();
            VTOLOff();
            delay(1000);
            display.clearDisplay();
            LSwitchState3 = SwitchState3;
        }
        break;
    case 1:
        if (SwitchState3 != LSwitchState3)
        {
            display.clearDisplay();
            buf[2] = 14;
            Serial.write(buf, 8);
            releaseKey();
            VTOLOn();
            delay(1000);
            display.clearDisplay();  
            LSwitchState3 = SwitchState3;
        }
        break;
    }
    switch (SwitchState4)
    {
    case 0:
        if (SwitchState4 != LSwitchState4)
        {
            display.clearDisplay();
            buf[0] = 226;
            buf[2] = 6;
            Serial.write(buf, 8);
            releaseKey();
            CruiseOff();
            delay(1000);
            display.clearDisplay();
            LSwitchState4 = SwitchState4;
        }
        break;
    case 1:
        if (SwitchState4 != LSwitchState4)
        {
            display.clearDisplay();
            buf[0] = 226;
            buf[2] = 6;
            Serial.write(buf, 8);
            releaseKey();
            CruiseOn();
            delay(1000);
            display.clearDisplay();
            LSwitchState4 = SwitchState4;
        }
        break;
    }
    switch (ButtonState0)
    {
    case 1:
        display.clearDisplay();
        buf[2] = 5;
        Serial.write(buf, 8);
        releaseKey();
        if (MODESTATE == 0)
        {
            NAVMode();
            delay(1000);
            display.clearDisplay();
            QTM();
            delay(1000);
            display.clearDisplay();
            MODESTATE = 1;
            NAVMODESATE = 0;
        }
        else
        {
            SCMMode();
            delay(1000);
            display.clearDisplay();
            WEAPONS();
            delay(1000);
            display.clearDisplay();
            MODESTATE = 0;
            SCMMODESATE = 0;
        }
    break;
    }
    switch (ButtonState1)
    {
    case 1:
        display.clearDisplay();
        buf[2] = 49;
        Serial.write(buf, 8);
        releaseKey();
        if (MODESTATE == 0)
        {
            switch (SCMMODESATE)
            {
            case 0:
                MSL();
                delay(1000);
                display.clearDisplay();
                SCMMODESATE = 1;
            break;
            case 1:
                UTIL();
                delay(1000);
                display.clearDisplay();
                SCMMODESATE = 2;
            break;
            case 2:
                WEAPONS();
                delay(1000);
                display.clearDisplay();
                SCMMODESATE = 0;
            break;
            }
        }
        else
        {
            switch (NAVMODESATE)
            {
            case 0:
                SCAN();
                delay(1000);
                display.clearDisplay();
                NAVMODESATE = 1;
            break;
            case 1:
                FLIGHT();
                delay(1000);
                display.clearDisplay();
                NAVMODESATE = 2;
            break;
            case 2:
                QTM();
                delay(1000);
                display.clearDisplay();
                NAVMODESATE = 0;
            break;
            }
        }
        
    break;
    }
     switch (ButtonState2)
    {
    case 1:
        display.clearDisplay();
        buf[2] = 11;
        Serial.write(buf, 8);
        releaseKey();
        FLARE();
        delay(500);
        display.clearDisplay();    
    break;
    }
    switch (ButtonState3)
    {
    case 1:
        display.clearDisplay();
        buf[2] = 13; 
        Serial.write(buf, 8);
        releaseKey();
        NOISE();
        delay(500);
        display.clearDisplay();
    break;
    }
}
