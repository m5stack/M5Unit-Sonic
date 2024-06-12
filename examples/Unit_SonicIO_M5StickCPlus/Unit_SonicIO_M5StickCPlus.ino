/*
*******************************************************************************
* Copyright (c) 2021 by M5Stack
*                  Equipped with M5StickCPlus sample source code
*                          配套  M5StickCPlus 示例源代码
* Visit for more information:https://docs.m5stack.com/en/unit/sonic.io
* 获取更多资料请访问：https://docs.m5stack.com/zh_CN/unit/sonic.io
*
* Product: Ultrasonic.  超声波测距传感器 IO版本
* Date: 2022/7/21
*******************************************************************************
  Please connect to Port A,Display the distance measured by ultrasonic
  请连接端口B,显示超声波测量的距离
*/

#include <M5StickCPlus.h>
#include <Unit_Sonic.h>

SONIC_IO sensor;

void setup() {
    M5.begin();             // Init M5StickCPlus.  初始化M5StickCPlus
    M5.Lcd.setRotation(3);  // Rotating display.  旋转显示屏
    M5.Lcd.setCursor(60, 0, 4);
    // Set the cursor at (0,0) and set the font to a 4
    // point font. 将光标设置在(0,0)处,且设置字体为4号字体
    M5.Lcd.print("Ultrasonic\nDistance:");
    sensor.begin(32, 33);
}

int point      = 0;
int last_point = 0;

void loop() {
    static float newvalue = 0;
    newvalue              = sensor.getDistance();
    if ((newvalue < 4000) && (newvalue > 20)) {
        M5.Lcd.setCursor(0, 27);
        M5.Lcd.printf("%.2fmm", newvalue);
    }
    delay(100);
}
