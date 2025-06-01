/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   handle_char.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: okuilboe <okuilboe@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/05/25 21:56:19 by okuilboe      #+#    #+#                 */
/*   Updated: 2025/06/01 16:41:57 by okuilboe      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_int.h"
#include "libft.h"
#include <unistd.h>

/**
 * @brief String conversion output handler
 * @param fmt struct storing ft_printf() formatting data and processing state.
 * @returns void. function updates prt_count in the provided state struct.
 */
void	fn_handle_character_conversion(va_list args, t_format *fmt)
{
	char	c;

	c = (char)va_arg(args, int);
	fmt->chars_to_print = 1;
	if (fmt->width > fmt->chars_to_print)
		fmt->width_padding_len = fmt->width - fmt->chars_to_print;
	if (fmt->flag_minus)
	{
		fmt->prt_count += write(1, &c, fmt->chars_to_print);
		fmt->prt_count += pad_residual_width(fmt);
	}
	else
	{
		fmt->prt_count += pad_residual_width(fmt);
		fmt->prt_count += write(1, &c, fmt->chars_to_print);
	}
	return ;
}
