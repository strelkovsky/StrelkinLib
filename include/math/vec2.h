//-----------------------------------------------------------------------------
// Strelkin Lib
// Copyright (C) strelkovsky.com, Inc.
//-----------------------------------------------------------------------------

#pragma once

#include "math.h"

namespace math
{
	struct vec2 final
	{
		static const vec2 zero;
		static const vec2 one;

		inline vec2() = default;
		inline vec2(float x, float y) : x(x), y(y) {}
		inline vec2(const float *v) : x(v[0]), y(v[1]) {}
		inline vec2(const vec2& v) : x(v.x), y(v.y) {}

		inline bool operator==(const vec2& v) const { return math::abs (x - v.x) < math::EPSILON && fabs(y - v.y) < math::EPSILON; }
		inline bool operator!=(const vec2& v) const { return !(*this == v); }

		// Assignment operators
		inline vec2& operator+=(const vec2 &v) { x += v.x; y += v.y; return *this; }
		inline vec2& operator-=(const vec2 &v) { x -= v.x; y -= v.y; return *this; }
		inline vec2& operator*=(const vec2& v) { x *= v.x; y *= v.y; return *this; }
		inline vec2& operator*=(float f) { x *= f; y *= f; return *this; }
		inline vec2& operator/=(float f) { x /= f; y /= f; return *this; }

		// Unary operators
		vec2 operator-() const { return vec2(-x, -y); }

		operator float*() { return v; }
		operator const float*() const { return v; }

		float &operator[](int i) { return v[i]; }
		const float operator[](int i) const { return v[i]; }

		float length() const { return sqrt(x * x + y * y); }
		float lengthSqr() const{ return x*x + y*y; }
		
		void normalize()
		{
			const float inv = 1.0f / length();
			x *= inv;
			y *= inv;
		}

		union 
		{
			struct { float x = 0.0f, y = 0.0f; };
			float v[2] = {0};
		};
	};
	//-------------------------------------------------------------------------
	inline vec2 operator+(const vec2& v1, const vec2& v2)
	{
		return vec2(v1.x + v2.x, v1.y + v2.y);
	}
	//-------------------------------------------------------------------------
	inline vec2 operator-(const vec2& v1, const vec2& v2)
	{
		return vec2(v1.x - v2.x, v1.y - v2.y);
	}
	//-------------------------------------------------------------------------
	inline vec2 operator*(float s, const vec2& v)
	{
		return vec2(v.x * s, v.y * s);
	}
	//-------------------------------------------------------------------------
	inline vec2 operator*(const vec2& v, float s)
	{
		return s * v;
	}
	//-------------------------------------------------------------------------
	inline float distanse(const vec2& vec1, const vec2& vec2)
	{ 
		return (vec1 - vec2).length();
	}
	//-------------------------------------------------------------------------
	vec2 min(const vec2& v1, const vec2& v2)
	{
		return{ math::min(v1.x, v2.x), math::min(v1.y, v2.y) };
	}
	//-------------------------------------------------------------------------
	vec2 max(const vec2& v1, const vec2& v2)
	{
		return{ math::max(v1.x, v2.x), math::max(v1.y, v2.y) };
	}
	//-------------------------------------------------------------------------
} // namespace math