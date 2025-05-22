/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: okuilboe <okuilboe@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/05/19 20:15:01 by okuilboe      #+#    #+#                 */
/*   Updated: 2025/05/22 14:08:54 by okuilboe      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdarg.h>
#include <stdio.h>
#include "printfint.h"
#include "libft.h"

int	ft_printf(const char *format, ...)
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
