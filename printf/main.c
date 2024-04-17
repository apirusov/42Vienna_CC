#include <limits.h>
#include <locale.h>
#include <stdarg.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <wchar.h>
#include "libftprintf.h"

#define RST "\033[0m"
#define O   "\033[1;33m"  // BOLD Yellow
#define R   "\033[1;31m"  // BOLD Red
#define G   "\033[1;32m"  // BOLD Green
#define Y   "\033[1;33m"  // BOLD Yellow
#define B   "\033[1;34m"  // BOLD Blue
#define M   "\033[1;35m"  // BOLD Magenta

void    test_char()
{
	ft_printf(M"************************* C H A R \tT E S T S *************************\n"RST);
	int n = 10; Y;
	printf(Y"\t\t^%d bytes written\n", printf(Y"___printf: This is a char "Y"[%-*%]"RST"\n", n));
	printf(G"\t\t^%d bytes written\n", ft_printf(G"ft_printf: This is a char "G"[%-*%]"RST"\n", n)); // make ignore flags if %%
	printf(Y"\t\t^%d bytes written\n", printf(Y"___printf: c: \t"Y"[%c]"RST"\n", 99));
	printf(G"\t\t^%d bytes written\n", ft_printf(G"ft_printf: c: \t"G"[%c]"RST"\n", 99));
	printf(Y"\t\t^%d bytes written\n", printf(Y"___printf: "Y"[%%]"RST"\n"));
	printf(G"\t\t^%d bytes written\n", ft_printf(G"ft_printf: "G"[%%]"RST"\n"));
	printf(Y"\t\t^%d bytes written\n", printf(Y"___printf: Characters: "Y"%c %c"RST" \n", 'a', 65));
	printf(G"\t\t^%d bytes written\n", ft_printf(G"ft_printf: Characters: "G"%c %c"RST" \n", 'a', 65));
    printf(Y"\t\t^%d bytes written\n", printf(Y"___printf: This is a char: "Y"[%c]"RST"\n", 'A'));
	printf(G"\t\t^%d bytes written\n", ft_printf(G"ft_printf: This is a char: "G"[%c]"RST"\n", 'A'));
	printf(Y"\t\t^%d bytes written\n", printf(Y"___printf: This is a char: "Y"[%10c]"RST"\n", 'A'));
	printf(G"\t\t^%d bytes written\n", ft_printf(G"ft_printf: This is a char: "G"[%10c]"RST"\n", 'A'));
	printf(Y"\t\t^%d bytes written\n", printf(Y"___printf: This is a char: "Y"[%-10c]"RST"\n", 'A'));
	printf(G"\t\t^%d bytes written\n", ft_printf(G"ft_printf: This is a char: "G"[%-10c]"RST"\n", 'A'));
	printf(Y"\t\t^%d bytes written\n", printf(Y"___printf: This is a char: "Y"[%-*c]"RST"\n", n, 'A'));
	printf(G"\t\t^%d bytes written\n", ft_printf(G"ft_printf: This is a char: "G"[%-*c]"RST"\n", n, 'A'));
}

