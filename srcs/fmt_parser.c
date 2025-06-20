/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fmt_parser.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: okuilboe <okuilboe@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/05/26 15:50:25 by okuilboe      #+#    #+#                 */
/*   Updated: 2025/06/09 18:52:37 by okuilboe      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_int.h"

static int	parse_fmt_conversion(char const *format, t_format *fmt)
{
	size_t	i;

	i = 0;
	if (!*format)
		return (0);
	fmt->conv_spec = *format;
	if (fmt->conv_spec == 'X')
		fmt->hex_upper = 1;
	if (fmt->conv_spec == 'p')
		fmt->flag_hash = 1;
	i++;
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
static int	parse_fmt_precision(char const *format, t_format *fmt)
{
	size_t	i;

	i = 0;
	if (*format == '.')
	{
		fmt->precision = '.';
		format++;
		i++;
		while (ft_isdigit(*format))
		{
			fmt->precision_len = fmt->precision_len * 10 + (*format - '0');
			format++;
			i++;
		}
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
int	parse_formatting_string(char const *format, t_format *fmt)
{
	fmt->read_index = 1;
	fmt->read_index += parse_fmt_flags(&format[fmt->read_index], fmt);
	fmt->read_index += parse_fmt_width(&format[fmt->read_index], fmt);
	fmt->read_index += parse_fmt_precision(&format[fmt->read_index], fmt);
	fmt->read_index += parse_fmt_conversion(&format[fmt->read_index], fmt);
	return (fmt->read_index);
}
