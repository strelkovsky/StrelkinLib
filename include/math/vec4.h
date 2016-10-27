//-----------------------------------------------------------------------------
// Strelkin Lib
// Copyright (C) strelkovsky.com, Inc.
//-----------------------------------------------------------------------------

#pragma once

#include "math.h"

namespace math
{
	struct vec3;
	struct vec4
	{
		inline vec4() = default;
		inline vec4(float x, float y, float z, float w) : x(x), y(y), z(z), w(w) { }
		inline vec4(const float *v) : x(v[0]), y(v[1]), z(v[2]), w(v[3]) { }
		inline vec4(const vec3 &v) : x(v.x), y(v.y), z(v.z), w(1) { }
		inline vec4(const vec3 &v, float w) : x(v.x), y(v.y), z(v.z), w(w) { }
		inline vec4(const vec4 &v) : x(v.x), y(v.y), z(v.z), w(v.w) { }

		inline bool operator==(const vec4& v) const { return math::abs(x - v.x) < math::EPSILON && fabs(y - v.y) < math::EPSILON && math::abs(z - v.z) < math::EPSILON && math::abs(w - v.w) < math::EPSILON; }
		inline bool operator!=(const vec4& v) const { return !(*this == v); }

		int operator==(const vec4 &v) { return (x == v.x && y == v.y && z == v.z && w == v.w); }
		int operator!=(const vec4 &v) { return (x != v.x || y != v.y || z != v.z || w != v.w); }

		// Assignment operators
		inline vec4& operator+=(const vec4& v) { x += v.x; y += v.y; z += v.z; w += v.w; return *this; }
		inline vec4& operator-=(const vec4& v) { x -= v.x; y -= v.y; z -= v.z; w -= v.w; return *this; }
		inline vec4& operator*=(const vec4& v) { x *= v.x; y *= v.y; z *= v.z; w *= v.w; return *this; }
		inline vec4& operator*=(float f) { x *= f; y *= f; z *= f; w *= f; return *this; }
		inline vec4& operator/=(float f) { x /= f; y /= f; z /= f; w /= f; return *this; }

		// Unary operators:
		vec4 operator-() const { return vec4(-x, -y, -z, -w); }

		operator float*() { return v; }
		operator const float*() const { return v; }

		float &operator[](int i) { return v[i]; }
		const float operator[](int i) const { return v[i]; }

		union 
		{
			struct { float x = 0, y = 0, z = 0, w = 1; };
			float v[4];
		};
	};
} // namespace math