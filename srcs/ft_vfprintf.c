/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_vfprintf.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: okuilboe <okuilboe@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/05/22 00:00:15 by okuilboe      #+#    #+#                 */
/*   Updated: 2025/05/25 20:19:17 by okuilboe      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printfint.h"
#include <unistd.h>

static const t_convrs_handler	g_convrs_table[] = {
{'c', fn_chr},
{'s', fn_str},
{'\0', NULL}
};

// {'p', fn_ptr},
// {'d', fn_dgt},
// {'i', fn_int},
// {'u', fn_uns},
// {'x', fn_hexl},
// {'X', fn_hexu},

/*
Parse Flags:
Helper function for ft_vfprintf() that processes below flags from a formatting
substring and stores it in the tmp struct that is provided through the para-
meter 'fmt'.

Flags:

	'#' (hash ): The value should be converted to an "alternate form". For 'x' 
	             and 'X' conversions a nonzero result has the string "0x" (or
				 "0X" for 'X' conversions) prepended to it.
	'0' (zero ): left padding of field width with 0's(right aligned).
	'-' (minus): value is left alligned in its field (overwrites 0). the con-
	             verted value is padded on the right with blanks.
	' ' (space): print a space in front of positive int and digits where other-
	             wise the sign would be.
	'+' (plus ): enforce the use of a sign +/- on signed conversions. By default
	             a sign is only used for negative numbers. + overrides a space

Returns pointer delta value 'i'; 
*/
static int	parse_fmt_flags(char const *format, t_format *fmt)
{
	size_t	i;

	i = 0;
	while (*format == '-' || *format == '0' || *format == ' '
		|| *format == '+' || *format == '#')
	{
		if (*format == '-')
			fmt->flag_minus = 1;
		else if (*format == '0')
			fmt->flag_zero = 1;
		else if (*format == ' ')
			fmt->flag_space = 1;
		else if (*format == '+')
			fmt->flag_plus = 1;
		else if (*format == '#')
			fmt->flag_hash = 1;
		format++;
		i++;
	}
	return (i);
}

/*
Field width:

Helper function for ft_vfprintf() that processes a field width from a format-
ting substring and stores it in the tmp struct that is provided through the para-
meter 'fmt'.

(decimal with non 0 first digit): Specify the minimum field width. if the con-
                verted value has fewer chars than the field width , it will be
				padded with spaces to the left. In no case does a nonexistent
				or small field width cause truncation of a field; if the result
				of a conversion is wider than the field width, the field is ex-
				panded to contain the conversion result.

Returns pointer delta value 'i'; 
*/
static int	parse_fmt_width(char const *format, t_format *fmt)
{
	size_t	i;

	i = 0;
	while (ft_isdigit(*format))
	{
		fmt->width = fmt->width * 10 + (*format - '0');
		format++;
		i++;
	}
	return (i);
}

/*
Precision:

Helper function for ft_vfprintf() that processes Precision from a formatting
substring and stores it in the tmp struct that is provided through the para-
meter 'fmt'.

	'.' (dot  ): followed by an optional decimal digit string.If the precision
				 is given as just '.', the precision is taken to be zero.
				 This gives the minimum number of digits to appear for d, i, u,
				 x, and X conversions, or the maximum number of characters to 
				 be printed from a string for s and S conversions.

Returns pointer delta value 'i'; 
*/
static int	parse_fmt_prcis(char const *format, t_format *fmt)
{
	size_t	i;

	i = 0;
	if (format[i] == '.')
	{
		format++;
		i++;
		while (ft_isdigit(*format))
		{
			fmt->precision = fmt->precision * 10 + (*format - '0');
			format++;
			i++;
		}
	}
	return (i);
}

/*
Parse Formatting string:

This is a helper function for vftprintf() function. It abstracts an optional
formating substring, that is identified by a '%' char and which ends after the 
occurence of an alphabetic char that specifies the data conversion type to 
apply, from the 'format' string and stores it in a temporary struct 'fmt' for 
later processing. The order in which the different parts of the formatting sub-
string are parsed is as follows: 

%[flags][width][.precision]conversion

Returns pointer delta value 'i'; 
*/
static int	parse_formatting_string(char const *format, t_format *fmt)
{
	size_t	i;

	i = 0;
	i += parse_fmt_flags(&format[i], fmt);
	i += parse_fmt_width(&format[i], fmt);
	i += parse_fmt_prcis(&format[i], fmt);
	return (i);
}

/* 
vfprintf implements the heavy lifting for printf() it finds the regular chars
from string 'format'. end writes them to stdout. If it finds a '%' char
it parses the cuncurrent characters as a formatting substring upto the next occu-
rance of a % or an alphabetical character. the formatting parameters are stored
in the struct 'fmt'. 

Formatting string structure:
%[flags][width][.precision]conversion

The % or alpha char that terminates the formatting string signifies a conversion 
type specifier, the followint conversion are handled by ft_vfprintf():

 %c → Character: prints a single character.
 %s → String: prints a null-terminated string.
 %p → Pointer: prints a memory address in hexadecimal format, typically with 0x
 	  prefix.
 %d → Decimal (int): prints a signed decimal integer.
 %i → Integer: same as %d, prints a signed decimal integer.
 %u → Unsigned decimal: prints an unsigned decimal integer.
 %x → Hex lowercase: prints an unsigned number in base 16 using lowercase le-
      tters (a–f).
 %X → Hex uppercase: same as %x but with uppercase letters (A–F).
 %% → Literal percent sign: prints a single %.

*/
int	ft_vfprintf(char const *format, va_list args)
{
	t_format	fmt;
	size_t		i;
	size_t		ti;
	size_t		prt_count;

	prt_count = 0;
	i = 0;
	while (format && format[i])
	{
		if (format[i + 1] && format[i] == '%' && format[i + 1] == '%')
			i++;
		else if (format[i] == '%' && format[i + 1])
		{
			fmt = (t_format){0};
			i++;
			i += parse_formatting_string(&format[i], &fmt);
			ti = 0;
			while (g_convrs_table[ti].specifier
				&& g_convrs_table[ti].specifier != format[i])
				ti++;
			prt_count += g_convrs_table[ti].handler(args, &fmt);
			i++;
		}
		if (format[i])
		{
			prt_count += write(1, &format[i], 1); //ft_putchar_fd(format[i], 1);
			i++;
		}
	}
	return (prt_count);
}
