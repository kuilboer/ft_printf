/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: okuilboe <okuilboe@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/05/22 21:40:22 by okuilboe      #+#    #+#                 */
/*   Updated: 2025/05/25 10:00:17 by okuilboe      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_test.h"

int main(void)
{
  printf("01[%-3c]8", '3');
  printf("\n");
  ft_printf("01[%-3c]8", '3');
 // printf("char zeroed: [%05c]\n", 'a');
 // printf("char padded: [% 5c]\n", 'a');
  //printf("char minusd: [%-5c]\n", 'a');
 //printf("char plussd: [%+5c]\n", 'a');
}