void test_str()
{
	ft_printf(M"************************* S T R \tT E S T S *************************\n"RST);
	char *null = NULL; 
	Y;
	printf(Y"\t\t^%d bytes written\n", printf(Y"___printf: string null: "Y"%s"RST"\n", null));
	printf(G"\t\t^%d bytes written\n", ft_printf(G"ft_printf: string null: "G"%s"RST"\n", null));
	printf(Y"\t\t^%d bytes written\n", printf(Y"___printf: \t"Y"%s"RST" \n", "A string"));
	printf(G"\t\t^%d bytes written\n", ft_printf(G"ft_printf: \t"G"%s"RST" \n", "A string"));
	char *s = "Special Beam Cannon";
	printf(Y"\t\t^%d bytes written\n", printf(Y"___printf: This is a string: "Y"[%s]"RST"\n", s));
	printf(G"\t\t^%d bytes written\n", ft_printf(G"ft_printf: This is a string: "G"[%s]"RST"\n", s));
	printf(Y"\t\t^%d bytes written\n", printf(Y"___printf: This is a string: "Y"[%10s]"RST"\n", s));
	printf(G"\t\t^%d bytes written\n", ft_printf(G"ft_printf: This is a string: "G"[%10s]"RST"\n", s));
	printf(Y"\t\t^%d bytes written\n", printf(Y"___printf: This is a string: "Y"[%10s]"RST"\n", null));
	printf(G"\t\t^%d bytes written\n", ft_printf(G"ft_printf: This is a string: "G"[%10s]"RST"\n", null));
	printf(Y"\t\t^%d bytes written\n", printf(Y"___printf: This is a string: "Y"[%10.3s]"RST"\n", s));
	printf(G"\t\t^%d bytes written\n", ft_printf(G"ft_printf: This is a string: "G"[%10.3s]"RST"\n", s));
	printf(Y"\t\t^%d bytes written\n", printf(Y"___printf: This is a string: "Y"[%3.3s]"RST"\n", s));
	printf(G"\t\t^%d bytes written\n", ft_printf(G"ft_printf: This is a string: "G"[%3.3s]"RST"\n", s));
	printf(Y"\t\t^%d bytes written\n", printf(Y"___printf: This is a string: "Y"[%10.0s]"RST"\n", s));
	printf(G"\t\t^%d bytes written\n", ft_printf(G"ft_printf: This is a string: "G"[%10.0s]"RST"\n", s));
	printf(Y"\t\t^%d bytes written\n", printf(Y"___printf: This is a string: "Y"[%-10.3s]"RST"\n", s));
	printf(G"\t\t^%d bytes written\n", ft_printf(G"ft_printf: This is a string: "G"[%-10.3s]"RST"\n", s));
	//printf(Y"\t\t^%d bytes written\n", printf(Y"___printf: This is a string: "Y"[%-10.3s]"RST"\n", null));
	printf(G"\t\t^%d bytes written\n", ft_printf(G"ft_printf: This is a string: "G"[%-10.3s]"RST"\n", null));
	printf(Y"\t\t^%d bytes written\n", printf(Y"___printf: This is a string: "Y"[%32s]"RST"\n", s));
	printf(G"\t\t^%d bytes written\n", ft_printf(G"ft_printf: This is a string: "G"[%32s]"RST"\n", s));
	printf(Y"\t\t^%d bytes written\n", printf(Y"___printf: This is a string: "Y"[%32.0s]"RST"\n", s));
	printf(G"\t\t^%d bytes written\n", ft_printf(G"ft_printf: This is a string: "G"[%32.0s]"RST"\n", s));
	printf(Y"\t\t^%d bytes written\n", printf(Y"___printf: This is a string: "Y"[%-32.3s]"RST"\n", s));
	printf(G"\t\t^%d bytes written\n", ft_printf(G"ft_printf: This is a string: "G"[%-32.3s]"RST"\n", s));
//	printf(Y"\t\t^%d bytes written\n", printf(Y"___printf: This is a string: "Y"[%*.*s]"RST"\n", 10, s));
	printf(R"On next call original func makes a char from [%%*.->*s], so doesn't work with that command! Causes segfault\n"R RST);
	printf(G"\t\t^%d bytes written\n", ft_printf(G"ft_printf: This is a string: "G"[%*.*s]"RST"\n", 10, s));
}

