/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printfint.h                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: okuilboe <okuilboe@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/05/20 22:33:10 by okuilboe      #+#    #+#                 */
/*   Updated: 2025/05/26 16:27:48 by okuilboe      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINT_FINT_H

# define FT_PRINT_FINT_H

# include <stdarg.h>
# include "libft.h"
# include "ft_printf.h"
# include <stdio.h>

/**
 * Internal conversion helper functions for ft_printf().
 */
void	fn_handle_string_conversion(va_list args, t_format *fmt);
void	fn_handle_character_conversion(va_list args, t_format *fmt);
int		pad_residual_width(t_format *fmt);

/**
 * Iternal formatting parameter parsing helper functions for ft_printf().  
 */
int	parse_fmt_flags(char const *format, t_format *fmt);
int	parse_fmt_width(char const *format, t_format *fmt);
int	parse_fmt_prcis(char const *format, t_format *fmt);


#endif
