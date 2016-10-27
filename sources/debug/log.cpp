//-----------------------------------------------------------------------------
// Strelkin Lib
// Copyright (C) strelkovsky.com, Inc.
//-----------------------------------------------------------------------------

#include <cstdarg>
#include <list>
#include <memory>

#include "debug\log.h"

using std::list;

namespace log
{
	namespace details
	{
		list<std::unique_ptr<processor>> processors;

		level current_level;

		void message(level level, const char* format, va_list argsptr)
		{
			if (processors.empty())
			{
				vprintf(format, argsptr);
			}
			else
			{
				for (auto& p : processors)
				{
					p->message(level, format, argsptr);
				}
			}
		}
	}

	void set_log_level(level l)
	{
		details::current_level = l;
	}

	void set_log_filter(const char* filter)
	{
	}

	void attach(std::unique_ptr<processor> processor)
	{
		details::processors.push_back(processor);
	}

	void info(const char* msg, ...)
	{
		if (details::current_level >= level::info)
		{
			va_list argsptr;
			va_start(argsptr, msg);

			details::message(level::info, msg, argsptr);

			va_end(argsptr);
		}
	}

	void warn(const char* msg, ...)
	{
		if (details::current_level >= level::warn)
		{
			va_list argsptr;
			va_start(argsptr, msg);

			details::message(level::warn, msg, argsptr);

			va_end(argsptr);
		}
	}

	void error(const char* msg, ...)
	{
		if (details::current_level >= level::error)
		{
			va_list argsptr;
			va_start(argsptr, msg);

			details::message(level::error, msg, argsptr);

			va_end(argsptr);
		}
	}

	void fatal(const char* msg, ...)
	{
		if (details::current_level >= level::fatal)
		{
			va_list argsptr;
			va_start(argsptr, msg);

			details::message(level::fatal, msg, argsptr);

			va_end(argsptr);
		}
	}

} // namespace log