void test_int()
{
	ft_printf(M"************************* I N T \tT E S T S *************************\n"RST);
	//printf(Y"\t\t^%d bytes written\n", printf(Y"___printf: \t"Y"%d"RST"\n", NULL));
	//printf(G"\t\t^%d bytes written\n", ft_printf(G"ft_printf: \t"G"%d"RST"\n", NULL));
	printf(Y"\t\t^%d bytes written\n", printf(Y"___printf: \t"Y"%x"RST"\n", INT_MIN));
	printf(G"\t\t^%d bytes written\n", ft_printf(G"ft_printf: \t"G"%x"RST"\n", INT_MIN));
	//printf(Y"\t\t^%d bytes written\n", printf(Y"___printf: \tDecimals: %d %ld\n", 1977, 650000L));
	//printf(G"\t\t^%d bytes written\n", ft_printf(G"ft_printf: \tDecimals: %d %ld\n", 1977, 650000L));
	printf(Y"\t\t^%d bytes written\n", printf(Y"___printf: \tPreceding with blanks [%%10d]: "Y"[%10d]"RST" \n", 1977));
	printf(G"\t\t^%d bytes written\n", ft_printf(G"ft_printf: \tPreceding with blanks [%%10d]: "G"[%10d]"RST" \n", 1977));
	printf(Y"\t\t^%d bytes written\n", printf(Y"___printf: \tPreceding with zeros [%%010d]: "Y"[%010d]"RST" \n", 1977));
	printf(G"\t\t^%d bytes written\n", ft_printf(G"ft_printf: \tPreceding with zeros [%%010d]: "G"[%010d]"RST" \n", 1977));
	printf(Y"\t\t^%d bytes written\n", printf(Y"___printf: \tSome different radices [%%d %%x %%o %%#x %%#o]: "Y"[%d %x %o %#x %#o]"RST" \n", 100, 100, 100, 100, 100));
	printf(G"\t\t^%d bytes written\n", ft_printf(G"ft_printf: \tSome different radices [%%d %%x %%o %%#x %%#o]: "G"[%d %x %o %#x %#o]"RST" \n", 100, 100, 100, 100, 100));
	printf(Y"\t\t^%d bytes written\n", printf(Y"___printf: \tWidth trick [%%*d]: "Y"[%*d]"RST" \n", 5, 10));
	printf(G"\t\t^%d bytes written\n", ft_printf(G"ft_printf: \tWidth trick [%%*d]: "G"[%*d]"RST" \n", 5, 10));
	printf(Y"\t\t^%d bytes written\n", printf(Y"___printf: This is a int [%%i] "Y"[%i]"RST"\n", INT_MIN));
	printf(G"\t\t^%d bytes written\n", ft_printf(G"ft_printf: This is a int [%%i] "G"[%i]"RST"\n", INT_MIN));
	printf(Y"\t\t^%d bytes written\n", printf(Y"___printf: This is a int [%%d] "Y"[%d]"RST"\n", 42));
	printf(G"\t\t^%d bytes written\n", ft_printf(G"ft_printf: This is a int [%%d] "G"[%d]"RST"\n", 42));
	printf(Y"\t\t^%d bytes written\n", printf(Y"___printf: This is a int [%%10d] "Y"[%10d]"RST"\n", 42));
	printf(G"\t\t^%d bytes written\n", ft_printf(G"ft_printf: This is a int [%%10d] "G"[%10d]"RST"\n", 42));
	printf(Y"\t\t^%d bytes written\n", printf(Y"___printf: This is a int [%%-10d] "Y"[%-10d]"RST"\n", 42));
	printf(G"\t\t^%d bytes written\n", ft_printf(G"ft_printf: This is a int [%%-10d] "G"[%-10d]"RST"\n", 42));
	printf(Y"\t\t^%d bytes written\n", printf(Y"___printf: This is a int [%%-+10d] "Y"[%-+10d]"RST"\n", 42));
	printf(G"\t\t^%d bytes written\n", ft_printf(G"ft_printf: This is a int [%%-+10d] "G"[%-+10d]"RST"\n", 42));
	printf(Y"\t\t^%d bytes written\n", printf(Y"___printf: This is a int [%% 10d] "Y"[% 10d]"RST"\n", 42));
	printf(G"\t\t^%d bytes written\n", ft_printf(G"ft_printf: This is a int [%% 10d] "G"[% 10d]"RST"\n", 42));
	printf(Y"\t\t^%d bytes written\n", printf(Y"___printf: This is a int [%%1d] "Y"[%1d]"RST"\n", 42));
	printf(G"\t\t^%d bytes written\n", ft_printf(G"ft_printf: This is a int [%%1d] "G"[%1d]"RST"\n", 42));
	printf(Y"\t\t^%d bytes written\n", printf(Y"___printf: This is a int [%%-10.3d] "Y"[%-10.3d]"RST"\n", 42));
	printf(G"\t\t^%d bytes written\n", ft_printf(G"ft_printf: This is a int [%%-10.3d] "G"[%-10.3d]"RST"\n", 42));
	printf(Y"\t\t^%d bytes written\n", printf(Y"___printf: This is a int [%%- 10.7d] "Y"[%- 10.7d]"RST"\n", 42));
	printf(G"\t\t^%d bytes written\n", ft_printf(G"ft_printf: This is a int [%%- 10.7d] "G"[%- 10.7d]"RST"\n", 42));
	printf(Y"\t\t^%d bytes written\n", printf(Y"___printf: This is a int [%% 010.7d] "Y"[% 010.7d]"RST"\n", 42));
	printf(G"\t\t^%d bytes written\n", ft_printf(G"ft_printf: This is a int [%% 010.7d] "G"[% 010.7d]"RST"\n", 42));
	printf(Y"\t\t^%d bytes written\n", printf(Y"___printf: This is a int [%%+-10.7d] "Y"[%+-10.7d]"RST"\n", 42));
	printf(G"\t\t^%d bytes written\n", ft_printf(G"ft_printf: This is a int [%%+-10.7d] "G"[%+-10.7d]"RST"\n", 42));
	printf(Y"\t\t^%d bytes written\n", printf(Y"___printf: This is a int [%%- 10.*d] "Y"[%- 10.*d]"RST"\n", 1<<12, 42));
	printf(G"\t\t^%d bytes written\n", ft_printf(G"ft_printf: This is a int [%%- 10.*d] "G"[%- 10.*d]"RST"\n", 1<<12, 42));
	printf(Y"\t\t^%d bytes written\n", printf(Y"___printf: This is a int [%%0.*d] "Y"[%0.*d]"RST"\n", 1<<8, 42));
	printf(G"\t\t^%d bytes written\n", ft_printf(G"ft_printf: This is a int [%%0.*d] "G"[%0.*d]"RST"\n", 1<<8, 42));
	printf(Y"\t\t^%d bytes written\n", printf(Y"___printf: Crazy [%%-+10.4d]: "Y"[%-+10.4d]"RST"\n", 12345));
	printf(G"\t\t^%d bytes written\n", ft_printf(G"ft_printf: Crazy [%%-+10.4d]: "G"[%-+10.4d]"RST"\n", 12345));
	printf(Y"\t\t^%d bytes written\n", printf(Y"___printf: Crazy [%%010.8d]: "Y"[%010.8d]"RST"\n", 9876));
	printf(G"\t\t^%d bytes written\n", ft_printf(G"ft_printf: Crazy [%%010.8d]: "G"[%010.8d]"RST"\n", 9876));
	printf(Y"\t\t^%d bytes written\n", printf(Y"___printf: Crazy [%%-+*.*d]: "Y"[%-+*.*d]"RST"\n", 6, 3, 123));
	printf(G"\t\t^%d bytes written\n", ft_printf(G"ft_printf: Crazy [%%-+*.*d]: "G"[%-+*.*d]"RST"\n", 6, 3, 123));
	printf(Y"\t\t^%d bytes written\n", printf(Y"___printf: Crazy [%%0*.*d]: "Y"[%0*.*d]"RST"\n", 1<<5, 2, 42));
	printf(G"\t\t^%d bytes written\n", ft_printf(G"ft_printf: Crazy [%%0*.*d]: "G"[%0*.*d]"RST"\n", 1<<5, 2, 42));
	printf(Y"\t\t^%d bytes written\n", printf(Y"___printf: Crazy [%%0*.*d]: "Y"[%0*.*d]"RST"\n", 5, 2, 42));
	printf(G"\t\t^%d bytes written\n", ft_printf(G"ft_printf: Crazy [%%0*.*d]: "G"[%0*.*d]"RST"\n", 5, 2, 42));
	printf(Y"\t\t^%d bytes written\n", printf(Y"___printf: Crazy [%%-+10.5d]: "Y"[%-+10.5d]"RST"\n", 987654));
	printf(G"\t\t^%d bytes written\n", ft_printf(G"ft_printf: Crazy [%%-+10.5d]: "G"[%-+10.5d]"RST"\n", 987654));
	printf(Y"\t\t^%d bytes written\n", printf(Y"___printf: Crazy [%%*.*d]: "Y"[%*.*d]"RST"\n", 8, 1<<10, 123));
	printf(G"\t\t^%d bytes written\n", ft_printf(G"ft_printf: Crazy [%%*.*d]: "G"[%*.*d]"RST"\n", 8, 1<<10, 123));
	printf(Y"\t\t^%d bytes written\n", printf(Y"___printf: Crazy [%%*.*d]: "Y"[%*.*d]"RST"\n", 100, 50, 12345));
	printf(G"\t\t^%d bytes written\n", ft_printf(G"ft_printf: Crazy [%%*.*d]: "G"[%*.*d]"RST"\n", 100, 50, 12345));
//	printf(Y"\t\t^%d bytes written\n", printf(Y"___printf: Crazy: [%-+0*.*d]\n", 1<<7, 3, 987));
	R;
	ft_printf("On next call original func ignores flag '0' when flag '-' is present [%%-+->0*.*d], so doesn't work with that command! Causes segfault\n"R RST);
	printf(G"\t\t^%d bytes written\n", ft_printf(G"ft_printf: Crazy [%%-+->0*.*d]: "G"[%-+0*.*d]"RST"\n", 1<<7, 3, 987));
	printf(Y"\t\t^%d bytes written\n", printf(Y"___printf: Crazy [%%-1000.500d]: "Y"[%-1000.500d]"RST"\n", 87654));
	printf(G"\t\t^%d bytes written\n", ft_printf(G"ft_printf: Crazy [%%-1000.500d]: "G"[%-1000.500d]"RST"\n", 87654));
	printf(Y"\t\t^%d bytes written\n", printf(Y"___printf: Crazy [%%*.*d]: "Y"[%*.*d]"RST"\n", 15, 1<<11, 98765));
	printf(G"\t\t^%d bytes written\n", ft_printf(G"ft_printf: Crazy [%%*.*d]: "G"[%*.*d]"RST"\n", 15, 1<<11, 98765));
//	printf(Y"\t\t^%d bytes written\n", printf(Y"___printf: Crazy: [%-+01000.500d]\n", 123456));
	R;
	ft_printf("On next call original func ignores flag '0' when flag '-' is present [%%-+->01000.500d], so doesn't work with that command! Causes segfault\n"R RST);
	printf(G"\t\t^%d bytes written\n", ft_printf(G"ft_printf: Crazy [%%-+->01000.500d]: "G"[%-+01000.500d]"RST"\n", 123456));
	printf(Y"\t\t^%d bytes written\n", printf(Y"___printf: Crazy [%%0*.*d]: "Y"[%0*.*d]"RST"\n", 1<<6, 3, 42));
	printf(G"\t\t^%d bytes written\n", ft_printf(G"ft_printf: Crazy [%%0*.*d]: "G"[%0*.*d]"RST"\n", 1<<6, 3, 42));
	printf(Y"\t\t^%d bytes written\n", printf(Y"___printf: Crazy [%%-+*.*d]: "Y"[%-+*.*d]"RST"\n", 1<<8, 2, 9876));
	printf(G"\t\t^%d bytes written\n", ft_printf(G"ft_printf: Crazy [%%-+*.*d]: "G"[%-+*.*d]"RST"\n", 1<<8, 2, 9876));
	printf(Y"\t\t^%d bytes written\n", printf(Y"___printf: Max int: "Y"[%d]"RST"\n", INT_MAX));
	printf(G"\t\t^%d bytes written\n", ft_printf(G"ft_printf: Max int: "G"[%d]"RST"\n", INT_MAX));
	printf(Y"\t\t^%d bytes written\n", printf(Y"___printf: Min int: "Y"[%d]"RST"\n", INT_MIN));
	printf(G"\t\t^%d bytes written\n", ft_printf(G"ft_printf: Min int: "G"[%d]"RST"\n", INT_MIN));
}

