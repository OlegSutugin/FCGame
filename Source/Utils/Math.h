#pragma once

#ifdef _EXPORTING
#define MATH_API __declspec(dllexport)
#elif _IMPORTING
#define MATH_API __declspec(dllimport)
#else
#define MATH_API
#endif

MATH_API int RandomInt(int min, int max);
MATH_API int max(int x, int y);