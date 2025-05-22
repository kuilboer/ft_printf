/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   textutils.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: okuilboe <okuilboe@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/05/22 17:11:20 by okuilboe      #+#    #+#                 */
/*   Updated: 2025/05/22 23:29:36 by okuilboe      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "printfint.h"
#include <unistd.h>

int	fn_chr(va_list args, t_format *fmt)
{
	char	c;
	char	*str;


	c = va_arg(args, char);
	str = 
	return (write(1, &c, 1));
}

int	fn_str(va_list args, t_format *fmt)
{
	char	*str;

	str = va_arg(args, char);
	return (write(1, str, ft_strlen(str)));
}

int	fn_prct(va_list args, t_format *fmt)
{
	return (write(1, "%", 1));
}
