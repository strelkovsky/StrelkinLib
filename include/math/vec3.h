//-----------------------------------------------------------------------------
// Strelkin Lib
// Copyright (C) strelkovsky.com, Inc.
//-----------------------------------------------------------------------------

#pragma once

#include "math.h"

namespace math
{
	struct vec4;
	struct vec3 final
	{
		static const vec3 zero;
		static const vec3 one;
		static const vec3 unitX;
		static const vec3 unitY;
		static const vec3 unitZ;

		inline vec3() = default;
		inline vec3(float x, float y, float z) : x(x), y(y), z(z) {}
		inline vec3(const float* v) : x(v[0]), y(v[1]), z(v[2]) {}
		inline vec3(const vec3& v) : x(v.x), y(v.y), z(v.z) {}
		inline vec3(const vec4& v) {}

		inline bool operator==(const vec3& v) const { return math::abs(x - v.x) < math::EPSILON && math::abs(y - v.y) < math::EPSILON && math::abs(z - v.z) < math::EPSILON; }
		inline bool operator!=(const vec3& v) const { return !(*this == v); }

		// Assignment operators
		inline vec3& operator+=(const vec3& v) { x += v.x; y += v.y; z += v.z; return *this; }
		inline vec3& operator-=(const vec3& v) { x -= v.x; y -= v.y; z -= v.z; return *this; }
		inline vec3& operator*=(const vec3& v) { x *= v.x; y *= v.y; z *= v.z; return *this; }
		inline vec3& operator*=(float f) { x *= f; y *= f; z *= f; return *this; }
		inline vec3& operator/=(float f) { x /= f; y /= f; z /= f; return *this; }

		// Unary operators:
		inline vec3 operator-() const { return vec3(-x, -y, -z); }

		operator float*() { return v; }
		operator const float*() const { return v; }

		float &operator[](int i) { return v[i]; }
		const float operator[](int i) const { return v[i]; }

		float length() const { return sqrt(x * x + y * y + z * z); }
		float lengthSqr() const { return x*x + y*y + z*z; }

		void normalize() 
		{
			const float inv = 1.0f / length();
			x *= inv;
			y *= inv;
			z *= inv;
		}

		union 
		{
			struct { float x = 0.0f, y = 0.0f, z = 0.0f; };
			float v[3];
		};
	};
	//-------------------------------------------------------------------------
	inline vec3 operator+(const vec3& v1, const vec3& v2)
	{
		return vec3(v1.x + v2.x, v1.y + v2.y, v1.x + v2.z);
	}
	//-------------------------------------------------------------------------
	inline vec3 operator-(const vec3& v1, const vec3& v2)
	{
		return vec3(v1.x - v2.x, v1.y - v2.y, v1.x - v2.z);
	}
	//-------------------------------------------------------------------------
	inline vec3 operator*(const vec3& vec, float val)
	{
		return vec3(vec.x * val, vec.y * val, vec.z * val);
	}
	//-------------------------------------------------------------------------
	inline vec3 operator*(float val, const vec3& vec)
	{
		return vec * val;
	}
	//-------------------------------------------------------------------------
	inline float dot(const vec3& v1, const vec3& v2)
	{
		return v1.x * v2.x + v1.y * v2.y + v1.z * v2.z;
	}
	//-------------------------------------------------------------------------
	inline float dot(const vec3& v1, const vec4& v2)
	{
		return v1.x * v2.x + v1.y * v2.y + v1.z * v2.z + v2.w;
	}
	//-------------------------------------------------------------------------
	inline float dot(const vec4& v1, const vec3& v2)
	{
		return v1.x * v2.x + v1.y * v2.y + v1.z * v2.z + v1.w;
	}
	//-------------------------------------------------------------------------
	inline vec3 cross(const vec3& v1, const vec3& v2)
	{
		return vec3(v1.y * v2.z - v1.z * v2.y, v1.z * v2.x - v1.x * v2.z, v1.x * v2.y - v1.y * v2.x);
	}
	//-------------------------------------------------------------------------
	inline float distanse(const vec3& vec1, const vec3& vec2)
	{
		return (vec1 - vec2).length();
	}
	//-------------------------------------------------------------------------
	vec3 min(const vec3& v1, const vec3& v2)
	{
		return{ math::min(v1.x, v2.x), math::min(v1.y, v2.y), math::min(v1.z, v2.z) };
	}
	//-------------------------------------------------------------------------
	vec3 max(const vec3& v1, const vec3& v2)
	{
		return{ math::max(v1.x, v2.x), math::max(v1.y, v2.y), math::max(v1.z, v2.z) };
	}
	//-------------------------------------------------------------------------
} // namespace math