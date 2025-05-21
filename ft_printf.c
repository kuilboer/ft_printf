/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: okuilboe <okuilboe@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/05/19 20:15:01 by okuilboe      #+#    #+#                 */
/*   Updated: 2025/05/22 01:18:16 by okuilboe      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdarg.h>
#include <stdio.h>
#include "printfint.h"
#include "libft.h"



int ft_printf(const char *format, ...)
{
	t_convrs_handler	convrs_table[10];
	va_list				args;
	int					done;

	convrs_table[0] = (t_convrs_handler){'c', fn_chr};
	convrs_table[1] = (t_convrs_handler){'s', fn_str};
	convrs_table[2] = (t_convrs_handler){'p', fn_ptr};
	convrs_table[3] = (t_convrs_handler){'d', fn_dgt};
	convrs_table[4] = (t_convrs_handler){'i', fn_int};
	convrs_table[5] = (t_convrs_handler){'u', fn_uns};
	convrs_table[6] = (t_convrs_handler){'x', fn_hexl};
	convrs_table[7] = (t_convrs_handler){'X', fn_hexu};
	convrs_table[8] = (t_convrs_handler){'%', fn_prct};
	convrs_table[9] = (t_convrs_handler){'\0', NULL};

	va_start(args, format);
	done = ft_vfprintf(stdout, format, args);
	va_end(args);
	return (done);
}




	/*
	1 .Create a function int myprintf() with const char* and '...' as its parameters.
		('. . .' enables the function to receive any number of arguments).
    2. Initialize a pointer of type va_list to work with variable arguments. Pass the pointer to va_start.
    3. Process the passed string with a delimiter as '%' or '\0', and store it in a token string.
    4. For every token starting with '%' check if its next characters are a format specifier defined in C. It can be 'i','s','lf'.
    5. Pass the token string and value retrieved from va_arg() to fprintf() in order to print the required value to the console.
    6. Once the whole string is processed, end the va_arg pointer.
    Return 0.

	*/


// %c → Character: prints a single character.
// %s → String: prints a null-terminated string.
// %p → Pointer: prints a memory address in hexadecimal format, typically with 0x prefix.
// %d → Decimal (int): prints a signed decimal integer.
// %i → Integer: same as %d, prints a signed decimal integer.
// %u → Unsigned decimal: prints an unsigned decimal integer.
// %x → Hex lowercase: prints an unsigned number in base 16 using lowercase letters (a–f).
// %X → Hex uppercase: same as %x but with uppercase letters (A–F).
// %% → Literal percent sign: prints a single %.

/*
	- (minus) 	left-align the output in its field width;
					%-5d --> [42   ];
	0 (zero)	Pad with zeros instead of spaces (right aligned);
					%05d --> [00042];
	. (dot)		Indicates precision:
					- For strings: max characters to print --> %.3s --> abc
					- For integers: min digits, padded with zeros --> %.5d --> 00042
	# (hashtag)	Adds a prefix:
					- %#x --> 0x1a
					- %#X --> 0X1A
	' ' (space)	Adds a leading space before positive numbers (if no sign)
					% d --> [ 42];
	+ (plus)	Forces display of the sign for numbers
				AND overwrites the space flag.access
					%+d		--> [+42]
					%-+d	--> [  +42]
					%0+d	--> [+0042]

*/