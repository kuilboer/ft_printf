/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   handle_hex_format.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: okuilboe <okuilboe@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/05/29 13:43:33 by okuilboe      #+#    #+#                 */
/*   Updated: 2025/05/31 19:27:08 by okuilboe      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printfint.h"

static void format_width_padding(t_format *fmt)
{
	size_t		i;

	if (fmt->width && fmt->width > fmt->chars_to_print)
	{
		fmt->width_padding_str = malloc(sizeof(char) * fmt->width_padding_len + 1);
		if (!fmt->width_padding_str)
			return; 
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

static void format_calculate_value_output_length(t_format *fmt)
{
	if (fmt->num_sign)
		fmt->chars_to_print += 1;
	if (fmt->num_prefix_str)
		fmt->chars_to_print += 2;
	if (fmt->hex_precise_padding_str)
		fmt->chars_to_print += fmt->hex_precise_padding_len;
	fmt->chars_to_print += fmt->hex_string_len;
	if (fmt->width && fmt->width > fmt->chars_to_print)
		fmt->width_padding_len = fmt->width - fmt->chars_to_print; 
}

/**
 * @brief Precision padding is handled here.
 */
static void	format_hex_precision_padding(t_format *fmt)
{
	//char	*hex_precision_str;
	//size_t	fmt->hex_precise_padding_len;
	size_t	i;

	fmt->hex_precise_padding_len = fmt->precision_len - fmt->hex_string_len;
	if (fmt->precision && (fmt->precision_len > fmt->hex_string_len))
	{
		fmt->hex_precise_padding_str = malloc(sizeof(char) * fmt->hex_precise_padding_len + 1);
		if (!fmt->hex_precise_padding_str)
			return ;
		i =0;
		while (i < (fmt->hex_precise_padding_len))
			fmt->hex_precise_padding_str[i++] = '0';
		fmt->hex_precise_padding_str[i] = '\0';
		//ft_strlcpy(fmt->hex_precise_padding_str, hex_precision_str, fmt->hex_precise_padding_len + 1);
		return ; 
	}
}

/**
 * @brief	Convert *nbr to hex.
 * 			If required copy create a new streng with the length specified  by
 * 			fmt->precision_len. Copy hex to hex_precision right alligned 
 * 			pad the residual space left with '0'.
 * @param	nbr	pointer for which to get the hex address.
 * @param 	fmt	struct that tracks formatting settings and process state.
 * @return	hex	string containing the hex representation of *nbr address.
 * @return	hex_precision	string containing reformatted value of hex. 
 */
static void	format_hex_string(size_t nbr, t_format *fmt)
{
	char	*hex;
	hex = ft_utohex_trim((size_t)nbr, fmt->hex_upper);
	fmt->hex_string = hex;
	fmt->hex_input_nbr = nbr;
	fmt->hex_string_len = ft_strlen(fmt->hex_string);
	return ;
}

static void	format_hex_signage_and_prefix(t_format *fmt)
{
	if(fmt->flag_plus && fmt->flag_space)
		fmt->num_sign = '+';
	else if (fmt->flag_plus)
		fmt->num_sign = '+';
	else if (fmt->flag_space)
		fmt->num_sign = ' ';
	if (fmt->flag_hash && fmt->conv_spec == 'X')
	{
		fmt->hex_upper = 1;
		fmt->num_prefix_str = "0X";
	}
	else if (fmt->flag_hash)
		fmt->num_prefix_str = "0x";
}

/**
 * @brief	Configures ft_printf() formatting parameters before assembling and
 * writing out the different components of a hexadecimal number.
 * @param	nbr unsigned int to be converted to Hexadecimal.
 * @param	fmt read formatting parameters and store formatted output state. 
 */
void	format_hex_output_parameters(size_t nbr, t_format *fmt)
{
	format_hex_signage_and_prefix(fmt);
	format_hex_string(nbr, fmt);
	format_hex_precision_padding(fmt);
	format_calculate_value_output_length(fmt);
	format_width_padding(fmt);
	return ;
}