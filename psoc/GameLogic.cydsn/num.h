#ifndef NUM_H
#define NUM_H

#include <stdint.h>
#include <stddef.h>
#include <stdlib.h>
#include <math.h>

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

static const f32 PI = 3.1415926535897;

// Color
typedef struct {
    u16 r: 5;
    u16 g: 6;
    u16 b: 5;
} rgb;

// 2D Vector
typedef struct {         // TODO: fixed point
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
typedef struct {         // TODO: fixed point
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

static inline vec3 vec3_rand(const f32 scale) {
    // Order of operation will matter when changing this to fixed point
    return (vec3){
        .x = (f32)rand() / RAND_MAX * scale,
        .y = (f32)rand() / RAND_MAX * scale,
        .z = (f32)rand() / RAND_MAX * scale,
    };
}

// Quaternion
// Adapted from https://github.com/MartinWeigel/Quaternion
typedef struct {
    f32 w;
    f32 x;
    f32 y;
    f32 z;
} quat;

static inline quat quat_mul(const quat* a, const quat* b) {
    quat out;

    out.w = (a->w * b->w) - (a->x * b->x) - (a->y * b->y) - (a->z * b->z);
    out.x = (a->x * b->w) + (a->w * b->x) + (a->y * b->z) - (a->z * b->y);
    out.y = (a->w * b->y) - (a->x * b->z) + (a->y * b->w) + (a->z * b->x);
    out.z = (a->w * b->z) + (a->x * b->y) - (a->y * b->x) + (a->z * b->w);

    return out;
}

static inline vec3 quat_rotate(const quat* q, const vec3* v) {
    vec3 out;
    
    f32 ww = q->w * q->w;
    f32 xx = q->x * q->x;
    f32 yy = q->y * q->y;
    f32 zz = q->z * q->z;
    f32 wx = q->w * q->x;
    f32 wy = q->w * q->y;
    f32 wz = q->w * q->z;
    f32 xy = q->x * q->y;
    f32 xz = q->x * q->z;
    f32 yz = q->y * q->z;

    out.x = (ww * v->x) + (2 * wy * v->z) - (2 * wz * v->y) +
            (xx * v->x) + (2 * xy * v->y) + (2 * xz * v->z) -
            (zz * v->x) - (yy * v->x);
    out.y = (2 * xy * v->x) + (yy * v->y) + (2 * yz * v->z) +
            (2 * wz * v->x) - (zz * v->y) + (ww * v->y) -
            (2 * wx * v->z) - (xx * v->y);
    out.z = (2 * xz * v->x) + (2 * yz * v->y) + (zz * v->z) -
            (2 * wy * v->x) - (yy * v->z) + (2 * wx * v->y) -
            (xx * v->z) + (ww * v->z);
    
    return out;
}

static inline vec3 quat_forward(const quat* q) {
    vec3 out;
    
    f32 ww = q->w * q->w;
    f32 xx = q->x * q->x;
    f32 yy = q->y * q->y;
    f32 zz = q->z * q->z;
    f32 wx = q->w * q->x;
    f32 wy = q->w * q->y;
    f32 xz = q->x * q->z;
    f32 yz = q->y * q->z;

    out.x = 2 * (wy + xz);
    out.y = 2 * (yz - wx);
    out.z = zz - yy - xx + ww;
    
    return out;
}

static inline quat quat_from_euler(f32 yaw, f32 pitch, f32 roll) {
    quat out;
    
    f32 cp = cos(pitch * 0.5);
    f32 sp = sin(pitch * 0.5);
    f32 cr = cos(roll * 0.5);
    f32 sr = sin(roll * 0.5);
    f32 cy = cos(yaw * 0.5);
    f32 sy = sin(yaw * 0.5);

    out.w = cp * cr * cy + sp * sr * sy;
    out.x = sp * cr * cy - cp * sr * sy;
    out.y = cp * sr * cy + sp * cr * sy;
    out.z = cp * cr * sy - sp * sr * cy;

    return out;
}

#endif