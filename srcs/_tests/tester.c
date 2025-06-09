#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <limits.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include "../ft_printf.h"

#define RED	 "\033[1;31m"
#define GREEN   "\033[1;32m"
#define YELLOW  "\033[1;33m"
#define BLUE	"\033[1;34m"
#define MAGENTA "\033[1;35m"
#define CYAN	"\033[1;36m"
#define RESET   "\033[0m"

static int tests_passed = 0;
static int tests_failed = 0;

int ft_printf(const char *format, ...);

#define BUFFER_SIZE 30000
char std_buf[BUFFER_SIZE];
char ft_buf[BUFFER_SIZE];

int set_nonblocking(int fd) {
	int flags = fcntl(fd, F_GETFL, 0);
	if (flags == -1) return -1;
	return fcntl(fd, F_SETFL, flags | O_NONBLOCK);
}

void read_from_fd(int fd, char* buffer, int size) {
	int n;
	int total_read = 0;

	if (set_nonblocking(fd) == -1) {
		perror("fcntl");
		return;
	}

	while (1) {
		n = read(fd, buffer + total_read, size - total_read);
		if (n > 0) {
			total_read += n;
		} else if (n == 0) {
			// EOF
			break;
		} else {
			if (errno == EAGAIN || errno == EWOULDBLOCK) {
				// No more data to read
				break;
			} else {
				perror("read");
				break;
			}
		}
	}
	buffer[total_read] = '\0';
}

int capture_output(int (*printf_func)(const char *, va_list *), char *buf, const char *format, va_list args) {
	fflush(stdout);
	va_list args_copy;
	va_copy(args_copy, args);

	int pipefd[2];
	if (pipe(pipefd)) return -1;

	int saved_stdout = dup(STDOUT_FILENO);
	dup2(pipefd[1], STDOUT_FILENO);
	close(pipefd[1]);

	int ret = printf_func(format, &args_copy);
	fflush(stdout);

	read_from_fd(pipefd[0], buf, BUFFER_SIZE - 1);

	dup2(saved_stdout, STDOUT_FILENO);
	close(saved_stdout);
	close(pipefd[0]);

	va_end(args_copy);
	return ret;
}

void run_test(const char *description, const char *format, ...) {
	va_list args;
	va_start(args, format);

	memset(std_buf, 0, BUFFER_SIZE);
	int std_ret = capture_output(vprintf, std_buf, format, args);

	va_end(args);
	va_start(args, format);

	memset(ft_buf, 0, BUFFER_SIZE);
	int ft_ret = capture_output(ft_vprintf, ft_buf, format, args);

	va_end(args);

	int output_match = strcmp(std_buf, ft_buf) == 0;
	int retval_match = std_ret == ft_ret;
	int result = output_match && retval_match;

	printf("[Test] %-60s", description);
	if (result) {
		printf(GREEN "[OK]" RESET "\n");
		tests_passed++;
	} else {
		printf(RED "[FAIL]" RESET "\n");
		if (!output_match) {
			printf(YELLOW "Output mismatch:\nExpected: \"%s\"\nGot:	  \"%s\"" RESET "\n", std_buf, ft_buf);
		}
		if (!retval_match) {
			printf(YELLOW "Return value mismatch:\nExpected: %d\nGot:	  %d" RESET "\n", std_ret, ft_ret);
		}
		printf("\n");
		tests_failed++;
	}
}

void print_summary() {
	printf("\n" CYAN "=== Test Summary ===" RESET "\n");
	printf(GREEN "Passed: %d" RESET "\n", tests_passed);
	printf(RED "Failed: %d" RESET "\n", tests_failed);
	printf("Total:  %d\n\n", tests_passed + tests_failed);

	if (tests_failed == 0) {
		printf(GREEN "All tests passed! Congratulations!" RESET "\n");
	} else {
		printf(RED "Some tests failed. Check the output above for details." RESET "\n");
	}
}

