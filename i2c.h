/* 
 * File:   i2c.h
 * Author: Jan Kubovy <jan@kubovy.eu>
 */

#ifndef I2C_H
#define	I2C_H

#ifdef	__cplusplus
extern "C" {
#endif

#include <stdbool.h>
#include <stdint.h>
#include <stdarg.h>

// Configuration which SPP module to use.
#ifndef I2C_SSPSTAT
#define I2C_SSPSTAT SSP1STAT
#define I2C_SSPCON2 SSP1CON2
#define I2C_BUFFER SSP1BUF
#endif

// Operation modes
#define I2C_MODE_WRITE 0x00
#define I2C_MODE_READ 0x01
    
// Acknowledgments
#define I2C_ACK 0x01
#define I2C_NACK 0x00

/**
 *  Initiates the START condition on SDA and SCL pins.
 */
void I2C_start(void);

/**
 *  Initiates the REPEATED START condition on SDA and SCL pins.
 */
void I2C_repeated_start(void);

/**
 *  Initiate the STOP condition on SDA and SCL pins
 */
void I2C_stop(void);

/**
 * Select a device by its address and the communication mode.
 * 
 * The address will be shifted about 1 bit to the right and the mode bit will
 * be inserted on the last position. Therefore only first 7 bits of the 8 bit
 * address will be effectively used.
 * 
 * @param address 7bit address, the 8th bit is ignored.
 * @param mode One of: <code>I2C_MODE_WRITE</code>, <code>I2C_MODE_READ</code>.
 */
void I2C_select(uint8_t address, bool mode);

/**
 * Writes 8 bits to the I2C bus.
 *
 * Following the communication start (e.g. <code>I2C_start</code>) and device
 * selection (<code>I2C_select</code>) this function can be used to writes 
 * 8 bits to the I2C bus.
 *
 * @param data Data to be written.
 */
void I2C_write(uint8_t data);

/**
 * Reads 8 bits from the I2C bus.
 *
 * Following the communication start (e.g. <code>I2C_start</code>) and device
 * selection (<code>I2C_select</code>) this function can be used to read 
 * 8 bits from the I2C bus.
 *
 * @param ack <code>I2C_ACK</code>, <code>I2C_NACK</code>.
 * @return 8bits read from the I2C bus.
 */
uint8_t I2C_read(uint8_t ack);

/**
 * Send 8bits to defined address.
 * 
 *  This is a shorthand to start communication with <code>address</code> in
 *  <code>I2C_MODE_WRITE</code> mode and send <code>data</code>.
 * 
 * @param address 7bit address, the 8th bit is ignored.
 * @param data Data to be written.
 */
void I2C_send(uint8_t address, uint8_t data);

/**
 *  Send N times 8bits to defined address.
 * 
 *  This is a shorthand to start communication with <code>address</code> in
 *  <code>I2C_MODE_WRITE</code> mode and send <code>data</code>.
 * 
 * @param address 7bit address, the 8th bit is ignored.
 * @param n Number of bytes to be send (number of vararg parameters)
 * @param ... Data to be written (n times <code>uint8_t</code>).
 */
void I2C_sendN(uint8_t address, uint8_t n, ...);

/**
 *  Receives 8bits from defined address.
 * 
 *  This is a shorthand to start communication with <code>address</code> in
 *  <code>I2C_MODE_WRITE</code> mode and write <code>reg</code> to tell the
 *  other device what data it should send back then switching to
 *  <code>I2C_MODE_READ</code> and read the response.
 * 
 * @param address 7bit address, the 8th bit is ignored.
 * @param reg Information for the other device what data should be send back.
 * @return 8bits response.
 */
uint8_t I2C_receive(uint8_t address, uint8_t reg);

#ifdef	__cplusplus
}
#endif

#endif	/* I2C_H */