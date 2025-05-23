/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: okuilboe <okuilboe@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/05/19 20:43:24 by okuilboe      #+#    #+#                 */
/*   Updated: 2025/05/24 18:22:50 by okuilboe      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H

# define FT_PRINTF_H

# include <limits.h>
# include <stdarg.h>
# include <stdio.h>
#include "ft_printfint.h"

typedef struct s_format
{
	int		flag_minus;
	int		flag_zero;
	int		flag_space;
	int		flag_hash;
	int		flag_plus;
	int		width;
	int		precision;
	char	specifier;
}	t_format;

/* 
* typedef that returns a ptr2func. 
* and takes a va_list and format table as input;
*/
typedef int	(*t_handler)(va_list args, t_format *fmt);

/*
* formatter function lookup table definition
*/
typedef struct s_convrs_handler
{
	char		specifier;
	t_handler	handler;
}	t_convrs_handler;

int			ft_vfprintf(char const *format, va_list args);

int	fn_chr(va_list args, t_format *fmt);
int	fn_str(va_list args, t_format *fmt);
int	fn_prct(va_list args, t_format *fmt);

int	ft_printf(const char *format, ...);

#endif
