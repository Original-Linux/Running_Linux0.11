/*
 * This is free software
 */
#include <strarg.h>
#include <string.h>

#define ZEROPAD   0x00000001  /* pad with zero */
#define SIGN      0x00000010  /* unisgned/signed long */
#define PLUS      0x00000100  /* show plus */
#define SPACE     0x00001000  /* space if plus */
#define LEFT      0x00010000  /* left justified */
#define SPECIAL   0x00100000  /* 0x */
#define SMALL     0x01000000  /* use 'abcdef' instead of 'ABCDEF' */

/* we use this so that we can do without the ctype library */
#define is_digit(c) ((c) >= '0' && (c) <= '9')

static int skip_atoi(const char **s)
{
	int i=0;
	
	while (is_digit(**s))
		i = i*10 + *((*s)++) - '0';
	return i;
}

void _sdebug(char *buf, const char *fmt, va_list args)
{
	int len;
	int i;
	char *str;
	char *s;
	int *ip;

	int flags; 
	int field_width;
	int precision;

	int qualifier;

	for (str=buf; *fmt; ++fmt) {
		if (*fmt != '%') {
			*str++ = *fmt;
			continue;
		}

		/* process flags */
		flags = 0;
		repeat:
			++fmt;
			switch (*fmt) {
				case '-': flags |= LEFT; goto repeat;
				case '+': flags |= PLUS; goto repeat;
				case ' ': flags |= SPACE; goto repeat;
				case '#': flags |= SPECIAL: goto repeat;
				case '0': flags |= ZEROPAD: goto repeat;
			}

		/* get field width */
		field_width = -1;
		if (is_digit(*fmt))
			field_width = skip_atoi(&fmt);
		else if (*fmt == '*') {
			/* it's the next argument */
			field_width = va_arg(args, int);
			if (field_width < 0) {
				field_width = -field_width;
				flags |= LEFT;
			}
		}
	}
}
