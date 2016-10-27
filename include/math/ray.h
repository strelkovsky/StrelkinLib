//-----------------------------------------------------------------------------
// Strelkin Lib
// Copyright (C) strelkovsky.com, Inc.
//-----------------------------------------------------------------------------

#pragma once

namespace math
{
	struct vec3;
	struct ray final
	{
		vec3 origin;
		vec3 direction;

		inline ray() {}
		inline ray(const ray& src) { origin = src.origin; direction = src.direction; }
		inline explicit ray(vec3& point, vec3& dir) { origin = point; direction = dir; }

		vec3 get_point(float distance) const { return origin + (direction * distance); }
	};
} // namespace math