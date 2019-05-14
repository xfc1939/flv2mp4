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
	static void write64(std::string &str, int64_t value);

	static void writeU8(std::string &str, uint8_t value);
	static void writeU16(std::string &str, uint16_t value);
	static void writeU32(std::string &str, uint32_t value);
	static void writeU64(std::string &str, uint64_t value);
};

