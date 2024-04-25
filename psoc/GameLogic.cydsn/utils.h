#ifndef UTILS_H
#define UTILS_H

#include <stdint.h>
#include <stddef.h>

#define len(x) (sizeof((x)) / sizeof((x)[0]))

// Boolean
typedef uint8_t bool;
#define false ((bool)0)
#define true ((bool)1)
// Platform
typedef size_t usize;
// 8-bit
typedef uint8_t u8;
typedef int8_t i8;
// 16-bit
typedef int16_t i16;
typedef uint16_t u16;
// 32-bit
typedef uint32_t u32;
typedef int32_t i32;
// 64-bit
typedef uint64_t u64;
typedef int64_t i64;
// Floating-point
typedef float f32;
typedef double f64;

#endif