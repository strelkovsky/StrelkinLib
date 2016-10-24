//-----------------------------------------------------------------------------
// Strelkin Lib
// Copyright (C) strelkovsky.com, Inc.
//-----------------------------------------------------------------------------

#pragma once

#include <cmath>

namespace math
{
	const long double PI = 3.1415926535897932384626433832795;
	const float EPSILON = 0.0001f;

	const float math_radians = (float)(PI / 180.0f);
	const float math_degrees = (float)(180.0f / PI);

	float Sqr(const float& val);
	float Sqrt(const float& val);

	float Abs(const float& val);

	float Cos(const float& angle)
	{
		return cosf(angle);
	}

	float Sin(const float& angle)
	{
		return sinf(angle);
	}

	float Tan(const float& angle)
	{
		return tanf(angle);
	}
} // namespace math