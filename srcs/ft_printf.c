/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: okuilboe <okuilboe@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/05/19 20:15:01 by okuilboe      #+#    #+#                 */
/*   Updated: 2025/05/24 18:35:50 by okuilboe      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdarg.h>
#include "ft_printf.h"
#include "libft.h"

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		done;

	va_start(args, format);
	done = ft_vfprintf(format, args);
	va_end(args);
	return (done);
}
