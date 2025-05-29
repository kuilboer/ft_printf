/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   handler_utils.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: okuilboe <okuilboe@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/05/26 10:19:21 by okuilboe      #+#    #+#                 */
/*   Updated: 2025/05/29 16:14:05 by okuilboe      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printfint.h"
#include <unistd.h>

/**
* @brief Blank space padding for ft_vfprintf().
* @param fmt struct providing formatting flag state like flag_zero and pad_size. 
* @returns The nuber of bytes written to stdout.  
*/ 
int	pad_residual_width(t_format *fmt)
{
	char pad_char;
	size_t	i;

	i = 0;
	if (fmt->flag_zero)
		pad_char = '0';
	else
		pad_char = ' ';
	while (i < fmt->width_padding_len)
	{
		write(1, &pad_char, 1);
		i++;
	}
	return (i);
}
