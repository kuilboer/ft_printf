/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: okuilboe <okuilboe@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/05/22 21:40:22 by okuilboe      #+#    #+#                 */
/*   Updated: 2025/05/23 18:00:22 by okuilboe      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_test.h"
#include "libftprintf.h"

int main(void)
{
  
  printf("System function\t|| ft_function\n");
  printf("char: [%c]\t|| "  , 'a');
  //ft_printf("char       : [%c]\n"  , 'a');
 // printf("char zeroed: [%05c]\n", 'a');
 // printf("char padded: [% 5c]\n", 'a');
  //printf("char minusd: [%-5c]\n", 'a');
 //printf("char plussd: [%+5c]\n", 'a');
}

