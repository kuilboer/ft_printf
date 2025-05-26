/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   textutils.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: okuilboe <okuilboe@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/05/22 17:11:20 by okuilboe      #+#    #+#                 */
/*   Updated: 2025/05/23 16:02:58 by okuilboe      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "printfint.h"
#include <unistd.h>
#include "libft.h"

int	fn_chr(va_list args, t_format *fmt)
{
	char	c;
	int		count;
	int		i;

	c = (char)va_arg(args, int);
	count = 0;
	i = 0;
	if (fmt->flag_minus)
	{
		count = write(1, &c, 1);
		i++;
	}
	while (i < fmt->width || i < fmt->precision)
	{
		count += write(1, " ", 1);
		i++;
	}
	if (fmt->flag_minus)
	{
		count = write(1, &c, 1);
		i++;
	}
	return (count);
}

int	fn_str(va_list args, t_format *fmt)
{
	char	*str;
	int		count;
	int		i;

	str = va_arg(args, char *);
	count = 0;
	i = 0;
	if (fmt->flag_minus)
	{
		count = write(1, str, ft_strlen(str));
		i++;
	}
	while (i < fmt->width || i < fmt->precision)
	{
		count += write(1, " ", 1);
		i++;
	}
	if (fmt->flag_minus)
	{
		count = write(1, str, ft_strlen(str));
		i++;
	}
	return (count);
}

