/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   handle_int_format.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: okuilboe <okuilboe@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/05/29 13:43:33 by okuilboe      #+#    #+#                 */
/*   Updated: 2025/06/04 20:15:51 by okuilboe      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_int.h"

static void	format_width_padding(t_format *fmt)
{
	size_t	i;

	if (fmt->width_padding_len)
	{
		fmt->width_padding_str = \
			malloc(sizeof(char) * fmt->width_padding_len + 1);
		if (!fmt->width_padding_str)
			return ;
		i = 0;
		if (fmt->flag_zero && !fmt->flag_minus && !fmt->precision)
			fmt->width_padding_chr = '0';
		else
			fmt->width_padding_chr = ' ';
		while (i < fmt->width_padding_len)
			fmt->width_padding_str[i++] = fmt->width_padding_chr;
		fmt->width_padding_str[i] = '\0';
	}
	return ;
}

static void	format_calculate_value_output_length(t_format *fmt)
{
	if (fmt->num_sign && fmt->conv_spec != 'u')
		fmt->chars_to_print += 1;
	if (fmt->num_precise_padding_str)
		fmt->chars_to_print += fmt->num_precise_padding_len;
	fmt->chars_to_print += fmt->num_string_len;
	if (fmt->width && fmt->width > fmt->chars_to_print)
		fmt->width_padding_len = fmt->width - fmt->chars_to_print;
	return ;
}

/**
 * @brief Precision padding is handled here.
 */
static void	format_int_precision_padding(t_format *fmt)
{
	size_t	i;

	if (fmt->precision && (fmt->precision_len > fmt->num_string_len))
	{
		fmt->num_precise_padding_len = fmt->precision_len - fmt->num_string_len;
		fmt->num_precise_padding_str = \
			malloc(sizeof(char) * fmt->num_precise_padding_len + 1);
		if (!fmt->num_precise_padding_str)
			return ;
		i = 0;
		while (i < (fmt->num_precise_padding_len))
			fmt->num_precise_padding_str[i++] = '0';
		fmt->num_precise_padding_str[i] = '\0';
		return ;
	}
}

static void	format_int_signage(t_format *fmt)
{
	if (fmt->input_nbr < 0)
		fmt->num_sign = '-';
	else if (fmt->flag_plus && fmt->flag_space)
		fmt->num_sign = '+';
	else if (fmt->flag_plus)
		fmt->num_sign = '+';
	else if (fmt->flag_space)
		fmt->num_sign = ' ';
}

/**
 * @brief	Configures ft_printf() formatting parameters before assembling and
 * writing out the different components of a hexadecimal number.
 * @param	nbr unsigned int to be converted to Hexadecimal.
 * @param	fmt read formatting parameters and store formatted output state. 
 */
void	format_int_output_parameters(t_format *fmt)
{
	if (fmt->conv_spec != 'u')
		format_int_signage(fmt);
	format_int_precision_padding(fmt);
	format_calculate_value_output_length(fmt);
	format_width_padding(fmt);
	return ;
}
