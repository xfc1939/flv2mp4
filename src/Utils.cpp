#include "StdAfx.h"
#include "Utils.h"
#include <stdio.h>

Utils::Utils(void)
{
}


Utils::~Utils(void)
{
}

void Utils::write8(std::string &str, int8_t value) 
{
	str.push_back(value);
	printf("%d\t", str[str.size() - 1]);
}

void Utils::write16(std::string &str, int16_t value)
{
	Utils::write8(str, (value & 0xff00) >> 8);
	Utils::write8(str, (value & 0x00ff));
}

void Utils::write32(std::string &str, int32_t value) 
{
	Utils::write16(str, (value & 0xffff0000) >> 16);
	Utils::write16(str, (value & 0x0000ffff));
}