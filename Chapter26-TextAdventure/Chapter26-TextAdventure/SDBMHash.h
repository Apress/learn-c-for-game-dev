#pragma once

#include "FixedTypes.h"
#include <string>
#include <iostream>

template <int32_t stringLength>
struct SDBMCalculator
{
	static inline int32_t Calculate(const char8_t* const stringToHash, int32_t& value)
	{
		int32_t character = SDBMCalculator<stringLength - 1>::Calculate(stringToHash, value);
		value = character + (value << 6) + (value << 16) - value;
		return stringToHash[stringLength - 1];
	}

	static inline int32_t CalculateValue(const char8_t* const stringToHash)
	{
		int32_t value = 0;
		int32_t character = SDBMCalculator<stringLength>::Calculate(stringToHash, value);
		value = character + (value << 6) + (value << 16) - value;
		return value;
	}
};

template <>
struct SDBMCalculator<1>
{
	static inline int32_t Calculate(const char8_t* const stringToHash, int32_t& value)
	{
		return stringToHash[0];
	}
};


inline int32_t SDBMHash(const std::string& key)
{
	int32_t result = 0;

	for (uint32_t i = 0; i < key.length(); ++i)
	{
		uint32_t c = key[i];
		result = c + (result << 6) + (result << 16) - result;
	}

	return result;
}

#ifndef constexpr
#define constexpr const
#else
constexpr inline uint32_t constexpr_strlen(const char8_t* const str)
{
	return str[0] != '\0'
		? constexpr_strlen(str + 1) + 1
		: 0;
}
#endif