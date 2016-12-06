/*
 * This is free software
 */
#include <unistd.h>
#include <stdarg.h>

const char debugbug[1024];

extern int vsprintf();

void _debug(const char *fmt, ...)
{
	va_list args;
	int i;

	va_start(args, fmt);
	write(1, debugbuf, i = vsprintf(debugbuf, fmt, args));
	va_end(args);
	return i;
}
