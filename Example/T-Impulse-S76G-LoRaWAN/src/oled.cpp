
#include "oled.h"
#include "config.h"

U8G2_SSD1306_64X32_1F_F_HW_I2C *u8g2 = nullptr;

void oled_init(void)
{
    u8g2 = new U8G2_SSD1306_64X32_1F_F_HW_I2C(U8G2_R0, OLED_RESET, IICSCL, IICSDA);

    u8g2->begin();
    u8g2->setContrast(0x00);
    u8g2->clearBuffer();
    u8g2->setFontMode(1); // Transparent
    u8g2->setFontDirection(0);
    u8g2->setFont(u8g2_font_fub14_tf);
    u8g2->drawStr(2, 18, "LilyGo");
    u8g2->sendBuffer();
    for (int i = 0; i < 0xFF; i++)
    {
        u8g2->setContrast(i);
        u8g2->drawFrame(2, 25, 60, 6);
        u8g2->drawBox(3, 26, (uint8_t)(0.231 * i), 5);
        u8g2->sendBuffer();
    }

    u8g2->setFont(u8g2_font_IPAandRUSLCD_tr);
}