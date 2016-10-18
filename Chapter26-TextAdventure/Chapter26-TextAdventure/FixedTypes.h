#pragma once
#include <cassert>
#include <cstdint>
#include <climits>

static_assert(CHAR_BIT == 8, "Compiling on a platform with large char type!");
using char8_t = char;
using uchar8_t = unsigned char;