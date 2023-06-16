/*
 * Copyright (c) 2016 by Stefan van der Linden <spvdlinden@gmail.com>
 *
 * DWire: a library to provide full hardware-driven I2C functionality
 * to the TI MSP432 family of microcontrollers. It is possible to use
 * this library in Energia (the Arduino port for MSP microcontrollers)
 * or in other toolchains.
 *
 * This file is free software; you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License 
 * version 3, both as published by the Free Software Foundation.
 *
 */

#ifndef DWIRE_DWIRE_H_
#define DWIRE_DWIRE_H_

// Similar for the roles
#define BUS_ROLE_MASTER 0
#define BUS_ROLE_SLAVE 1

// define I2C speed
#define STANDARD 0
#define FAST     1
#define FASTPLUS 2

// Default buffer size in bytes
#define TX_BUFFER_SIZE 256
#define RX_BUFFER_SIZE 256

#define TIMEOUTLIMIT 0xFFFF

#include <driverlib.h>

/* Device specific includes */
#include <inc/pins.h>

class DWire 
{
private:

    uint32_t delayCycles;
	/* TX buffer pointers */
	uint8_t * pTxBuffer;
    volatile uint8_t * pTxBufferIndex;
    volatile uint8_t * pTxBufferSize;

	/* RX buffer pointers */
    uint8_t * pRxBuffer;
    uint8_t * pRxBufferIndex;
    uint8_t * pRxBufferSize;

    volatile bool requestDone;
    volatile bool sendStop;
    volatile bool gotNAK;

	/* MSP specific modules */
    uint_fast32_t module;
    uint32_t intModule;
    uint_fast8_t modulePort;
    uint_fast16_t modulePins;
    uint_fast16_t moduleSCL;
    
    /* Internal states */
    eUSCI_I2C_MasterConfig config;
    uint8_t mode;
    uint8_t slaveAddress;
    uint8_t busRole;
    uint32_t timeout;
    
    void (*user_onRequest)( void );
    void (*user_onReceive)( uint8_t );

    void _initMain( void );
    void _initMaster( const eUSCI_I2C_MasterConfig * );
    void _initSlave( void );
    void _setSlaveAddress( uint_fast8_t );
    void _I2CDelay( void );
    void _resetBus( void );

    friend void EUSCIB0_IRQHandler_I2C( void );
    friend void EUSCIB1_IRQHandler_I2C( void );
    friend void EUSCIB2_IRQHandler_I2C( void );
    friend void EUSCIB3_IRQHandler_I2C( void );

public:
    /* Constructors */
    DWire( uint8_t );
    DWire( );
    ~DWire( void );

    /* MASTER specific */
    void begin( );
    void setStandardMode( );
    void setFastMode( );
    void setFastModePlus( );

    void beginTransmission( uint_fast8_t );
    void write( uint_fast8_t );
    bool endTransmission( void );
    bool endTransmission( bool );

    uint8_t requestFrom( uint_fast8_t, uint_fast8_t );

    /* SLAVE specific */
    void begin( uint8_t );

    uint8_t read( void );

    void onRequest( void (*)( void ) );
    void onReceive( void (*)( uint8_t ) );

    /* Miscellaneous */
    bool isMaster( void );

    /* Internal */
    void _handleReceive( uint8_t * );
    void _handleRequestSlave( void );
    void _finishRequest( bool );
    bool _isSendStop( ) { return sendStop; }
};

#endif /* DWIRE_DWIRE_H_ */
