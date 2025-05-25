/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_str.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: okuilboe <okuilboe@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/05/25 14:01:31 by okuilboe      #+#    #+#                 */
/*   Updated: 2025/05/25 14:02:40 by okuilboe      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

// File: tsts/test_str.c
#include <stdio.h>
#include "libft.h"
#include "ft_printf.h"
#include "test_defs.h"

static int test_str_format(const char *label, const char *fmt, const char *s)
{
	int ret_sys, ret_ft;

	ret_sys = printf("System printf  : ");
	ret_sys += printf(fmt, s);
	printf("\n");

	ret_ft = ft_printf("Your ft_printf : ");
	ret_ft += ft_printf(fmt, s);
	ft_printf("\n");

	if (ret_sys != ret_ft)
	{
		printf("❌ FAIL: %s\n", label);
		printf("   Format: %s\n", fmt);
		printf("   Arg: \"%s\"\n", s ? s : "(null)");
		printf("   printf() = %d, ft_printf() = %d\n", ret_sys, ret_ft);
		return 0;
	}
	return 1;
}

t_result run_str_format_tests(void)
{
	t_result result = {"String Format", 0, 0};

	t_testcase tests[] = {
		{"Basic string", "%s", "hello", 0},
		{"Right-aligned", "%10s", "hi", 0},
		{"Left-aligned", "%-10s", "yo", 0},
		{"Precision cut", "%.3s", "abcdef", 0},
		{"Prec + Width", "%10.3s", "abcdef", 0},
		{"Null string", "%s", NULL, 0},
		{NULL, NULL, NULL, 0}
	};

	for (int i = 0; tests[i].label; i++)
	{
		result.total++;
		if (test_str_format(tests[i].label, tests[i].format, tests[i].arg_str))
			result.passed++;
	}
	return result;
}