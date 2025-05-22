/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   printfint.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: okuilboe <okuilboe@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/05/20 22:33:10 by okuilboe      #+#    #+#                 */
/*   Updated: 2025/05/22 23:09:49 by okuilboe      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTFINT_H

# define PRINTFINT_H

# include <stdarg.h>
# include "libft.h"
# include "libftprintf.h"

/*
* definition for struct for temporary storage of formatting parameters
* found in print string. 
*/
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

#endif