void	test_ptr()
{
	ft_printf(M"************************* P T R \tT E S T S *************************\n"RST);
	int n = 42;
	char *str = NULL;
	char *name = "Andrey";
	char *ptr;
	ptr = name;
	Y;
	printf(Y"\t\t^%d bytes written\n", printf(Y"___printf: ptr NULL "Y"%p"RST"\n", str));
	printf(G"\t\t^%d bytes written\n", ft_printf(G"ft_printf: ptr NULL "G"%p"RST"\n", str));
	printf(Y"\t\t^%d bytes written\n", printf(Y"___printf: ptr non NULL "Y"%p"RST"\n", ptr));
    printf(G"\t\t^%d bytes written\n", ft_printf(G"ft_printf: ptr non NULL "G"%p"RST"\n", ptr));
	printf(Y"\t\t^%d bytes written\n", printf(Y"___printf: Basic pointer: "Y"[%p]"RST"\n", &n));
	printf(G"\t\t^%d bytes written\n", ft_printf(G"ft_printf: Basic pointer: "G"[%p]"RST"\n", &n));
	printf(Y"\t\t^%d bytes written\n", printf(Y"___printf: Width of 20: "Y"[%20p]"RST"\n", &n));
	printf(G"\t\t^%d bytes written\n", ft_printf(G"ft_printf: Width of 20: "G"[%20p]"RST"\n", &n));
	printf(Y"\t\t^%d bytes written\n", printf(Y"___printf: Width of 20: "Y"[%20p]"RST"\n", str));
	printf(G"\t\t^%d bytes written\n", ft_printf(G"ft_printf: Width of 20: "G"[%20p]"RST"\n", str));
	printf(Y"\t\t^%d bytes written\n", printf(Y"___printf: Left-justified with width of 15: "Y"[%-15p]"RST"\n", &n));
	printf(G"\t\t^%d bytes written\n", ft_printf(G"ft_printf: Left-justified with width of 15: "G"[%-15p]"RST"\n", &n));
	printf(Y"\t\t^%d bytes written\n", printf(Y"___printf: Left-justified with width of 15: "Y"[%-15p]"RST"\n", str));
	printf(G"\t\t^%d bytes written\n", ft_printf(G"ft_printf: Left-justified with width of 15: "G"[%-15p]"RST"\n", str));
//	printf(Y"\t\t^%d bytes written\n", printf(Y"___printf: Alternate form: "Y"[%#p]"RST"\n", &n));
	ft_printf(R"On next call original flag '#' results in undefined behavior with 'p' conversion specifier[%%->#p]\n"R RST);
	printf(G"\t\t^%d bytes written\n", ft_printf(G"ft_printf: Alternate form: "G"[%#p]"RST"\n", &n));
//	printf(Y"\t\t^%d bytes written\n", printf(Y"___printf: Crazy combination: "Y"[%#-20p]"RST"\n", &n));
	ft_printf(R"On next call original flag '#' results in undefined behavior with 'p' conversion specifier[%%->#-20p]\n"R RST);
	printf(G"\t\t^%d bytes written\n", ft_printf(G"ft_printf: Crazy combination: "G"[%#-20p]"RST"\n", &n));
//	printf(Y"\t\t^%d bytes written\n", printf(Y"___printf: Precision and width: "Y"[%15.8p]"RST"\n", &n));
	ft_printf(R"On next call original func doesn't use precision with 'p' conversion specifier, resulting in undefined behavior! [%%15->.8p]\n"R RST);
	printf(G"\t\t^%d bytes written\n", ft_printf(G"ft_printf: Precision and width: "G"[%15.8p]"RST"\n", &n));
}

