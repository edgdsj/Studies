/*
 * mcp2515_hal.h
 *
 *  Created on: 25 de out de 2022
 *      Author: Edmilson Gonçalves de Souza Junior
 */

#ifndef MCP2515_MCP2515_HAL_H_
#define MCP2515_MCP2515_HAL_H_

#define TXB0CTRL		0x30
#define TXB0SIDH		0x31
#define TXB0SIDL		0x32

#define TXB1CTRL		0x40
#define TXB2CTRL		0x50
#define RXB0CTRL		0x60
#define RXB1CTRL		0x70

#define RXB1SIDL		0x71

#define RXB0Dm			0x66 // ~ 0x6d
#define RXB1Dm			0x76 // ~ 0x7d


//Instructions
#define RESET			0b11000000
#define READ			0b00000011
#define READRXB			0b10010000
#define WRITE			0b00000010
#define LOADTXB			0b01000000
#define RTS				0b10000000
#define READSTATUS		0b10100000
#define RXSTATUS		0b10110000
#define BITMODIFY		0b00000101



#endif /* MCP2515_MCP2515_HAL_H_ */
