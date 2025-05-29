/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: okuilboe <okuilboe@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/05/19 20:43:24 by okuilboe      #+#    #+#                 */
/*   Updated: 2025/05/29 14:01:06 by okuilboe      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H

# define FT_PRINTF_H

# include <limits.h>
# include <stdarg.h>
# include <stdio.h>

int	ft_vfprintf(char const *format, va_list args);

// int	fn_chr(va_list args, t_format *fmt);
// int	fn_str(va_list args, t_format *fmt);
// int	fn_prct(va_list args, t_format *fmt);

int	ft_printf(const char *format, ...);
char *ft_utohex_raw(size_t n, int uppercase);
char *ft_utohex_trim(size_t n, int uppercase);

#endif