void test_X_x()
{
	ft_printf(M"************************* H E X \tT E S T S *************************\n"RST);
	int n = 255;
	printf(Y"\t\t^%d bytes written\n", printf(Y"___printf: \tThe chars written are "Y"%X"RST"\n", -1));
	printf(G"\t\t^%d bytes written\n", ft_printf(G"ft_printf: \tThe chars written are "G"%X"RST"\n", -1));
	printf(Y"\t\t^%d bytes written\n", printf(Y"___printf: Hexadecimal lowercase: "Y"[%x]"RST"\n", n));
	printf(G"\t\t^%d bytes written\n", ft_printf(G"ft_printf: Hexadecimal lowercase: "G"[%x]"RST"\n", n));
	printf(Y"\t\t^%d bytes written\n", printf(Y"___printf: Hexadecimal uppercase: "Y"[%X]"RST"\n", n));
	printf(G"\t\t^%d bytes written\n", ft_printf(G"ft_printf: Hexadecimal uppercase: "G"[%X]"RST"\n", n));
	printf(Y"\t\t^%d bytes written\n", printf(Y"___printf: Padded lowercase: "Y"[%010x]"RST"\n", n));
	printf(G"\t\t^%d bytes written\n", ft_printf(G"ft_printf: Padded lowercase: "G"[%010x]"RST"\n", n));
	printf(Y"\t\t^%d bytes written\n", printf(Y"___printf: Zero-padded uppercase: "Y"[%020X]"RST"\n", n));
	printf(G"\t\t^%d bytes written\n", ft_printf(G"ft_printf: Zero-padded uppercase: "G"[%020X]"RST"\n", n));
	printf(Y"\t\t^%d bytes written\n", printf(Y"___printf: Precision lowercase: "Y"[%.*x]"RST"\n", 5, n));
	printf(G"\t\t^%d bytes written\n", ft_printf(G"ft_printf: Precision lowercase: "G"[%.*x]"RST"\n", 5, n));
	printf(Y"\t\t^%d bytes written\n", printf(Y"___printf: Precision uppercase: "Y"[%.*X]"RST"\n", 8, n));
	printf(G"\t\t^%d bytes written\n", ft_printf(G"ft_printf: Precision uppercase: "G"[%.*X]"RST"\n", 8, n));
	printf(Y"\t\t^%d bytes written\n", printf(Y"___printf: Left-justified lowercase: "Y"[%-15x]"RST"\n", n));
	printf(G"\t\t^%d bytes written\n", ft_printf(G"ft_printf: Left-justified lowercase: "G"[%-15x]"RST"\n", n));
	printf(Y"\t\t^%d bytes written\n", printf(Y"___printf: Left-justified uppercase: "Y"[%-15X]"RST"\n", n));
	printf(G"\t\t^%d bytes written\n", ft_printf(G"ft_printf: Left-justified uppercase: "G"[%-15X]"RST"\n", n));
	printf(Y"\t\t^%d bytes written\n", printf(Y"___printf: Alternate form lowercase: "Y"[%#x]"RST"\n", n));
	printf(G"\t\t^%d bytes written\n", ft_printf(G"ft_printf: Alternate form lowercase: "G"[%#x]"RST"\n", n));
	printf(Y"\t\t^%d bytes written\n", printf(Y"___printf: Alternate form uppercase: "Y"[%#X]"RST"\n", n));
	printf(G"\t\t^%d bytes written\n", ft_printf(G"ft_printf: Alternate form uppercase: "G"[%#X]"RST"\n", n));
	printf(Y"\t\t^%d bytes written\n", printf(Y"___printf: Zero value lowercase: "Y"[%x]"RST"\n", 0));
	printf(G"\t\t^%d bytes written\n", ft_printf(G"ft_printf: Zero value lowercase: "G"[%x]"RST"\n", 0));
	printf(Y"\t\t^%d bytes written\n", printf(Y"___printf: Zero value uppercase: "Y"[%X]"RST"\n", 0));
	printf(G"\t\t^%d bytes written\n", ft_printf(G"ft_printf: Zero value uppercase: "G"[%X]"RST"\n", 0));
//	printf(Y"\t\t^%d bytes written\n", printf(Y"___printf: Large value lowercase: [%x]\n", 4294967295));
	ft_printf(R"On next call original func doesnt get the argument long, so doesn't work with that command!\n"R RST);
	printf(G"\t\t^%d bytes written\n", ft_printf(G"ft_printf: Large value lowercase [%%x->lx]: "G"[%x]"RST"\n", 4294967295));
//	printf(Y"\t\t^%d bytes written\n", printf(Y"___printf: Large value uppercase: [%X]\n", 4294967295));
	ft_printf(R"On next call original func doesnt get the argument long, so doesn't work with that command!\n"R RST);
	printf(G"\t\t^%d bytes written\n", ft_printf(G"ft_printf: tLarge value uppercase [%%X->lX]: [%X]\n", 4294967295));
	printf(Y"\t\t^%d bytes written\n", printf(Y"___printf: Negative value lowercase: "Y"[%x]"RST"\n", -42));
	printf(G"\t\t^%d bytes written\n", ft_printf(G"ft_printf: Negative value lowercase: "G"[%x]"RST"\n", -42));
	printf(Y"\t\t^%d bytes written\n", printf(Y"___printf: Negative value uppercase: "Y"[%X]"RST"\n", -42));
	printf(G"\t\t^%d bytes written\n", ft_printf(G"ft_printf: Negative value uppercase: "G"[%X]"RST"\n", -42));
}

