/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   handle_txt.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: okuilboe <okuilboe@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/06/02 12:07:07 by okuilboe      #+#    #+#                 */
/*   Updated: 2025/06/02 12:09:58 by okuilboe      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_int.h"
#include <unistd.h>
#include "libft.h"

/**
 * @brief String conversion formatting handler.
 * @param fmt struct storing ft_printf() formatting data and processing state.
 */
void	fn_handle_string_conversion(va_list args, t_format *fmt)
{
	char	*str;

	str = va_arg(args, char *);
	if (!str)
	{
		str = "(null)";
		if (fmt->precision)
			return ;
	}
	fmt->chars_to_print = ft_strlen(str);
	if (fmt->precision && fmt->precision_len < fmt->chars_to_print)
		fmt->chars_to_print = fmt->precision_len;
	if (fmt->width > fmt->chars_to_print)
		fmt->width_padding_len = fmt->width - fmt->chars_to_print;
	if (fmt->flag_minus)
	{
		fmt->prt_count += write(1, str, fmt->chars_to_print);
		fmt->prt_count += pad_residual_width(fmt);
	}
	else
	{
		fmt->prt_count += pad_residual_width(fmt);
		fmt->prt_count += write(1, str, fmt->chars_to_print);
	}
	return ;
}

/**
 * @brief Char conversion output handler.
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
