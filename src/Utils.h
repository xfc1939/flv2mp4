#pragma once
#include <stdint.h>
#include <string>
class Utils
{
public:
	Utils(void);
	~Utils(void);
public:
	static void write8(std::string &str, int8_t value);
	static void write16(std::string &str, int16_t value);
	static void write32(std::string &str, int32_t value);
};

