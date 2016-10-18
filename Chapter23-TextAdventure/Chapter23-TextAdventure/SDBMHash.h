#pragma once

#include <string>
#include <iostream>

template <int stringLength>
struct SDBMCalculator
{
	static inline int Calculate(const char* const stringToHash, int& value)
	{
		int character = SDBMCalculator<stringLength - 1>::Calculate(stringToHash, value);
		value = character + (value << 6) + (value << 16) - value;
		return stringToHash[stringLength - 1];
	}

	static inline int CalculateValue(const char* const stringToHash)
	{
		int value = 0;
		int character = SDBMCalculator<stringLength>::Calculate(stringToHash, value);
		value = character + (value << 6) + (value << 16) - value;
		return value;
	}
};

template <>
struct SDBMCalculator<1>
{
	static inline int Calculate(const char* const stringToHash, int& value)
	{
		return stringToHash[0];
	}
};


inline unsigned int SDBMHash(const std::string& key)
{
	unsigned int result = 0;

	for (unsigned int i = 0; i < key.length(); ++i)
	{
		int c = key[i];
		result = c + (result << 6) + (result << 16) - result;
		std::cout << result << std::endl;
	}

	return result;
}

#ifndef constexpr
#define constexpr const
#else
constexpr inline unsigned int constexpr_strlen(const char* const str)
{
	return str[0] != '\0'
		? constexpr_strlen(str + 1) + 1
		: 0;
}
#endif