void	test_u()
{
	ft_printf(M"************************* U I N T \tT E S T S *************************\n"RST);
	printf(Y"\t\t^%d bytes written\n", printf(Y"___printf: This is a uint "Y"[%-10.3u]"RST"\n", 42));
	printf(G"\t\t^%d bytes written\n", ft_printf(G"ft_printf: This is a uint "G"[%-10.3u]"RST"\n", 42));
//	printf(Y"\t\t^%d bytes written\n", printf(Y"___printf: This is a uint [%- 10.7u]\n", 42));
	ft_printf(R"On next call original func doesn't use flag ' ' results in undefined behavior with 'u' conversion specifier [%%--> 10.7u]!\n"R RST);
	printf(G"\t\t^%d bytes written\n", ft_printf(G"ft_printf: This is a uint "G"[%- 10.7u]"RST"\n", 42));
//	printf(Y"\t\t^%d bytes written\n", printf(Y"___printf: This is a uint [% 010.7u]\n", 42));
	ft_printf(R"On next call original func doesn't use flag ' ' results in undefined behavior with 'u' conversion specifier [%%-> 010.7u]!\n"R RST);
	printf(G"\t\t^%d bytes written\n", ft_printf(G"ft_printf: This is a uint "G"[% 010.7u]"RST"\n", 42));
//	printf(Y"\t\t^%d bytes written\n", printf(Y"___printf: This is a uint [%+-10.7u]\n", 42));
	ft_printf(R"On next call original func doesn't use flag '+' results in undefined behavior with 'u' conversion specifier [%%->+-10.7u]!\n"R RST);
	printf(G"\t\t^%d bytes written\n", ft_printf(G"ft_printf: This is a uint "G"[%+-10.7u]"RST"\n", 42));
//	printf(Y"\t\t^%d bytes written\n", printf(Y"___printf: This is a uint [%- 10.*u]\n", 1<<12, 42));
	ft_printf(R"On next call original func doesn't use flag ' ' results in undefined behavior with 'u' conversion specifier [%%--> 10.*u]!\n"R RST);
	printf(G"\t\t^%d bytes written\n", ft_printf(G"ft_printf: This is a uint "G"[%- 10.*u]"RST"\n", 1<<12, 42));
	printf(Y"\t\t^%d bytes written\n", printf(Y"___printf: This is a uint "Y"[%0.*u]"RST"\n", 1<<8, 42));
	printf(G"\t\t^%d bytes written\n", ft_printf(G"ft_printf: This is a uint "G"[%0.*u]"RST"\n", 1<<8, 42));
}

