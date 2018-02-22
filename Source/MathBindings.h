#pragma once
#include <stdint.h>

#define Pi32	3.1415926535897932384626433832795028841971693993751058209749445923078164062

#define real32	float
#define real64	double
#define real	real32

#define int8	int8_t
#define int16	int16_t
#define int32	int32_t
#define int64	int64_t

#define uint8	uint8_t
#define uint16	uint16_t
#define uint32	uint32_t
#define uint64	uint64_t

typedef struct Vector2 {

	real x;
	real y;
} Vector2;

typedef struct Vector3 {

	real x;
	real y;
	real z;
} Vector3;