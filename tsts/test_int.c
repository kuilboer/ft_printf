/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_int.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: okuilboe <okuilboe@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/05/25 13:58:00 by okuilboe      #+#    #+#                 */
/*   Updated: 2025/06/03 15:58:18 by okuilboe      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"
#include "ft_printf.h"
#include "test_defs.h"

typedef struct s_testcase
{
	const char 		*label;
	const char 		*format;
	unsigned int	arg_uint; // voor hex and pointer
} t_testcase;

static int test_int_format(const char *label, const char *fmt, long long nbr)
{
	int ret_sys, ret_ft;

	//printf("\n=== Test: %s ===\n", label);
	ret_sys = printf("System printf  : ");
	ret_sys += printf(fmt, nbr);
	printf("\n");

	ret_ft = ft_printf("Your ft_printf : ");
	ret_ft += ft_printf(fmt, nbr);
	ft_printf("\n");

	if (ret_sys != ret_ft)
	{
		printf("❌ FAIL: %s\n", label);
		printf("   Format: %s\n", fmt);
		printf("   Arg: '%u'\n", (unsigned int)nbr ? (unsigned int)nbr : 0);
		printf("   printf() = %d, ft_printf() = %d\n", ret_sys, ret_ft);
		return 0;
	}
	return 1;
}

t_result run_int_format_tests(void)
{
	t_result result = {"Integer format", 0, 0};

// 	t_testcase tests[] = {
// 		// {"int", "[%i]", 42},
// 		// {"zero", "[%i]", 0},
// 		// {"zero with precision.", "[%.i]", 0},
// 		// {"zero with precision 5.", "[%.5i]", 0},
// 		// {"zero with precision + width.", "[%5.i]", 0},
// 		// {"zero with precision 5 + width.", "[%5.5i]", 0},
// 		// {"zero with precision 5 + width + flag-0.", "[%010.5i]", 0},
// 		// {"zero with precision 0", "[%.0i]", 0},
// 		// {"zero with precision 0 + width", "[%5.0i]", 0},
// 		// {"int with precision 5 + width + flag-0.", "[%010.5i]", 42},
// 		// {"-int with precision 5 + width + flag-0.", "[%010.5i]", -42},
// 		// {"int with precision 5 + width + flag-0.", "[%-010.5i]", 42},
// 		// {"-int with precision 5 + width + flag-0.", "[%-010.5i]", -42},
// 		// {"-int with precision 5 + width + flag-0.", "[%-010.5i]", INT_MIN},
// 		// {"-int with precision 5 + width + flag-0.", "[%-010.5i]", -2147483648},
// 		// {"-int with precision 5 + width + flag-0.", "[%-010.5i]", INT_MAX},
// 		// {"-int with precision 5 + width + flag-0.", "[%-010.5i]", 2147483650},
// 		// {"INT_MAX with width + flag-0.", "[%010i]", INT_MAX},
// 		// {"INT_MAX with width only.", "[%10i]", INT_MAX},
// 		// {"-INT_MIN with width + flag-0.", "[%010i]", INT_MIN},
// 		// {"-INT_MIN with width only.", "[%10i]", INT_MIN},
// 		// {"int with space", "[% i]", 42},
// 		// {"int with plus", "[%+i]", 42},
// 		// {"-int with space", "[% i]", -42},
// 		// {"-int with plus", "[%+i]", -42},
// 		// {"-int with plus", "[%05i]", -42},
// 		// {"int with space + width", "[% 20i]", 42},
// 		// {"int with plus + width", "[%+20i]", 42},
// 		// {"plus + precision", "[%+.5i]", 42},
// 		// {"space + precision", "[% .5i]", 42},
// 		// {"plus + width + precision", "[%+10.5i]", 42},
// 		// {"space + width + precision", "[% 10.5i]", 42},
// 		// {"plus + zero value + precision 0", "[%+.0i]", 0},
// 		// {"space + zero value + precision 0", "[% .0i]", 0},
// 		{"int", "[%u]", 42},
// 		{"zero", "[%u]", 0},
// 		{"zero with precision.", "[%.u]", 0},
// 		{"zero with precision 5.", "[%.5u]", 0},
// 		{"zero with precision + width.", "[%5.u]", 0},
// 		{"zero with precision 5 + width.", "[%5.5u]", 0},
// 		{"zero with precision 5 + width + flag-0.", "[%010.5u]", 0},
// 		{"zero with precision 0", "[%.0u]", 0},
// 		{"zero with precision 0 + width", "[%5.0u]", 0},
// 		{"int with precision 5 + width + flag-0.", "[%010.5u]", 42},
// 		{"-int with precision 5 + width + flag-0.", "[%010.5u]", -42},
// 		{"int with precision 5 + width + flag-0.", "[%-010.5u]", 42},
// 		{"-int with precision 5 + width + flag-0.", "[%-010.5u]", -42},
// 		{"-int with precision 5 + width + flag-0.", "[%-010.5u]", INT_MIN},
// 		{"-int with precision 5 + width + flag-0.", "[%-010.5u]", -2147483648},
// 		{"-int with precision 5 + width + flag-0.", "[%-010.5u]", INT_MAX},
// 		{"-int with precision 5 + width + flag-0.", "[%-010.5u]", 2147483650},
// 		{"INT_MAX with width + flag-0.", "[%010u]", INT_MAX},
// 		{"INT_MAX with width only.", "[%10u]", INT_MAX},
// 		{"-INT_MIN with width + flag-0.", "[%010u]", INT_MIN},
// 		{"-INT_MIN with width only.", "[%10u]", INT_MIN},
// 		{"int with space", "[% u]", 42},
// 		{"int with plus", "[%+u]", 42},
// 		{"-int with space", "[% u]", -42},
// 		{"-int with plus", "[%+u]", -42},
// 		{"-int with plus", "[%05u]", -42},
// 		{"int with space + width", "[% 20u]", 42},
// 		{"int with plus + width", "[%+20u]", 42},
// 		{"plus + precision", "[%+.5u]", 42},
// 		{"space + precision", "[% .5u]", 42},
// 		{"plus + width + precision", "[%+10.5u]", 42},
// 		{"space + width + precision", "[% 10.5u]", 42},
// 		{"plus + zero value + precision 0", "[%+.0u]", 0},
// 		{"space + zero value + precision 0", "[% .0u]", 0},
// 		{NULL, NULL, 0}
// };

t_testcase tests[] = {

    // %d
    // {"Basic positive", "[%d]", 42},
    // {"Basic negative", "[%d]", -42},
    // {"Zero", "[%d]", 0},
    // {"INT_MAX", "[%d]", 2147483647},
    // {"INT_MIN", "[%d]", -2147483648},

    // {"Width", "[%5d]", 42},
    // {"Width negative", "[%5d]", -42},
    // {"Zero-padding", "[%05d]", 42},
    // {"Zero-padding negative", "[%05d]", -42},

    // {"Precision", "[%.3d]", 42},
    // {"Precision negative", "[%.3d]", -42},
    // {"Precision 0 with zero", "[%.0d]", 0},
    // {"Width + Precision", "[%5.3d]", 42},
    // {"Width + Precision negative", "[%5.3d]", -42},

    // {"Left-align", "[%-5d]", 42},
    // {"Left-align negative", "[%-5d]", -42},

    // {"Space", "[% d]", 42},
    // {"Space negative", "[% d]", -42},

    // {"Plus", "[%+d]", 42},
    // {"Plus negative", "[%+d]", -42},

    // {"Space + Width", "[% 5d]", 42},
    // {"Plus + Width", "[%+5d]", 42},
    // {"Plus + Zero-padding", "[%+05d]", 42},

    // {"Illegal combo %-05d", "[%-05d]", 42},

    // // %i — same as %d
    // {"Basic positive i", "[%i]", 42},
    // {"Basic negative i", "[%i]", -42},
    // {"Zero i", "[%i]", 0},
    // {"INT_MAX i", "[%i]", 2147483647},
    // {"INT_MIN i", "[%i]", -2147483648},

    // %u
    // {"Basic unsigned", "[%u]", 42},
    // {"Zero unsigned", "[%u]", 0},
    // {"UINT_MAX", "[%u]", 4294967295U},
    // {"Width 5 unsigned", "[%5u]", 42},
    // {"Zero-padding width 5 unsigned", "[%05u]", 42},
    // {"Precision 3 unsigned", "[%.3u]", 42},
    // {"Precision 0 with zero unsigned", "[%.0u]", 0},
    // {"Width 5 precision 3 unsigned", "[%5.3u]", 42},
    // {"Left-align width 5 unsigned", "[%-5u]", 42},
    // {"Space flag ignored on unsigned", "[% u]", 42},
    // {"Plus flag ignored on unsigned", "[%+u]", 42},
    // {"Zero unsigned", "[%u]", 0},
    // {"UINT_MAX", "[%u]", 4294967295U},

    // {"Width unsigned", "[%5u]", 42},
    // {"Zero-padding unsigned", "[%05u]", 42},

    // {"Precision unsigned", "[%.3u]", 42},
    // {"Precision 0 with zero unsigned", "[%.0u]", 0},
    // {"Width + Precision unsigned", "[%5.3u]", 42},

    // {"Left-align unsigned", "[%-5u]", 42},

    // {"Space flag ignored", "[% u]", 42},
    // {"Plus flag ignored", "[%+u]", 42},

    // {"Space + Width unsigned", "[% 5u]", 42}, // Should behave like just width
    // {"Plus + Width unsigned", "[%+5u]", 42},  // Should behave like just width

    // {"Illegal combo %-05u", "[%-05u]", 42},

	{"Pointer NULL left-aligned", "[%-15p]", (unsigned long)NULL},

	{NULL, NULL, 0}
};


	for (int i = 0; tests[i].label; i++)
	{
		result.total++;
		printf("INT_TEST [%2d] - %s - %s \n", i, tests[i].format, tests[i].label);
		if (test_int_format(tests[i].label, tests[i].format, tests[i].arg_uint))
			result.passed++;
	}
	return result;
} 

