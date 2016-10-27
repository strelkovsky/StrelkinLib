//-----------------------------------------------------------------------------
// Strelkin Lib
// Copyright (C) strelkovsky.com, Inc.
//-----------------------------------------------------------------------------

#pragma once

namespace log
{
	enum struct level : short
	{
		info,
		warn,
		error,
		fatal
	};

	struct processor
	{
		virtual ~processor() = 0;
		virtual void message(level level, const char* format, va_list argsptr) = 0;
	};

	void set_log_level(level l);
	void set_log_filter(const char* filter);

	void attach(std::unique_ptr<processor> proc);

	void info(const char* msg, ...);
	void warn(const char* msg, ...);
	void error(const char* msg, ...);
	void fatal(const char* msg, ...);
} // namespace log
