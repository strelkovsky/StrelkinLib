//-----------------------------------------------------------------------------
// Strelkin Lib
// Copyright (C) strelkovsky.com, Inc.
//-----------------------------------------------------------------------------

#pragma once

namespace math
{
	struct vec3;
	struct plane final
	{
		vec3 normal;
		float offset;

		inline plane() = default;
		inline plane(const plane& src) : normal(src.normal), offset(src.offset) {}
		inline explicit plane(const vec3& p, float off) : normal(p), offset(off) {}

		plane& operator=(const plane& src) { normal = src.normal; offset = src.offset; return *this; }

		//float Distance(const vec3& point) const { return (Dot(normal, point) + offset); }
	};
} // namespace math