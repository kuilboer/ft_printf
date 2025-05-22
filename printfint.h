/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   printfint.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: okuilboe <okuilboe@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/05/20 22:33:10 by okuilboe      #+#    #+#                 */
/*   Updated: 2025/05/22 14:14:03 by okuilboe      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTFINT_H

# define PRINTFINT_H

# include <stdarg.h>
# include "libft.h"
# include "libftprintf.h"

typedef int	(*t_handler)(va_list args);/* define a type that returns a 
										  ptr2func. takes a va_list as 
										  input; */

typedef struct s_convrs_handler
{
	char		specifier;
	t_handler	handler;
}	t_convrs_handler;

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

#endif
