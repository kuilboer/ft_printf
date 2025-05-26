/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_vfprintf.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: okuilboe <okuilboe@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/05/22 00:00:15 by okuilboe      #+#    #+#                 */
/*   Updated: 2025/05/26 17:17:30 by okuilboe      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printfint.h"
#include <unistd.h>

static const t_convrs_handler	g_convrs_table[] = {
{'c', fn_handle_character_conversion},
{'s', fn_handle_string_conversion},
{'\0', NULL}
};

// {'p', fn_ptr},
// {'d', fn_dgt},
// {'i', fn_int},
// {'u', fn_uns},
// {'x', fn_hexl},
// {'X', fn_hexu},

static int	run_conversion_handler(va_list args, char const *format, t_format *fmt)
{
	size_t i;

	i = 0;
	while (g_convrs_table[i].specifier
		&& g_convrs_table[i].specifier != *format)
		i++;
	if (!g_convrs_table[i].specifier)
	{
		fmt->prt_count += write(1, "%", 1);
		fmt->prt_count += write(1, format, 1);
	}
	else
		g_convrs_table[i].handler(args, fmt);
	return (fmt->prt_count);
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
	fmt->read_index = 1;
	fmt->read_index += parse_fmt_flags(&format[fmt->read_index], fmt);
	fmt->read_index += parse_fmt_width(&format[fmt->read_index], fmt);
	fmt->read_index += parse_fmt_prcis(&format[fmt->read_index], fmt);
	return (fmt->read_index);
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
	size_t		prt_count;
	size_t		i;

	prt_count = 0;
	i = 0;
	while (format && format[i])
	{
		if (format[i + 1] && format[i] == '%' && format[i + 1] == '%')
			i++;
		else if (format[i] == '%' && format[i + 1])
		{
			fmt = (t_format){0};
			i += parse_formatting_string(&format[i], &fmt);
			prt_count += run_conversion_handler(args, &format[i], &fmt);
			i++;
		}
		if (!format[i])
			break ;
		prt_count += write(1, &format[i], 1); //ft_putchar_fd(format[i], 1);
		i++;
	}
	return (prt_count);
}
