//-----------------------------------------------------------------------------
// Strelkin Lib
// Copyright (C) strelkovsky.com, Inc.
//-----------------------------------------------------------------------------

#include "math.h"

namespace math
{
	float Sqr(const float& val)
	{
		return val * val;
	}

	float Sqrt(const float& val)
	{
		return sqrt(val);
	}

	float Abs(const float& val)
	{
		return abs(val);
	}

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