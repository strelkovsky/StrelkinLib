//-----------------------------------------------------------------------------
// Strelkin Lib
// Copyright (C) strelkovsky.com, Inc.
//-----------------------------------------------------------------------------

#pragma once

#include "math.h"

namespace math
{
	struct mat4
	{
		static const mat4 zero;
		static const mat4 identity;

		inline mat4() = default;
		inline mat4(const float *m)
		{
			mat[0] = m[0]; mat[4] = m[4]; mat[8] = m[8]; mat[12] = m[12];
			mat[1] = m[1]; mat[5] = m[5]; mat[9] = m[9]; mat[13] = m[13];
			mat[2] = m[2]; mat[6] = m[6]; mat[10] = m[10]; mat[14] = m[14];
			mat[3] = m[3]; mat[7] = m[7]; mat[11] = m[11]; mat[15] = m[15];
		}
		inline mat4(
			float m00, float m01, float m02, float m03,
			float m10, float m11, float m12, float m13,
			float m20, float m21, float m22, float m23,
			float m30, float m31, float m32, float m33)
		{
			mat[0] = m00; mat[4] = m01; mat[8] = m02; mat[12] = m03;
			mat[1] = m10; mat[5] = m11; mat[9] = m12; mat[13] = m13;
			mat[2] = m20; mat[6] = m21; mat[10] = m22; mat[14] = m23;
			mat[3] = m30; mat[7] = m31; mat[11] = m32; mat[15] = m33;
		}
		inline mat4(const mat4 &m) 
		{
			mat[0] = m[0]; mat[4] = m[4]; mat[8] = m[8]; mat[12] = m[12];
			mat[1] = m[1]; mat[5] = m[5]; mat[9] = m[9]; mat[13] = m[13];
			mat[2] = m[2]; mat[6] = m[6]; mat[10] = m[10]; mat[14] = m[14];
			mat[3] = m[3]; mat[7] = m[7]; mat[11] = m[11]; mat[15] = m[15];
		}

		bool operator==(const mat4 &m) const 
		{
			return math::abs(mat[0] - m.mat[0]) < EPSILON && math::abs(mat[1] - m.mat[1]) < EPSILON && math::abs(mat[2] - m.mat[2]) < EPSILON && math::abs(mat[3] - m.mat[3]) < EPSILON &&
				math::abs(mat[4] - m.mat[4]) < EPSILON && math::abs(mat[5] - m.mat[5]) < EPSILON && math::abs(mat[6] - m.mat[6]) < EPSILON && math::abs(mat[7] - m.mat[7]) < EPSILON &&
				math::abs(mat[8] - m.mat[8]) < EPSILON && math::abs(mat[9] - m.mat[9]) < EPSILON && math::abs(mat[10] - m.mat[10]) < EPSILON && math::abs(mat[11] - m.mat[11]) < EPSILON &&
				math::abs(mat[12] - m.mat[12]) < EPSILON && math::abs(mat[13] - m.mat[13]) < EPSILON && math::abs(mat[14] - m.mat[14]) < EPSILON && math::abs(mat[15] - m.mat[15]) < EPSILON;
		}
		bool operator!=(const mat4 &m) const { return !(*this == m); }

		operator float*() { return mat; }
		operator const float*() const { return mat; }

		float &operator[](int i) { return mat[i]; }
		const float operator[](int i) const { return mat[i]; }

		mat4 rotation() 
		{
			mat4 ret;
			ret[0] = mat[0]; ret[4] = mat[4]; ret[8] = mat[8]; ret[12] = 0;
			ret[1] = mat[1]; ret[5] = mat[5]; ret[9] = mat[9]; ret[13] = 0;
			ret[2] = mat[2]; ret[6] = mat[6]; ret[10] = mat[10]; ret[14] = 0;
			ret[3] = 0; ret[7] = 0; ret[11] = 0; ret[15] = 1;
			return ret;
		}

		mat4 transpose() 
		{
			mat4 ret;
			ret[0] = mat[0]; ret[4] = mat[1]; ret[8] = mat[2]; ret[12] = mat[3];
			ret[1] = mat[4]; ret[5] = mat[5]; ret[9] = mat[6]; ret[13] = mat[7];
			ret[2] = mat[8]; ret[6] = mat[9]; ret[10] = mat[10]; ret[14] = mat[11];
			ret[3] = mat[12]; ret[7] = mat[13]; ret[11] = mat[14]; ret[15] = mat[15];
			return ret;
		}

