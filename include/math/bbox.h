//-----------------------------------------------------------------------------
// Strelkin Lib
// Copyright (C) strelkovsky.com, Inc.
//-----------------------------------------------------------------------------

#pragma once

namespace math
{
	struct vec3;
	struct bbox final
	{
		vec3 min;
		vec3 max;
	};
} // namespace math