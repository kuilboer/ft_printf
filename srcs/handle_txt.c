/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   handle_txt.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: okuilboe <okuilboe@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/06/02 12:07:07 by okuilboe      #+#    #+#                 */
/*   Updated: 2025/06/04 19:36:10 by okuilboe      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_int.h"
#include <unistd.h>
#include "libft.h"

static int	null_input_error(char *str, t_format *fmt)
{
	char	*error;
	size_t	error_len;

	if (!str)
	{
		if (fmt->precision && fmt->precision_len < 6)
			error = 0;
		else
			error = "(null)";
		error_len = ft_strlen(error);
		if (fmt->width > error_len)
			fmt->width_padding_len = fmt->width - error_len;
		if (fmt->flag_minus)
		{
			fmt->prt_count += write(1, error, error_len);
			fmt->prt_count += pad_residual_width(fmt);
		}
		else
		{
			fmt->prt_count += pad_residual_width(fmt);
			fmt->prt_count += write(1, error, error_len);
		}
		return (1);
	}
	return (0);
}

/**
 * @brief String conversion formatting handler.
 * @param fmt struct storing ft_printf() formatting data and processing state.
 */
void	fn_handle_string_conversion(va_list args, t_format *fmt)
{
	char	*str;

	str = va_arg(args, char *);
	if (!null_input_error(str, fmt))
	{
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
	}
	return ;
}

static void	write_percent_character(char c, t_format *fmt)
{
	fmt->chars_to_print = 1;
	if (fmt->width > fmt->chars_to_print)
		fmt->width_padding_len = fmt->width - fmt->chars_to_print;
	if (fmt->flag_minus)
	{
		fmt->prt_count += write(1, &c, fmt->chars_to_print);
	}
	else
	{
		fmt->prt_count += write(1, &c, fmt->chars_to_print);
	}
}

/**
 * @brief Char conversion output handler.
 * @param fmt struct storing ft_printf() formatting data and processing state.
 * @returns void. function updates prt_count in the provided state struct.
 */
void	fn_handle_character_conversion(va_list args, t_format *fmt)
{
	char	c;

	if (fmt->conv_spec == '%')
	{
		c = '%';
		write_percent_character(c, fmt);
	}
	else
	{
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
	}
	return ;
}
