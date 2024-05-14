#ifndef NUM_H
#define NUM_H

#include <stdint.h>
#include <stddef.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

#define len(x) (sizeof((x)) / sizeof((x)[0]))
#define min(a, b) (((a) < (b)) ? (a) : (b))
#define max(a, b) (((a) > (b)) ? (a) : (b))

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

static inline f32 randf() {
    return 2.0 * ((f32)rand() / RAND_MAX - 0.5);
}

// Color
// typedef struct {
//     u16 r: 5;
//     u16 g: 6;
//     u16 b: 5;
// } rgb;
typedef struct {
    u16 inner;
} rgb;

// 16.16 Fixed-Point
typedef i32 fixed32;
typedef fixed32 fixed;

static const fixed FIXED_EPSILON = 1;
static const fixed FIXED_ONE = 1 << 16;

static inline fixed f32_to_fixed(f32 f) {
    return (fixed)(f * 65536.0f);
}

static inline f32 fixed_to_f32(fixed f) {
    return (f32)(f / 65536.0f);
}

static inline fixed i32_to_fixed(i32 i) {
    return (fixed)(i << 16);
}

static inline i32 fixed_to_i32(fixed f) {
    return (i32)(f >> 16);
}

static inline fixed fixed_mul(fixed a, fixed b) {
    return (fixed)(((i64)a * (i64)b) >> 16);
}

static inline fixed fixed_div(fixed a, fixed b) {
    return (fixed)(((i64)a << 16) / b);
}

static inline fixed fixed_sqrt(fixed f) {
    return (fixed)(sqrtf((f32)f) / 255.0);
}

// 8.8 Fixed_Point
typedef i16 fixed16;

static const fixed16 FIXED16_EPSILON = 1;
static const fixed16 FIXED16_ONE = 1 << 8;

static inline fixed16 f32_to_fixed16(f32 f) {
    return (fixed16)(f * 256.0f);
}

static inline f32 fixed16_to_f32(fixed16 f) {
    return (f32)(f / 256.0f);
}

static inline fixed16 i32_to_fixed16(i32 i) {
    return (fixed16)(i << 8);
}

static inline i32 fixed16_to_i32(fixed16 f) {
    return (i32)(f >> 8);
}

static inline fixed16 fixed16_mul(fixed16 a, fixed16 b) {
    return (fixed16)(((i32)a * (i32)b) >> 8);
}

static inline fixed16 fixed16_div(fixed16 a, fixed16 b) {
    return (fixed16)(((i32)a << 8) / b);
}

// 2D Vector
typedef struct {
    f32 x;
    f32 y;
} vec2f;

static inline vec2f vec2f_add(const vec2f a, const vec2f b) {
    return (vec2f){
        .x = a.x + b.x,
        .y = a.y + b.y,
    };
}

static inline vec2f vec2f_sub(const vec2f a, const vec2f b) {
    return (vec2f){
        .x = a.x - b.x,
        .y = a.y - b.y,
    };
}

static inline vec2f vec2f_scale(const vec2f a, const f32 s) {
    return (vec2f){
        .x = a.x * s,
        .y = a.y * s,
    };
}

