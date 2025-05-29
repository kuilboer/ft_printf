/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   handle_hex_format.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: okuilboe <okuilboe@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/05/29 13:43:33 by okuilboe      #+#    #+#                 */
/*   Updated: 2025/05/29 20:46:09 by okuilboe      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printfint.h"

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

static void format_width_padding(t_format *fmt)
{
	char	*padding_string;
	size_t		i;

	padding_string = malloc(sizeof(char) * fmt->width_padding_len + 1);
	if (!padding_string)
		return; 
	i = 0;
	if (fmt->flag_zero && !fmt->flag_minus && !fmt->precision)
		fmt->width_padding_chr = '0';
	else
		fmt->width_padding_chr = ' ';
	while (i < fmt->width_padding_len)
		padding_string[i++] = fmt->width_padding_chr = '0';
	ft_strlcpy(fmt->width_padding_str, padding_string, fmt->width_padding_len);
	free(padding_string);
	return ;
}

/**
 * @brief Precision padding is handled here.
 */
static void	format_hex_precision_padding(t_format *fmt)
{
	size_t	hex_len;
	char	*hex_precision_str;
	size_t	hex_precision_len;
	size_t	i;

	hex_len = ft_strlen(fmt->hex_string);
	hex_precision_len = fmt->precision_len - hex_len;
	if (fmt->precision && (fmt->precision_len > hex_len))
	{
		hex_precision_str = malloc(sizeof(char) * hex_precision_len + 1);
		if (!hex_precision_str)
			return ;
		i =0;
		while (i < (fmt->precision_len - hex_len))
			hex_precision_str[i++] = '0';
		hex_precision_str[i] = '\0';
		ft_strlcpy(fmt->hex_precise_padding_str, hex_precision_str, hex_precision_len + 1);
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
	size_t	hex_len;
	
	hex = ft_utohex_trim((size_t)nbr, fmt->hex_upper);
	hex_len = ft_strlen(hex);
	ft_strlcpy(fmt->hex_string, hex, hex_len + 1);
	free(hex);
	return ;
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
	format_width_padding(fmt);
	return ;
}