int main() {
	printf(BLUE "=== Starting ft_printf Tester ===\n\n" RESET);

	// Test %c specifier
	printf(MAGENTA "\n=== Testing %%c (character) ===" RESET "\n");
	run_test("Basic character", "%c", 'A');
	run_test("Null character", "%c", '\0');
	run_test("Space character", "%c", ' ');
	run_test("With width", "%5c", 'X');
	run_test("With left justify", "%-5c", 'X');
	run_test("Basic characters", "%c %c", 'a', 65);
	run_test("Char with space flag", "% c", 'a');

	// Test %s specifier
	printf(MAGENTA "\n=== Testing %%s (string) ===" RESET "\n");
	run_test("Basic string", "%s", "Hello");
	run_test("Empty string", "%s", "");
	run_test("NULL string", "%s", NULL);
	run_test("With width", "%10s", "test");
	run_test("With left justify", "%-10s", "test");
	run_test("With precision", "%.2s", "testing");
	run_test("With width and precision", "%10.2s", "testing");
	run_test("Combined flags", "%-10.3s", "abcdef");
	// String edge cases
	run_test("Basic string", "%s", "a string");
	run_test("String with NULL", "%s", NULL);
	run_test("String with precision", "%.3s", "abcdef");

	// Test %d and %i specifiers
	printf(MAGENTA "\n=== Testing %%d and %%i (signed integers) ===" RESET "\n");
	run_test("Basic positive", "%d", 42);
	run_test("Basic negative", "%d", -42);
	run_test("Zero", "%d", 0);
	run_test("INT_MAX", "%d", INT_MAX);
	run_test("INT_MIN", "%d", INT_MIN);
	run_test("With width", "%10d", 123);
	run_test("With left justify", "%-10d", 123);
	run_test("With zero padding", "%010d", 123);
	run_test("With plus flag", "%+d", 42);
	run_test("With space flag", "% d", 42);
	run_test("With precision", "%.5d", 42);
	run_test("With precision larger than number", "%.10d", 42);
	run_test("With precision and zero", "%.0d", 0);
	run_test("Combined flags", "%+-10.5d", 42);
	run_test("%i equivalent", "%i", 42);
	// Decimal edge cases
	run_test("Decimal basic", "%d", 1977);
	run_test("Decimal zero no precision", "%d", 0);
	run_test("Decimal zero precision zero", "%.0d", 0);
	run_test("Decimal one precision zero", "%.0d", 1);
	run_test("INT_MAX", "%i", INT_MAX);
	run_test("Decimal precision > width with zero", "%020.30d", 123);
	run_test("Decimal precision < width with zero", "%020.10d", 123);
	run_test("Decimal width with zero", "%010d", 123);
	run_test("Decimal width", "%10d", 123);
	run_test("Decimal precision", "%.10d", 123);

	// Test %u specifier
	printf(MAGENTA "\n=== Testing %%u (unsigned integers) ===" RESET "\n");
	run_test("Basic unsigned", "%u", 42);
	run_test("Zero unsigned", "%u", 0);
	run_test("UINT_MAX", "%u", UINT_MAX);
	run_test("With width", "%10u", 123);
	run_test("With left justify", "%-10u", 123);
	run_test("With zero padding", "%010u", 123);
	run_test("With precision", "%.5u", 42);
	run_test("With precision larger than number", "%.10u", 42);

	// Test %x and %X specifiers
	printf(MAGENTA "\n=== Testing %%x and %%X (hexadecimal) ===" RESET "\n");
	run_test("Basic lowercase hex", "%x", 255);
	run_test("Basic uppercase hex", "%X", 255);
	run_test("Zero hex", "%x", 0);
	run_test("With # flag lowercase", "%#x", 255);
	run_test("With # flag uppercase", "%#X", 255);
	run_test("With width", "%10x", 255);
	run_test("With left justify", "%-10x", 255);
	run_test("With zero padding", "%010x", 255);
	run_test("With precision", "%.5x", 255);
	run_test("Combined flags", "%#-10.5x", 255);
	// Hexadecimal edge cases
	run_test("Hex lowercase basic", "%x", 128);
	run_test("Hex lowercase negative", "%x", -128);
	run_test("Hex uppercase basic", "%X", 128);
	run_test("Hex uppercase negative", "%X", -128);
	run_test("Hex zero", "%x", 0);
	run_test("Hex -1", "%x", -1);
	run_test("Hex -2", "%x", -2);
	run_test("Hex 1", "%x", 1);
	run_test("Hex 2", "%x", 2);
	run_test("Hex with # flag", "%#x", 255);
	run_test("Hex with # flag and zero", "%#x", 0);

	// Test %p specifier
	printf(MAGENTA "\n=== Testing %%p (pointer) ===" RESET "\n");
	void *ptr = (void *)0x1234abcd;
	void *null_ptr = NULL;
	run_test("Basic pointer", "%p", ptr);
	run_test("NULL pointer", "%p", null_ptr);
	run_test("With width", "%20p", ptr);
	run_test("With left justify", "%-20p", ptr);
	// Pointer edge cases
	run_test("NULL pointer basic", "%p", NULL);
	run_test("NULL pointer with width", "%20p", NULL);
	run_test("NULL pointer with zero padding", "%020p", NULL);
	run_test("Pointer with complex flags 1", "%-020p", ptr);
	run_test("Pointer with complex flags 2", "%-+020p", ptr);
	run_test("Pointer with complex flags 3", "%+020p", ptr);
	run_test("Pointer with complex flags 4", "%+20p", ptr);
	run_test("Pointer with complex flags 5", "%+ 020p", ptr);
	run_test("Pointer with complex flags 6", "%+ 0.20p", ptr);
	run_test("Pointer with precision 1", "%020.30p", ptr);
	run_test("Pointer with precision 2", "%020.10p", ptr);
	run_test("NULL pointer with space flag", "% .20p", NULL);

	// Test %% specifier
	printf(MAGENTA "\n=== Testing %%%% (percent sign) ===" RESET "\n");
	run_test("Basic percent", "%%");
	run_test("With width", "%5%");
	run_test("With left justify", "%-5%");
	run_test("Percent with width in quotes", "\"%10%\"");
	run_test("Percent with width", "%10%");
	run_test("Percent with left justify", "%-5%");

	printf(MAGENTA "\n=== Testing previously failed  ===" RESET "\n");
	run_test("Two nil pointers", " %p %p ", 0, 0);
	run_test("One decimal zero", " %d ", 0);
	run_test("One decimal LONG_MIN", " %d ", LONG_MIN);
	run_test("One decimal LONG_MAX", " %d ", LONG_MAX);

	// test
	run_test("All decimal numbers", " %d %d %d %d %d %d %d", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);
    run_test("Complex combination 1", "Char: %c, Str: %s, Dec: %d, Hex: %x, Ptr: %p", 'X', "test", 42, 255, ptr);
    run_test("Complex combination 2", "|%-10.2s|%5d|%#10x|%5%|", "hello", 42, 255);
    run_test("Complex combination 3", "%+ -*.3c %#10.5x %0*d", 20, 'a', 255, 10, 42);

	print_summary();

	return tests_failed ? EXIT_FAILURE : EXIT_SUCCESS;
}
