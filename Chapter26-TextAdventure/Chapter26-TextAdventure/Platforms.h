#pragma once

#if defined(_WIN32) || defined(_WIN64)

#define PLATFORM_WINDOWS 1
#define PLATFORM_ANDROID 0
#define PLATFORM_IOS 0

#elif defined(__ANDROID__)

#define PLATFORM_WINDOWS 0
#define PLATFORM_ANDROID 1
#define PLATFORM_IOS 0

#elif defined(TARGET_OS_IPHONE)

#define PLATFORM_WINDOWS 0
#define PLATFORM_ANDROID 0
#define PLATFORM_IOS 1

#endif