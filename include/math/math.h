//-----------------------------------------------------------------------------
// Strelkin Lib
// Copyright (C) strelkovsky.com, Inc.
//-----------------------------------------------------------------------------

#pragma once

#include <cmath>

namespace math
{
	const float PI = 3.14159265358979323846f;
	const float EPSILON = 0.0001f;

	inline float radians(float deg)
	{
		return (PI / 180.f) * deg;
	}

	inline float degrees(float rad)
	{
		return (180.f / PI) * rad;
	}

	inline float min(float a, float b)
	{
		return std::fminf(a, b);
	}

	inline float max(float a, float b)
	{
		return std::fmaxf(a, b);
	}

	float sqr(const float val);
	float sqrt(const float val);

	float abs(const float val);

	float cos(const float angle);
	float sin(const float angle);

	float tan(const float angle);
} // namespace math