		mat4 inverse() 
		{
			mat4 ret;
			float det;
			det = mat[0] * mat[5] * mat[10];
			det += mat[4] * mat[9] * mat[2];
			det += mat[8] * mat[1] * mat[6];
			det -= mat[8] * mat[5] * mat[2];
			det -= mat[4] * mat[1] * mat[10];
			det -= mat[0] * mat[9] * mat[6];
			det = 1.0f / det;
			ret[0] = (mat[5] * mat[10] - mat[9] * mat[6]) * det;
			ret[1] = -(mat[1] * mat[10] - mat[9] * mat[2]) * det;
			ret[2] = (mat[1] * mat[6] - mat[5] * mat[2]) * det;
			ret[3] = 0.0;
			ret[4] = -(mat[4] * mat[10] - mat[8] * mat[6]) * det;
			ret[5] = (mat[0] * mat[10] - mat[8] * mat[2]) * det;
			ret[6] = -(mat[0] * mat[6] - mat[4] * mat[2]) * det;
			ret[7] = 0.0;
			ret[8] = (mat[4] * mat[9] - mat[8] * mat[5]) * det;
			ret[9] = -(mat[0] * mat[9] - mat[8] * mat[1]) * det;
			ret[10] = (mat[0] * mat[5] - mat[4] * mat[1]) * det;
			ret[11] = 0.0;
			ret[12] = -(mat[12] * ret[0] + mat[13] * ret[4] + mat[14] * ret[8]);
			ret[13] = -(mat[12] * ret[1] + mat[13] * ret[5] + mat[14] * ret[9]);
			ret[14] = -(mat[12] * ret[2] + mat[13] * ret[6] + mat[14] * ret[10]);
			ret[15] = 1.0;
			return ret;
		}

		float mat[16] = { 0 };
	};
	//-------------------------------------------------------------------------
	inline mat4 operator*(const mat4& first, const mat4& second)
	{
		mat4 ret;
		ret.mat[0] = first.mat[0] * second.mat[0] + first.mat[1] * second.mat[4] + first.mat[2] * second.mat[8] + first.mat[3] * second.mat[12];
		ret.mat[1] = first.mat[0] * second.mat[1] + first.mat[1] * second.mat[5] + first.mat[2] * second.mat[9] + first.mat[3] * second.mat[13];
		ret.mat[2] = first.mat[0] * second.mat[2] + first.mat[1] * second.mat[6] + first.mat[2] * second.mat[10] + first.mat[3] * second.mat[14];
		ret.mat[3] = first.mat[0] * second.mat[3] + first.mat[1] * second.mat[7] + first.mat[2] * second.mat[11] + first.mat[3] * second.mat[15];
		ret.mat[4] = first.mat[4] * second.mat[0] + first.mat[5] * second.mat[4] + first.mat[6] * second.mat[8] + first.mat[7] * second.mat[12];
		ret.mat[5] = first.mat[4] * second.mat[1] + first.mat[5] * second.mat[5] + first.mat[6] * second.mat[9] + first.mat[7] * second.mat[13];
		ret.mat[6] = first.mat[4] * second.mat[2] + first.mat[5] * second.mat[6] + first.mat[6] * second.mat[10] + first.mat[7] * second.mat[14];
		ret.mat[7] = first.mat[4] * second.mat[3] + first.mat[5] * second.mat[7] + first.mat[6] * second.mat[11] + first.mat[7] * second.mat[15];
		ret.mat[8] = first.mat[8] * second.mat[0] + first.mat[9] * second.mat[4] + first.mat[10] * second.mat[8] + first.mat[11] * second.mat[12];
		ret.mat[9] = first.mat[8] * second.mat[1] + first.mat[9] * second.mat[5] + first.mat[10] * second.mat[9] + first.mat[11] * second.mat[13];
		ret.mat[10] = first.mat[8] * second.mat[2] + first.mat[9] * second.mat[6] + first.mat[10] * second.mat[10] + first.mat[11] * second.mat[14];
		ret.mat[11] = first.mat[8] * second.mat[2] + first.mat[9] * second.mat[6] + first.mat[10] * second.mat[10] + first.mat[11] * second.mat[14];
		ret.mat[12] = first.mat[12] * second.mat[0] + first.mat[13] * second.mat[4] + first.mat[14] * second.mat[8] + first.mat[15] * second.mat[12];
		ret.mat[13] = first.mat[12] * second.mat[1] + first.mat[13] * second.mat[5] + first.mat[14] * second.mat[9] + first.mat[15] * second.mat[13];
		ret.mat[14] = first.mat[12] * second.mat[2] + first.mat[13] * second.mat[6] + first.mat[14] * second.mat[10] + first.mat[15] * second.mat[14];
		ret.mat[15] = first.mat[12] * second.mat[3] + first.mat[13] * second.mat[7] + first.mat[14] * second.mat[11] + first.mat[15] * second.mat[15];
		return ret;
	}
} // namespace math