void	test_o()
{
	ft_printf(M"************************* O C T \tT E S T S *************************\n"RST);
	printf(Y"\t\t^%d bytes written\n", printf(Y"___printf: This is a uint "Y"[%-10.3o]"RST"\n", 42));
	printf(G"\t\t^%d bytes written\n", ft_printf(G"ft_printf: This is a uint "G"[%-10.3o]"RST"\n", 42));
//	printf(Y"\t\t^%d bytes written\n", printf(Y"___printf: This is a uint "Y"[%- 10.7o]\n", 42));
	ft_printf(R"On next call original func doesn't use flag ' ' results in undefined behavior with 'o' conversion specifier [%%--> 10.7o]!\n"R RST);
	printf(G"\t\t^%d bytes written\n", ft_printf(G"ft_printf: This is a uint "G"[%- 10.7o]"RST"\n", 42));
//	printf(Y"\t\t^%d bytes written\n", printf(Y"___printf: This is a uint "Y"[% 010.7o]\n", 42));
	ft_printf(R"On next call original func doesn't use flag ' ' results in undefined behavior with 'o' conversion specifier [%%-> 010.7o]!\n"R RST);
	printf(G"\t\t^%d bytes written\n", ft_printf(G"ft_printf: This is a uint "G"[% 010.7o]"RST"\n", 42));
//	printf(Y"\t\t^%d bytes written\n", printf(Y"___printf: This is a uint "Y"[%+-10.7o]\n", 42));
	ft_printf(R"On next call original func doesn't use flag '+' results in undefined behavior with 'o' conversion specifier [%%->+-10.7o]!\n"R RST);
	printf(G"\t\t^%d bytes written\n", ft_printf(G"ft_printf: This is a uint "G"[%+-10.7o]"RST"\n", 42));
//	printf(Y"\t\t^%d bytes written\n", printf(Y"___printf: This is a uint "Y"[%- 10.*o]\n", 1<<12, 42));
	ft_printf(R"On next call original func doesn't use flag ' ' results in undefined behavior with 'o' conversion specifier [%%--> 10.*o]!\n"R RST);
	printf(G"\t\t^%d bytes written\n", ft_printf(G"ft_printf: This is a uint "G"[%- 10.*o]"RST"\n", 1<<12, 42));
	printf(Y"\t\t^%d bytes written\n", printf(Y"___printf: This is a uint "Y"[%0.*o]"RST"\n", 1<<8, 42));
	printf(G"\t\t^%d bytes written\n", ft_printf(G"ft_printf: This is a uint "G"[%0.*o]"RST"\n", 1<<8, 42));
}
#include <string.h>
int	main(int ac, char **av)
{
    char			*name = "Andrey";
    unsigned int	date =  28;
    int				month = 3;
    int				year = 1989;
	int				age = 35;
	float			age_f = 35.03;
	int				age_int = (int)age_f;
	char			*str = NULL;
	if (ac > 1)
	{
		char *test;
		test = av[1];
		if (!strcmp(test, "tests"))
		{
			test_char();
			ft_printf("\v");
			test_str();
			ft_printf("\v");
			test_int();
			ft_printf("\v");
			test_ptr();
			ft_printf("\v");
			test_X_x();
			ft_printf("\v");
			test_u();
			ft_printf("\v");
			test_o();
			ft_printf("\v");
			ft_printf(G"ft_printf: Hello, \t%s, you are born @ %u.%o.%d, which means you are %f years old \
or %e%% of 100. (unexpected null!) %s It also is equal to %X or %x in \"hexadecimal\"\n", name, date, month, year, age, age_f, str, age_int, (int)age_f);
			ft_printf(G"ft_printf: Hello, %s, today is %d, in hex is %x or %X, char ->%c\n", "friend", 27, 27, 27, 'R');
		}
		else if (!strcmp(test, "test_char"))
			test_char();
		else if (!strcmp(test, "test_str"))
			test_str();
		else if (!strcmp(test, "test_int"))
			test_int();
		else if (!strcmp(test, "test_ptr"))
			test_ptr();
		else if (!strcmp(test, "test_hex"))
			test_X_x();
		else if (!strcmp(test, "test_u"))
			test_u();
		else if (!strcmp(test, "test_o"))
			test_o();
		else 
		{
			printf(Y"___printf:\n\tYOUR INPUT: %s\n", test);
			ft_printf(G"ft_printf:\n\tYOUR INPUT: %s\n", test);
		}
	}
	else
		return (1);
}

