/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   textutils.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: okuilboe <okuilboe@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/05/22 17:11:20 by okuilboe      #+#    #+#                 */
/*   Updated: 2025/05/25 10:30:32 by okuilboe      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printfint.h"
#include <unistd.h>
#include "libft.h"

/*
* fn_chr() handles the conversion of character based conversions in the string.
* it takes the a va_list for the source of the actual character to print and a
* t_format types struct that holds the formatting parameters. for printing. 
*/
int	fn_chr(va_list args, t_format *fmt)
{
	char	c;
	int		count;
	int		i;

	c = (char)va_arg(args, int);
	count = 0;
	i = 0;
	if (fmt->flag_minus || fmt->flag_zero)
	{
		count = write(1, &c, 1);
		i++;
	}
	else
		i++;
	while (i < fmt->width || i < fmt->precision)
	{
		count += write(1, " ", 1);
		i++;
	}
	if (!fmt->flag_minus && !fmt->flag_zero)
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

