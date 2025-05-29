/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   handle_str.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: okuilboe <okuilboe@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/05/22 17:11:20 by okuilboe      #+#    #+#                 */
/*   Updated: 2025/05/29 16:14:05 by okuilboe      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printfint.h"
#include <unistd.h>
#include "libft.h"

/**
 * @brief String conversion formatting handler
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
	if(fmt->width > fmt->chars_to_print)
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
