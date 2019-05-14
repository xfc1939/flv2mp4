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

void Utils::write64(std::string &str, int64_t value) 
{
	Utils::write32(str, (value & 0xffffffff00000000) >> 32);
	Utils::write32(str, (value & 0x00000000ffffffff) >> 32);
}

void Utils::writeU8(std::string &str, uint8_t value)
{
	str.push_back(value);
}
void Utils::writeU16(std::string &str, uint16_t value)
{
	Utils::writeU8(str, (value & 0xff00) >> 8);
	Utils::writeU8(str, (value & 0x00ff));
}
void Utils::writeU32(std::string &str, uint32_t value)
{
	Utils::writeU16(str, (value & 0xffff0000) >> 16);
	Utils::writeU16(str, (value & 0x0000ffff));
}
void Utils::writeU64(std::string &str, uint64_t value)
{
	Utils::writeU32(str, (value & 0xffffffff00000000) >> 32);
	Utils::writeU32(str, (value & 0x00000000ffffffff) >> 32);
}