//
// Created by caspar on 6/9/23.
//
#include "EPS.h"

EPS::standard_reply EPS::reset_watchdog(DWire &wire, uint8_t i2c_address) {
    standard_reply reply;


    /* Write command to EPS */
    wire.beginTransmission(i2c_address);
    wire.write(0x00);
    wire.write(0x06);
    wire.write(0x06);
    wire.write(0x00);

    // delay
    delay_ms(25);

    // request 5 bytes of data (i.e) the length of the response
    uint8_t response = wire.requestFrom(i2c_address, 5);

    // if response if 5 bytes long populate reply struct else mark error
    if (response == 5) {
        reply.stid = wire.read();
        reply.ivid = wire.read();
        reply.rc = wire.read();
        reply.bid = wire.read();
        reply.stat = wire.read();
        reply.error = false;
    } else {
        reply.error = true;
    }

    return reply;

}

EPS::standard_reply EPS::no_operation(DWire &wire, uint8_t i2c_address) {
    standard_reply reply;

    /* Write command to EPS */
    wire.beginTransmission(i2c_address);
    wire.write(0x00);
    wire.write(0x06);
    wire.write(0x02);
    wire.write(0x00);

    // delay
    delay_ms(25);

    // request 5 bytes of data (i.e) the length of the response
    uint8_t response = wire.requestFrom(i2c_address, 5);

    // if response if 5 bytes long populate reply struct else mark error
    if (response == 5) {
        reply.stid = wire.read();
        reply.ivid = wire.read();
        reply.rc = wire.read();
        reply.bid = wire.read();
        reply.stat = wire.read();
        reply.error = false;
    } else {
        reply.error = true;
    }

    return reply;

}

EPS::standard_reply EPS::system_reset(DWire &wire, uint8_t i2c_address) {
    standard_reply reply;

    /* Write command to EPS */
    wire.beginTransmission(i2c_address);
    wire.write(0x00);
    wire.write(0x06);
    wire.write(0xAA);
    wire.write(0x00);
    wire.write(0xA6);

    // delay
    delay_ms(25);

    // request 5 bytes of data (i.e) the length of the response
    uint8_t response = wire.requestFrom(i2c_address, 5);

    // if response if 5 bytes long populate reply struct else mark error
    if (response == 5) {
        reply.stid = wire.read();
        reply.ivid = wire.read();
        reply.rc = wire.read();
        reply.bid = wire.read();
        reply.stat = wire.read();
        reply.error = false;
    } else {
        reply.error = true;
    }

    return reply;

}

EPS::standard_reply EPS::cancel_operation(DWire &wire, uint8_t i2c_address) {
    standard_reply reply;

    /* Write command to EPS */
    wire.beginTransmission(i2c_address);
    wire.write(0x00);
    wire.write(0x06);
    wire.write(0x04);
    wire.write(0x00);

    // delay
    delay_ms(25);

    // request 5 bytes of data (i.e) the length of the response
    uint8_t response = wire.requestFrom(i2c_address, 5);

    // if response if 5 bytes long populate reply struct else mark error
    if (response == 5) {
        reply.stid = wire.read();
        reply.ivid = wire.read();
        reply.rc = wire.read();
        reply.bid = wire.read();
        reply.stat = wire.read();
        reply.error = false;
    } else {
        reply.error = true;
    }

    return reply;

}


EPS::standard_reply EPS::switch_to_safety_mode(DWire &wire, uint8_t i2c_address) {
    standard_reply reply;

    /* Write command to EPS */
    wire.beginTransmission(i2c_address);
    wire.write(0x11);
    wire.write(0x06);
    wire.write(0x32);
    wire.write(0x00);

    // delay
    delay_ms(25);

    // request 5 bytes of data (i.e) the length of the response
    uint8_t response = wire.requestFrom(i2c_address, 5);

    // if response if 5 bytes long populate reply struct else mark error
    if (response == 5) {
        reply.stid = wire.read();
        reply.ivid = wire.read();
        reply.rc = wire.read();
        reply.bid = wire.read();
        reply.stat = wire.read();
        reply.error = false;
    } else {
        reply.error = true;
    }

    return reply;
}

