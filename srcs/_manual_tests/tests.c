/* ************************************************************************** */
/*																			*/
/*														 ::::::::		   */
/*   tests.c											 :+:	:+:		   */
/*													  +:+				   */
/*   By: tgritske <marvin@42.fr>					   +#+					*/
/*													+#+					 */
/*   Created: 2025/05/02 16:32:32 by tgritske	   #+#	#+#				*/
/*   Updated: 2025/05/09 19:48:54 by tgritske	   ########   odam.nl		*/
/*																			*/
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "../ft_printf.h"

#define RED	 "\033[1;31m"
#define GREEN   "\033[1;32m"
#define YELLOW  "\033[1;33m"
#define BLUE	"\033[1;34m"
#define MAGENTA "\033[1;35m"
#define CYAN	"\033[1;36m"
#define RESET   "\033[0m"

void compare_returns(int std_ret, int ft_ret)
{
	printf("Return value comparison: std=%d, ft=%d - %s\n", std_ret, ft_ret,
		   std_ret == ft_ret ? GREEN "MATCH" RESET : RED "DIFFER" RESET);
}

#define COMPARE_PRINTF(format, ...) do { \
	int std_ret = printf(format, __VA_ARGS__); \
	int ft_ret = ft_printf(format, __VA_ARGS__); \
	compare_returns(std_ret, ft_ret); \
} while (0)

// cspdiuxX% and
// '-'(left-justify with given width)
// '0'(left-pads the number with zeroes instead of spaces, when padding is specified)
// '.'(precision?)
// '#'(used with o, x, X - specifiers the value is preceeded with 0,0x,0X for values different than zero )
// ' ' - if no sign is go to be written, a blank space is inserted before the value
// '+' - forces to preceed the result with a plus or minus sign even for positive numbers.
int main() {
	int std_ret, ft_ret;
	void *ptr = NULL;

	COMPARE_PRINTF("-1): %%s;\n", NULL);

	std_ret =	printf(NULL);
	ft_ret = ft_printf(NULL);
	compare_returns(std_ret, ft_ret);

	COMPARE_PRINTF("-1): %%s;\n", NULL);
	COMPARE_PRINTF("0): %%p;\n", NULL);
	COMPARE_PRINTF("1): %d\n", 42);

	std_ret =	printf("2): %%%\n");
	ft_ret = ft_printf("2): %%%\n");
	compare_returns(std_ret, ft_ret);


	std_ret =   printf("3): %%%");
	printf("\n");
	ft_ret = ft_printf("3): %%%");
	printf("\n");
	compare_returns(std_ret, ft_ret);

	COMPARE_PRINTF("4): int width trick: \"%+0*d\" \n", 20, 23);

	std_ret =   printf("5): wrong spec(undefined behaviour): %10w ;\n");
	ft_ret = ft_printf("5): wrong spec(undefined behaviour): %10w ;\n");
	compare_returns(std_ret, ft_ret);

	std_ret =   printf("6): wrong spec(undefined behaviour): %w ;\n");
	ft_ret = ft_printf("6): wrong spec(undefined behaviour): %w ;\n");
	compare_returns(std_ret, ft_ret);

	COMPARE_PRINTF("7) negative decimal with space flag: % d ;\n", -123);
	COMPARE_PRINTF("8) negative hex with space flag: % x %x %x;\n", -128, -1, -2);
	COMPARE_PRINTF("9) positive hex with space flag: % x ;\n", 123);
	COMPARE_PRINTF("10) zero hex with space flag: % x ;\n", 0);
	COMPARE_PRINTF("11): correct spec and then wrong spec: %*d %w %d;\n", 5, 10, 20);
	COMPARE_PRINTF("12): With # flag lowercase: \"%#x;\n", 255);
	COMPARE_PRINTF("13): With complex #+width flag lowercasecase: \"%#10x;\n", 255);
	COMPARE_PRINTF("14): Different radices combo: \"%d %x %w %#x %#w;\n", 100, 100, 100, 100, 100);
	COMPARE_PRINTF("15): Complex format:|%-10.2s|%5d|%#10x|%5%|\n", "hello", 42, 255);
	COMPARE_PRINTF("16): Width trick with *: \"%*d;\n", 5, 10);
	COMPARE_PRINTF("17): Two nil pointer: %p %p;\n", 0, 0);
	COMPARE_PRINTF("18): All decimal number:  %d %d %d %d %d %d %d;\n", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);
	COMPARE_PRINTF("19): %.03s;\n", NULL);
	COMPARE_PRINTF("20): Complex combination 1:Char: %c, Str: %s, Dec: %d, Hex: %x, Ptr: %p;\n", 'X', "test", 42, 255, ptr);
	COMPARE_PRINTF("21): Complex combination 2:|%-10.2s|%5d|%#10x|%5%|;\n", "hello", 42, 255);
	COMPARE_PRINTF("22): Complex combination 3:%+ -*.3c %#10.5x %0*d;\n", 20, 'a', 255, 10, 42);
	COMPARE_PRINTF("23): Char with complex flags 1: %+ -*.3c;\n", 20, 'a');
	COMPARE_PRINTF("24): Basic characters: %c %c;\n", 'a', 65);
	COMPARE_PRINTF("25): String width trick: %*s;\n", 20, "small");
	COMPARE_PRINTF("26): Multiple specifiers: Char: %c, String: %s, Int: %d, Hex: %x;\n", 'A', "test", 42, 255);
	COMPARE_PRINTF("27): Complex format:|%-10.2s|%5d|%#10x|%5%|;\n", "hello", 42, 255);
	COMPARE_PRINTF("28): %%s;\n", NULL);
	COMPARE_PRINTF("29): %%p;\n", NULL);
	COMPARE_PRINTF("30): %+u;\n", 2147483647);
	COMPARE_PRINTF("31): %+x;\n", 2147483647);

	char *p = "data";
	COMPARE_PRINTF("32): %+p;\n", p);
	COMPARE_PRINTF("33): % u;\n", 0);

	COMPARE_PRINTF("34): Large precision with zero: %.1000d;\n", 0);
	COMPARE_PRINTF("35): Negative width: %-10d;\n", 42);

	return 0;
}
