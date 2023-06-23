//
// Created by caspar on 6/9/23.
//
// Defines all EPS commands

#ifndef EPS_CONVERSION_EPS_H
#define EPS_CONVERSION_EPS_H

// PDU i2c addresses
//TODO: store them better
#define PDU_1_ADDR 0x20
#define PDU_2_ADDR 0x21
#define PDU_3_ADDR 0x22
#define PDU_4_ADDR 0x23
#define PDU_5_ADDR 0x24
#define PDU_6_ADDR 0x25
#define PDU_7_ADDR 0x26
#define PDU_8_ADDR 0x27

//PBU addresses
#define PBU_1_ADDR 0x28
#define PBU_2_ADDR 0x29
#define PBU_3_ADDR 0x2A
#define PBU_4_ADDR 0x2B

//PCU addresses
#define PCU_1_ADDR 0x2C
#define PCU_2_ADDR 0x2D
#define PCU_3_ADDR 0x2E
#define PCU_4_ADDR 0x2F

#define

#include "DWire.h"
#include "delay.h"

class EPS {
public:
    // standard reply
    struct standard_reply {
        uint8_t stid;
        uint8_t ivid;
        uint8_t rc;
        uint8_t bid;
        uint8_t stat;
        uint8_t error;
    };

    // system status reply
    struct system_status_reply : standard_reply {
        system_status_reply(
            uint8_t stid,
            uint8_t ivid,
            uint8_t rc,
            uint8_t bid,
            uint8_t stat,
            uint8_t mode,
            uint8_t conf,
            uint8_t reset_cause,
            uint32_t uptime,
            uint16_t system_error,
            uint16_t rc_cnt_pwron,
            uint16_t rc_cnt_wdg,
            uint16_t rc_cnt_cmd,
            uint16_t rc_cnt_mcu,
            uint16_t rc_cnt_emlopo,
            uint16_t prevcmd_elapsed,
            uint8_t internal_use,
            uint8_t error
        ) : standard_reply(stid, ivid, rc, bid, stat, error),
            mode(mode),
            conf(conf),
            reset_cause(reset_cause),
            uptime(uptime),
            system_error(system_error),
            rc_cnt_pwron(rc_cnt_pwron),
            rc_cnt_wdg(rc_cnt_wdg),
            rc_cnt_cmd(rc_cnt_cmd),
            rc_cnt_mcu(rc_cnt_mcu),
            rc_cnt_emlopo(rc_cnt_emlopo),
            prevcmd_elapsed(prevcmd_elapsed),
            internal_use(internal_use)
        { }
    };

    static standard_reply reset_watchdog(DWire &wire, uint8_t i2c_address);
    static standard_reply no_operation(DWire &wire, uint8_t i2c_address);
    static standard_reply system_reset(DWire &wire, uint8_t i2c_address);
    static standard_reply cancel_operation(DWire &wire, uint8_t i2c_address);
    static system_status_reply get_system_status(DWire &wire, uint8_t i2c_address);
};

#endif //EPS_CONVERSION_EPS_H