// 2D Vector (Fixed Point)
typedef struct {
    fixed x;
    fixed y;
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

static inline vec2 vec2_scale(const vec2 a, const fixed s) {
    return (vec2){
        .x = fixed_mul(a.x, s),
        .y = fixed_mul(a.y, s),
    };
}

// 3D Vector
typedef struct {
    f32 x;
    f32 y;
    f32 z;
} vec3f;

static inline vec3f vec3f_add(const vec3f a, const vec3f b) {
    return (vec3f){
        .x = a.x + b.x,
        .y = a.y + b.y,
        .z = a.z + b.z,
    };
}

static inline vec3f vec3f_sub(const vec3f a, const vec3f b) {
    return (vec3f){
        .x = a.x - b.x,
        .y = a.y - b.y,
        .z = a.z - b.z,
    };
}

static inline vec3f vec3f_scale(const vec3f a, const f32 s) {
    return (vec3f){
        .x = a.x * s,
        .y = a.y * s,
        .z = a.z * s,
    };
}

static inline vec3f vec3f_rand(const f32 scale) {
    // Order of operation will matter when changing this to fixed point
    return (vec3f){
        .x = ((f32)rand() / RAND_MAX - 0.5) * scale,
        .y = ((f32)rand() / RAND_MAX - 0.5) * scale,
        .z = ((f32)rand() / RAND_MAX - 0.5) * scale,
    };
}

static inline vec3f vec3f_lerp(const vec3f a, const vec3f b, const f32 t) {
    return (vec3f){
        .x = a.x + (b.x - a.x) * t,
        .y = a.y + (b.y - a.y) * t,
        .z = a.z + (b.z - a.z) * t,
    };
}

// 3D Vector (Fixed Point)
typedef struct {
    fixed x;
    fixed y;
    fixed z;
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

static inline vec3 vec3_scale(const vec3 a, const fixed s) {
    return (vec3){
        .x = fixed_mul(a.x, s),
        .y = fixed_mul(a.y, s),
        .z = fixed_mul(a.z, s),
    };
}

static inline vec3 vec3_cross(const vec3 a, const vec3 b) {
    return (vec3){
        .x = fixed_mul(a.y, b.z) - fixed_mul(a.z, b.y),
        .y = fixed_mul(a.z, b.x) - fixed_mul(a.x, b.z),
        .z = fixed_mul(a.x, b.y) - fixed_mul(a.y, b.x),
    };
}

static inline fixed vec3_dot(const vec3 a, const vec3 b) {
    return fixed_mul(a.x, b.x) + fixed_mul(a.y, b.y) + fixed_mul(a.z, b.z);
}

static inline fixed vec3_magnitude(const vec3 v) {
    return fixed_sqrt(fixed_mul(v.x, v.x) + fixed_mul(v.y, v.y) + fixed_mul(v.z, v.z));
}

static inline vec3 vec3_normalized(const vec3 v) {
    fixed l = vec3_magnitude(v);
    if (l == 0) {
        return (vec3) { 0, 0, 0 };
    }
    fixed l1 = fixed_div(1, l);

    return vec3_scale(v, l1);
}

// 3D Vector (8.8 Fixed Point)
typedef struct {
    fixed16 x;
    fixed16 y;
    fixed16 z;
} vec3s;

// Quaternion
// Adapted from https://github.com/MartinWeigel/Quaternion
typedef struct {
    f32 w;
    f32 x;
    f32 y;
    f32 z;
} quat;

static quat quat_mul(const quat* a, const quat* b) {
    quat out;

    out.w = (a->w * b->w) - (a->x * b->x) - (a->y * b->y) - (a->z * b->z);
    out.x = (a->x * b->w) + (a->w * b->x) + (a->y * b->z) - (a->z * b->y);
    out.y = (a->w * b->y) - (a->x * b->z) + (a->y * b->w) + (a->z * b->x);
    out.z = (a->w * b->z) + (a->x * b->y) - (a->y * b->x) + (a->z * b->w);

    return out;
}

static vec3f quat_rotate(const quat* q, const vec3f* v) {
    vec3f out;
    
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

static vec3f quat_up(const quat* q) {
    vec3f out;
    
    f32 xx = q->x * q->x;
    f32 zz = q->z * q->z;
    f32 wx = q->w * q->x;
    f32 wz = q->w * q->z;
    f32 xy = q->x * q->y;
    f32 yz = q->y * q->z;

    out.x = 2 * (xy - wz);
    out.y = 1 - 2 * (xx + zz);
    out.z = 2 * (yz + wx);
    
    return out;
}

static vec3f quat_forward(const quat* q) {
    vec3f out;
    
    f32 xx = q->x * q->x;
    f32 yy = q->y * q->y;
    f32 wx = q->w * q->x;
    f32 wy = q->w * q->y;
    f32 xz = q->x * q->z;
    f32 yz = q->y * q->z;

    out.x = 2 * (xz + wy);
    out.y = 2 * (yz - wx);
    out.z = 1 - 2 * (xx + yy);
    
    return out;
}

static vec3f quat_left(const quat* q) {
    vec3f out;
    
    f32 yy = q->y * q->y;
    f32 zz = q->z * q->z;
    f32 wy = q->w * q->y;
    f32 wz = q->w * q->z;
    f32 xy = q->x * q->y;
    f32 xz = q->x * q->z;

    out.x = 1 - 2 * (yy + zz);
    out.y = 2 * (xy + wz);
    out.z = 2 * (xz - wy);
    
    return out;
}

static quat quat_from_euler(f32 yaw, f32 pitch, f32 roll) {
    quat out;
    
    f32 cy = cos(yaw * 0.5);
    f32 sy = sin(yaw * 0.5);
    f32 cr = cos(roll * 0.5);
    f32 sr = sin(roll * 0.5);
    f32 cp = cos(pitch * 0.5);
    f32 sp = sin(pitch * 0.5);

    out.w = cp * cy * cr + sp * sy * sr;
    out.x = sp * cy * cr - cp * sy * sr;
    out.y = cp * sy * cr + sp * cy * sr;
    out.z = cp * cy * sr - sp * sy * cr;  

    return out;
}

static quat quat_slerp(quat* a, quat* b, f32 t) {
    f32 cos_half_theta = (a->w * b->w) + (a->x * b->x) + (a->y * b->y) + (a->z * b->z);

    if (fabs(cos_half_theta) >= 1.0) {
        return *a;
    }

    f32 half_theta = acos(cos_half_theta);
    f32 sin_half_theta = sqrt(1.0 - (cos_half_theta * cos_half_theta));
    quat out;

    if (fabs(sin_half_theta) < 1e-4) {
        out.w = (a->w * 0.5) + (b->w * 0.5);
        out.x = (a->x * 0.5) + (b->x * 0.5);
        out.y = (a->y * 0.5) + (b->y * 0.5);
        out.z = (a->z * 0.5) + (b->z * 0.5);
    } else {
        f32 ratio_a = sin((1 - t) * half_theta) / sin_half_theta;
        f32 ratio_b = sin(t * half_theta) / sin_half_theta;

        out.w = (a->w * ratio_a) + (b->w * ratio_b);
        out.x = (a->x * ratio_a) + (b->x * ratio_b);
        out.y = (a->y * ratio_a) + (b->y * ratio_b);
        out.z = (a->z * ratio_a) + (b->z * ratio_b);
    }

    return out;
}

// Input `axis` should be normalized
static quat quat_angle_axis(f32 angle, const vec3f axis) {
    quat out;

    f32 s = sin(angle * 0.5);

    out.w = cos(angle * 0.5);
    out.x = axis.x * s;
    out.y = axis.y * s;
    out.z = axis.z * s;
}

typedef struct {
    fixed16 inner[4][4];
} mat4s;

static inline mat4s mat4s_identity() {
    return (mat4s) {{
        { 1<<8, 0, 0, 0 },
        { 0, 1<<8, 0, 0 },
        { 0, 0, 1<<8, 0 },
        { 0, 0, 0, 1<<8 },
    }};
}

// Might have a slight speed adventage thanks to single-cycle 32-bit hardware
// multiplier. Probably wise to only do this at the last stage (i.e. MVP * vertex)
// to avoid compounding error
static vec3 mat4s_apply_vec3s(const mat4s* m, const vec3s v) {
    fixed out[4] = { 0, 0, 0, 0 };
    fixed16 in[4] = { v.x, v.y, v.z, FIXED16_ONE };
    for (usize i = 0; i < 4; i++) {
        for (usize j = 0; j < 4; j++) {
            out[j] += (i32)m->inner[j][i] * (i32)in[i];
        }
    }
    if (out[3] == 0) {
        return (vec3) { 0, 0, 0 };
    }
    return (vec3) {
        .x = fixed_div(out[0], out[3]),
        .y = fixed_div(out[1], out[3]),
        .z = fixed_div(out[2], out[3]),
    };
}

typedef struct {
    f32 inner[4][4];
} mat4f;

static inline mat4f mat4f_zero() {
    return (mat4f) {{
        { 0, 0, 0, 0 },
        { 0, 0, 0, 0 },
        { 0, 0, 0, 0 },
        { 0, 0, 0, 0 },
    }};
}

static inline mat4f mat4f_identity() {
    return (mat4f) {{
        { 1, 0, 0, 0 },
        { 0, 1, 0, 0 },
        { 0, 0, 1, 0 },
        { 0, 0, 0, 1 },
    }};
}

static mat4f mat4f_mul(const mat4f* a, const mat4f* b) {
    mat4f out = mat4f_zero();
    for (usize i = 0; i < 4; i++) {
        for (usize j = 0; j < 4; j++) {
            for (usize k = 0; k < 4; k++) {
                out.inner[i][j] += a->inner[i][k] * b->inner[k][j];
            }
        }
    }
    return out;
}

static inline mat4f mat4f_translation(vec3f t) {
    return (mat4f) {{
        { 1, 0, 0, t.x },
        { 0, 1, 0, t.y },
        { 0, 0, 1, t.z },
        { 0, 0, 0,  1  },
    }};
}

// https://en.wikipedia.org/wiki/Rotation_matrix
static inline mat4f mat4f_rotation_z(f32 t) {
    f32 c = cosf(t);
    f32 s = sinf(t);
    return (mat4f) {{
        { c, -s, 0, 0 },
        { s, c, 0, 0 },
        { 0, 0, 1, 0 },
        { 0, 0, 0, 1 },
    }};
}

static inline mat4f mat4f_rotation_y(f32 t) {
    f32 c = cosf(t);
    f32 s = sinf(t);
    return (mat4f) {{
        { c, 0, s, 0 },
        { 0, 1, 0, 0 },
        { -s, 0, c, 0 },
        { 0, 0, 0, 1 },
    }};
}

static inline mat4f mat4f_rotation_x(f32 t) {
    f32 c = cosf(t);
    f32 s = sinf(t);
    return (mat4f) {{
        { 1, 0, 0, 0 },
        { 0, c, -s, 0 },
        { 0, s, c, 0 },
        { 0, 0, 0, 1 },
    }};
}

static inline mat4f mat4f_rotation_yxz(f32 yaw, f32 pitch, f32 roll) {
    mat4f y = mat4f_rotation_y(yaw);
    mat4f x = mat4f_rotation_x(pitch);
    mat4f z = mat4f_rotation_z(roll);

    mat4f xz = mat4f_mul(&x, &z);
    mat4f yxz = mat4f_mul(&xz, &y);

    return yxz;
}

static mat4s mat4f_to_mat4s(const mat4f* m) {
    mat4s out;
    for (usize i = 0; i < 4; i++) {
        for (usize j = 0; j < 4; j++) {
            out.inner[i][j] = f32_to_fixed16(m->inner[i][j]);
        }
    }
    return out;
}

#endif