#pragma once

//clang-format off
#if defined(WIN32) || defined(_WINDOWS)
    #ifdef _EXPORTING
        #define MATH_API __declspec(dllexport)
    #elif _IMPORTING
        #define MATH_API __declspec(dllimport)
    #else
        #define MATH_API
    #endif
#else
    #define MATH_API __attribute__ ((visibility("default")))
#endif
//clang-format on

MATH_API int RandomInt(int min, int max);
MATH_API float RandomFloat(float min, float max);
MATH_API int max(int x, int y);