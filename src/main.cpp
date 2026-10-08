#include <Arduino.h>
#include "LED.h"
#include <OneButton.h>

LED led(LED_PIN, LED_ACT);

void btnPush();
void btnDoubleClick();
OneButton button(BTN_PIN, !BTN_ACT);

void setup()
{
    Serial.begin(115200);
    led.off();
    
    // Nhấn đơn: Bật / Tắt
    button.attachClick(btnPush);
    
    // Thay đổi theo đề bài: Nhấp đúp (Double click) để nhấp nháy LED
    button.attachDoubleClick(btnDoubleClick);
}

void loop()
{
    led.loop();
    button.tick();
}

void btnPush()
{
    led.flip();
    Serial.println("Single click: Flip LED");
}

void btnDoubleClick()
{
    led.blink(200);
    Serial.println("Double click: Blink LED 200ms");
}