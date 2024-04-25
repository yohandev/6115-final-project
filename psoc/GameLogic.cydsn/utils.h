#ifndef UTILS_H
#define UTILS_H

#include <stdint.h>
#include <stddef.h>
#include <stdlib.h>

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

// 2D Vector
typedef union {         // TODO: fixed point
    f32 x;
    f32 y;
} vec2;

static inline vec2 vec2_add(const vec2 a, const vec2 b) {
    return (vec2){
        .x = a.x + b.x,
        .y = a.y + b.y,
    };
}

static inline vec2 vec2_sub(const vec2 a, const vec2 b) {
    return (vec2){
        .x = a.x - b.x,
        .y = a.y - b.y,
    };
}

static inline vec2 vec2_scale(const vec2 a, const f32 s) {
    return (vec2){
        .x = a.x * s,
        .y = a.y * s,
    };
}

// 3D Vector
typedef union {         // TODO: fixed point
    f32 x;
    f32 y;
    f32 z;
} vec3;

static inline vec3 vec3_add(const vec3 a, const vec3 b) {
    return (vec3){
        .x = a.x + b.x,
        .y = a.y + b.y,
        .z = a.z + b.z,
    };
}

static inline vec3 vec3_sub(const vec3 a, const vec3 b) {
    return (vec3){
        .x = a.x - b.x,
        .y = a.y - b.y,
        .z = a.z - b.z,
    };
}

static inline vec3 vec3_scale(const vec3 a, const f32 s) {
    return (vec3){
        .x = a.x * s,
        .y = a.y * s,
        .z = a.z * s,
    };
}

vec3 vec3_rand(const f32 scale) {
    // Order of operation will matter when changing this to fixed point
    return (vec3){
        .x = (f32)rand() / RAND_MAX * scale,
        .y = (f32)rand() / RAND_MAX * scale,
        .z = (f32)rand() / RAND_MAX * scale,
    };
}

#endif