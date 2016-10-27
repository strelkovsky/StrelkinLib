//-----------------------------------------------------------------------------
// Strelkin Lib
// Copyright (C) strelkovsky.com, Inc.
//-----------------------------------------------------------------------------

#include <cmath>
#include "math.h"

namespace math
{
	float sqr(const float val)
	{
		return val * val;
	}

	float sqrt(const float val)
	{
		return std::sqrtf(val);
	}

	float abs(const float val)
	{
		return std::abs(val);
	}

	float cos(const float angle)
	{
		return std::cosf(angle);
	}

	float sin(const float angle)
	{
		return std::sinf(angle);
	}

	float tan(const float angle)
	{
		return std::tanf(angle);
	}
} // namespace math