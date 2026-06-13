/*
 * SimpleSender.cpp
 *
 *  Demonstrates sending IR codes in standard format with address and command
 *  An extended example for sending can be found as SendDemo.
 *  Sending IR codes using several pins for sending is implements in the MultipleSendPins example.
 *
 *  Copyright (C) 2020-2026  Armin Joachimsmeyer
 *  armin.joachimsmeyer@gmail.com
 *
 *  This file is part of Arduino-IRremote https://github.com/Arduino-IRremote/Arduino-IRremote.
 *
 *  MIT License
 */
#include <Arduino.h>

#if !defined(ARDUINO_ESP32C3_DEV) // This is due to a bug in RISC-V compiler, which requires unused function sections :-(.
#define DISABLE_CODE_FOR_RECEIVER // Disables static receiver code like receive timer ISR handler and static IRReceiver and irparams data. Saves 450 bytes program memory and 269 bytes RAM if receiving functions are not required.
#endif
//#define SEND_PWM_BY_TIMER         // Disable carrier PWM generation in software and use (restricted) hardware PWM.
//#define USE_NO_SEND_PWM           // Use no carrier PWM, just simulate an active low receiver signal. Overrides SEND_PWM_BY_TIMER definition
//#define NO_LED_FEEDBACK_CODE      // Saves 216 bytes program memory

#include "PinDefinitionsAndMore.h" // Define macros for input and output pin etc. Sets FLASHEND and RAMSIZE and evaluates value of SEND_PWM_BY_TIMER.
#include <IRremote.hpp> // include the library

void setup() {
    pinMode(LED_BUILTIN, OUTPUT);

    Serial.begin(115200);

    // Just to know which program is running on my Arduino
    Serial.println(F("START " __FILE__ " from " __DATE__ "\r\nUsing library version " VERSION_IRREMOTE));
    Serial.print(F("Send IR signals at pin "));
    Serial.println(IR_SEND_PIN);

    delay(5000);
    IrSender.sendPulseDistanceWidth(38, 3050, 2900, 650, 1600, 650, 500, 0x69BB, 16, PROTOCOL_IS_LSB_FIRST, 200, 3);    // start
    delay(30000);
    IrSender.sendPulseDistanceWidth(38, 3050, 2900, 650, 1600, 650, 500, 0x69BB, 16, PROTOCOL_IS_LSB_FIRST, 200, 3);    // pause
    delay(10000);

    IrSender.sendPulseDistanceWidth(38, 3000, 3000, 550, 1700, 550, 550, 0x78BB, 16, PROTOCOL_IS_LSB_FIRST, 200, 3);    // clean borders
    delay(5000);
    IrSender.sendPulseDistanceWidth(38, 3000, 3000, 600, 1650, 600, 550, 0xF0BB, 16, PROTOCOL_IS_LSB_FIRST, 200, 3);    // toggle suction power
    delay(5000);
    IrSender.sendPulseDistanceWidth(38, 3000, 3000, 600, 1650, 600, 550, 0xF0BB, 16, PROTOCOL_IS_LSB_FIRST, 200, 3);    // toggle suction power
    delay(30000);

    IrSender.sendPulseDistanceWidth(38, 3000, 3000, 550, 1700, 550, 550, 0x4BBB, 16, PROTOCOL_IS_LSB_FIRST, 200, 3);    // SPOT cleaning
    delay(30000);
    IrSender.sendPulseDistanceWidth(38, 3050, 2900, 650, 1600, 650, 500, 0x69BB, 16, PROTOCOL_IS_LSB_FIRST, 200, 3);    // pause
    delay(5000);

    IrSender.sendPulseDistanceWidth(38, 3050, 2950, 600, 1650, 600, 550, 0xC3BB, 16, PROTOCOL_IS_LSB_FIRST, 200, 3);    // go back home


    /*
     * No IR library setup required :-)
     * Default is to use IR_SEND_PIN -which is defined in PinDefinitionsAndMore.h- as send pin
     * and use feedback LED at default feedback LED pin if not disabled by #define NO_LED_SEND_FEEDBACK_CODE
     */
}

void loop() {}


