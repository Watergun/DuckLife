#ifndef MAKROS_H
#define MAKROS_H

#define _USE_MATH_DEFINES
#include <cmath>
#include <cstring>

#define RAD_TO_DEG(A)	((A*1.0f)*(180.0f/M_PI))
#define DEG_TO_RAD(A)	((A*1.0f)*(M_PI/180.0f))

extern char* stradd(const char* strA, const char* strB);
extern char* substr(const char* str, unsigned int start, unsigned int end);

#endif
