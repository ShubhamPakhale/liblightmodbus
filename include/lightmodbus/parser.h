/*
	liblightmodbus - a lightweight, multiplatform Modbus library
	Copyright (C) 2016	Jacek Wieczorek <mrjjot@gmail.com>

	This file is part of liblightmodbus.

	Liblightmodbus is free software: you can redistribute it and/or modify
	it under the terms of the GNU General Public License as published by
	the Free Software Foundation, either version 3 of the License, or
	(at your option) any later version.

	Liblightmodbus is distributed in the hope that it will be useful,
	but WITHOUT ANY WARRANTY; without even the implied warranty of
	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
	GNU General Public License for more details.

	You should have received a copy of the GNU General Public License
	along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef LIGHTMODBUS_PARSER_H
#define LIGHTMODBUS_PARSER_H

#include <inttypes.h>

union ModbusParser
{
	uint8_t frame[256];

	struct __attribute__( ( __packed__ ) )
	{
		uint8_t address;
		uint8_t function;
	} base; //Base shared bytes, which have always same meaning

	struct __attribute__( ( __packed__ ) )
	{
		uint8_t address;
		uint8_t function;
		uint8_t exceptionCode;
		uint16_t crc;
	} exception;

	struct __attribute__( ( __packed__ ) )
	{
		uint8_t address;
		uint8_t function;
		uint16_t firstCoil;
		uint16_t coilCount;
		uint16_t crc;
	} request01; //Read multiple coils

	struct __attribute__( ( __packed__ ) )
	{
		uint8_t address;
		uint8_t function;
		uint8_t byteCount;
		uint8_t values[32];
		uint16_t crc;
	} response01; //Read multiple coils - response

	struct __attribute__( ( __packed__ ) )
	{
		uint8_t address;
		uint8_t function;
		uint16_t firstInput;
		uint16_t inputCount;
		uint16_t crc;
	} request02; //Read multiple discrete inputs

	struct __attribute__( ( __packed__ ) )
	{
		uint8_t address;
		uint8_t function;
		uint8_t byteCount;
		uint8_t values[32];
		uint16_t crc;
	} response02; //Read multiple discrete inputs - response

	struct __attribute__( ( __packed__ ) )
	{
		uint8_t address;
		uint8_t function;
		uint16_t firstRegister;
		uint16_t registerCount;
		uint16_t crc;
	} request03; //Read multiple holding registers

	struct __attribute__( ( __packed__ ) )
	{
		uint8_t address;
		uint8_t function;
		uint8_t byteCount;
		uint16_t values[128];
		uint16_t crc;
	} response03; //Read multiple holding registers - response

	struct __attribute__( ( __packed__ ) )
	{
		uint8_t address;
		uint8_t function;
		uint16_t firstRegister;
		uint16_t registerCount;
		uint16_t crc;
	} request04; //Read multiple input registers

	struct __attribute__( ( __packed__ ) )
	{
		uint8_t address;
		uint8_t function;
		uint8_t byteCount;
		uint16_t values[128];
		uint16_t crc;
	} response04; //Read multiple input registers - response

	struct __attribute__( ( __packed__ ) )
	{
		uint8_t address;
		uint8_t function;
		uint16_t coil;
		uint16_t value;
		uint16_t crc;
	} request05; //Write single coil

	struct __attribute__( ( __packed__ ) )
	{
		uint8_t address;
		uint8_t function;
		uint16_t coil;
		uint16_t value;
		uint16_t crc;
	} response05; //Write single coil - response

	struct __attribute__( ( __packed__ ) )
	{
		uint8_t address;
		uint8_t function;
		uint16_t reg;
		uint16_t value;
		uint16_t crc;
	} request06; //Write single holding register

	struct __attribute__( ( __packed__ ) )
	{
		uint8_t address;
		uint8_t function;
		uint16_t reg;
		uint16_t value;
		uint16_t crc;
	} response06; //Write single holding register

	struct __attribute__( ( __packed__ ) )
	{
		uint8_t address;
		uint8_t function;
		uint16_t firstCoil;
		uint16_t coilCount;
		uint8_t byteCount;
		uint8_t values[32];
		uint16_t crc;
	} request15; //Write multiple coils

	struct __attribute__( ( __packed__ ) )
	{
		uint8_t address;
		uint8_t function;
		uint16_t firstCoil;
		uint16_t coilCount;
		uint16_t crc;
	} response15; //Write multiple coils - response

	struct __attribute__( ( __packed__ ) )
	{
		uint8_t address;
		uint8_t function;
		uint16_t firstRegister;
		uint16_t registerCount;
		uint8_t byteCount;
		uint16_t values[128];
		uint16_t crc;
	} request16; //Write multiple holding registers

	struct __attribute__( ( __packed__ ) )
	{
		uint8_t address;
		uint8_t function;
		uint16_t firstRegister;
		uint16_t registerCount;
		uint16_t crc;
	} response16; //Write multiple holding registers
};

#endif