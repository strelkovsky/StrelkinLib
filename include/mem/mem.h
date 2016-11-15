//-----------------------------------------------------------------------------
// Strelkin Lib
// Copyright (C) strelkovsky.com, Inc.
//-----------------------------------------------------------------------------

#pragma once

namespace mem
{
	inline void* alloc(size_t s)
	{
		return std::malloc(s);
	}

	inline void* realloc(void* ptr, size_t s)
	{
		return std::realloc(ptr, s);
	}

	inline void free(void* ptr)
	{
		std::free(ptr);
	}

	inline void copy(const void* from, void* to, size_t s)
	{
		std::memcpy(to, from, s);
	}

	inline void move(void* from, void* to, size_t s)
	{
		std::memmove(to, from, s);
	}

	inline void clear(void* dst, size_t s)
	{
		std::memset(dst, 0, s);
	}
} // namespace mem
