/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_vfprintf.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: okuilboe <okuilboe@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/05/22 00:00:15 by okuilboe      #+#    #+#                 */
/*   Updated: 2025/06/02 16:05:37 by okuilboe      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_int.h"
#include <unistd.h>

static const t_convrs_handler	g_convrs_table[] = {
{'c', fn_handle_character_conversion},
{'s', fn_handle_string_conversion},
{'p', fn_handle_pointer_conversion},
{'x', fn_handle_hexadec_conversion},
{'X', fn_handle_hexadec_conversion},
{'\0', NULL}
};

// {'d', fn_dgt},
// {'i', fn_int},
// {'u', fn_uns},

/**
 * @brief Manage initialization and freeing of formatting state struct variables
 * 
 * Only struct members are allowed to be dynamically allocated. Any dynamic
 * members MUST be declared in this function so they can be properly released
 * as intended.
 */
static void	free_and_initialize_format_stuct(t_format *fmt)
{
	if (fmt->hex_string)
		free(fmt->hex_string);
	if (fmt->hex_precise_padding_str)
		free(fmt->hex_precise_padding_str);
	if (fmt->width_padding_str)
		free(fmt->width_padding_str);
	*fmt = (t_format){0};
}

static int	run_conversion_handler(va_list args, \
	char const *format, t_format *fmt)
{
	size_t	i;

	i = 0;
	while (g_convrs_table[i].specifier
		&& g_convrs_table[i].specifier != fmt->conv_spec)
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

	fmt = (t_format){0};
	prt_count = 0;
	i = 0;
	while (format && format[i])
	{
		if (format[i + 1] && format[i] == '%' && format[i + 1] == '%')
			i++;
		else if (format[i] == '%' && format[i + 1])
		{
			i += parse_formatting_string(&format[i], &fmt);
			prt_count += run_conversion_handler(args, &format[i], &fmt);
			free_and_initialize_format_stuct(&fmt);
		}
		if (!format[i])
			break ;
		prt_count += write(1, &format[i], 1);
		i++;
	}
	return (prt_count);
}
