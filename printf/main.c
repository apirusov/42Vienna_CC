/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apirusov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 12:13:45 by apirusov          #+#    #+#             */
/*   Updated: 2024/04/19 12:13:50 by apirusov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#include <limits.h>
#include <string.h>
#include <stdlib.h>

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
	int n = 10;
	printf(Y"\t\t^%d bytes written\n", printf(Y"___printf: [%%-*%%]: "Y"[%-*%]"RST"\n", n));
	printf(G"\t\t^%d bytes written\n", ft_printf(G"ft_printf: [%%-*%%]: "G"[%-*%]"RST"\n", n)); // make ignore flags if %%
	printf(Y"\t\t^%d bytes written\n", printf(Y"___printf: [%%c]: \t"Y"[%c]"RST"\n", 99));
	printf(G"\t\t^%d bytes written\n", ft_printf(G"ft_printf: [%%c]: \t"G"[%c]"RST"\n", 99));
	printf(Y"\t\t^%d bytes written\n", printf(Y"___printf: "Y"[%%]"RST"\n"));
	printf(G"\t\t^%d bytes written\n", ft_printf(G"ft_printf: "G"[%%]"RST"\n"));
	printf(Y"\t\t^%d bytes written\n", printf(Y"___printf: Characters: "Y"%c %c"RST" \n", 'a', 65));
	printf(G"\t\t^%d bytes written\n", ft_printf(G"ft_printf: Characters: "G"%c %c"RST" \n", 'a', 65));
    printf(Y"\t\t^%d bytes written\n", printf(Y"___printf: [%%c]: "Y"[%c]"RST"\n", 'A'));
	printf(G"\t\t^%d bytes written\n", ft_printf(G"ft_printf: [%%c]: "G"[%c]"RST"\n", 'A'));
	printf(Y"\t\t^%d bytes written\n", printf(Y"___printf: [%%10c]: "Y"[%10c]"RST"\n", 'A'));
	printf(G"\t\t^%d bytes written\n", ft_printf(G"ft_printf: [%%10c]: "G"[%10c]"RST"\n", 'A'));
	printf(Y"\t\t^%d bytes written\n", printf(Y"___printf: [%%1c]: "Y"[%1c]"RST"\n", 'A'));
	printf(G"\t\t^%d bytes written\n", ft_printf(G"ft_printf: [%%1c]: "G"[%1c]"RST"\n", 'A'));
	//printf(Y"\t\t^%d bytes written\n", printf(Y"___printf: [%%010c]: "Y"[%010c]"RST"\n", 'A'));
	printf(G"\t\t^%d bytes written\n", ft_printf(G"ft_printf: [%%010c]: "G"[%010c]"RST"\n", 'A'));
	printf(Y"\t\t^%d bytes written\n", printf(Y"___printf: [%%-10c]: "Y"[%-10c]"RST"\n", 'A'));
	printf(G"\t\t^%d bytes written\n", ft_printf(G"ft_printf: [%%-10c]: "G"[%-10c]"RST"\n", 'A'));
	//printf(Y"\t\t^%d bytes written\n", printf(Y"___printf: [%%-010c]: "Y"[%-010c]"RST"\n", 'A'));
	printf(G"\t\t^%d bytes written\n", ft_printf(G"ft_printf: [%%-010c]: "G"[%-010c]"RST"\n", 'A'));
	printf(Y"\t\t^%d bytes written\n", printf(Y"___printf: [%%-1c]: "Y"[%-1c]"RST"\n", 'A'));
	printf(G"\t\t^%d bytes written\n", ft_printf(G"ft_printf: [%%-1c]: "G"[%-1c]"RST"\n", 'A'));
	printf(Y"\t\t^%d bytes written\n", printf(Y"___printf: [%%-*c]: "Y"[%-*c]"RST"\n", n, 'A'));
	printf(G"\t\t^%d bytes written\n", ft_printf(G"ft_printf: [%%-*c]: "G"[%-*c]"RST"\n", n, 'A'));
}

void test_str()
{
	ft_printf(M"************************* S T R \tT E S T S *************************\n"RST);
	char *null = NULL; 
	printf(Y"\t\t^%d bytes written\n", printf(Y"___printf: string null: "Y"%s"RST"\n", null));
	printf(G"\t\t^%d bytes written\n", ft_printf(G"ft_printf: string null: "G"%s"RST"\n", null));
	printf(Y"\t\t^%d bytes written\n", printf(Y"___printf: \t"Y"%s"RST" \n", "A string"));
	printf(G"\t\t^%d bytes written\n", ft_printf(G"ft_printf: \t"G"%s"RST" \n", "A string"));
	char *s = "42 Vienna is the best school in the world!";
	printf(Y"\t\t^%d bytes written\n", printf(Y"___printf: [%%s]: "Y"[%s]"RST"\n", s));
	printf(G"\t\t^%d bytes written\n", ft_printf(G"ft_printf: [%%s]: "G"[%s]"RST"\n", s));
	printf(Y"\t\t^%d bytes written\n", printf(Y"___printf: [%%10s]: "Y"[%10s]"RST"\n", s));
	printf(G"\t\t^%d bytes written\n", ft_printf(G"ft_printf: [%%10s]: "G"[%10s]"RST"\n", s));
	printf(Y"\t\t^%d bytes written\n", printf(Y"___printf: null [%%10s]: "Y"[%10s]"RST"\n", null));
	printf(G"\t\t^%d bytes written\n", ft_printf(G"ft_printf: null [%%10s]: "G"[%10s]"RST"\n", null));
	printf(Y"\t\t^%d bytes written\n", printf(Y"___printf: [%%10.3s]: "Y"[%10.3s]"RST"\n", s));
	printf(G"\t\t^%d bytes written\n", ft_printf(G"ft_printf: [%%10.3s]: "G"[%10.3s]"RST"\n", s));
	printf(Y"\t\t^%d bytes written\n", printf(Y"___printf: [%%3.3s]: "Y"[%3.3s]"RST"\n", s));
	printf(G"\t\t^%d bytes written\n", ft_printf(G"ft_printf: [%%3.3s]: "G"[%3.3s]"RST"\n", s));
	printf(Y"\t\t^%d bytes written\n", printf(Y"___printf: [%%10.0s]: "Y"[%10.0s]"RST"\n", s));
	printf(G"\t\t^%d bytes written\n", ft_printf(G"ft_printf: [%%10.0s]: "G"[%10.0s]"RST"\n", s));
	printf(Y"\t\t^%d bytes written\n", printf(Y"___printf: [%%-10.3s]: "Y"[%-10.3s]"RST"\n", s));
	printf(G"\t\t^%d bytes written\n", ft_printf(G"ft_printf: [%%-10.3s]: "G"[%-10.3s]"RST"\n", s));
	printf(Y"\t\t^%d bytes written\n", printf(Y"___printf: null [%%10.3s]: "Y"[%10.3s]"RST"\n", null));
	printf(G"\t\t^%d bytes written\n", ft_printf(G"ft_printf: null [%%10.3s]: "G"[%10.3s]"RST"\n", null));
	printf(Y"\t\t^%d bytes written\n", printf(Y"___printf: null [%%-10.3s]: "Y"[%-10.3s]"RST"\n", null));
	printf(G"\t\t^%d bytes written\n", ft_printf(G"ft_printf: null [%%-10.3s]: "G"[%-10.3s]"RST"\n", null));
	printf(Y"\t\t^%d bytes written\n", printf(Y"___printf: [%%62s]: "Y"[%62s]"RST"\n", s));
	printf(G"\t\t^%d bytes written\n", ft_printf(G"ft_printf: [%%62s]: "G"[%62s]"RST"\n", s));
	//printf(Y"\t\t^%d bytes written\n", printf(Y"___printf: [%%032s]: "Y"[%032s]"RST"\n", s));
	printf(R"Original function can not handle next call with the flag '0' on this system [%%032s], so it causes undefined behavior\n"RST);
	printf(G"\t\t^%d bytes written\n", ft_printf(G"ft_printf: [%%062s]: "G"[%062s]"RST"\n", s));
	printf(Y"\t\t^%d bytes written\n", printf(Y"___printf: [%%62.0s]: "Y"[%62.0s]"RST"\n", s));
	printf(G"\t\t^%d bytes written\n", ft_printf(G"ft_printf: [%%62.0s]: "G"[%62.0s]"RST"\n", s));
	printf(Y"\t\t^%d bytes written\n", printf(Y"___printf: [%%-62.3s]: "Y"[%-62.3s]"RST"\n", s));
	printf(G"\t\t^%d bytes written\n", ft_printf(G"ft_printf: [%%-62.3s]: "G"[%-62.3s]"RST"\n", s));
	printf(Y"\t\t^%d bytes written\n", printf(Y"___printf: [%%*.*s]: "Y"[%*.*s]"RST"\n", 10, 10, s));
	printf(G"\t\t^%d bytes written\n", ft_printf(G"ft_printf: [%%*.*s]: "G"[%*.*s]"RST"\n", 10, 10, s));
}

void test_int()
{
	ft_printf(M"************************* I N T \tT E S T S *************************\n"RST);
	//printf(Y"\t\t^%d bytes written\n", printf(Y"___printf: \t"Y"%d"RST"\n", NULL));
	//printf(G"\t\t^%d bytes written\n", ft_printf(G"ft_printf: \t"G"%d"RST"\n", NULL));
	printf(Y"\t\t^%d bytes written\n", printf(Y"___printf INT_MIN: \t"Y"%i"RST"\n", INT_MIN));
	printf(G"\t\t^%d bytes written\n", ft_printf(G"ft_printf INT_MIN: \t"G"%i"RST"\n", INT_MIN));
	//printf(Y"\t\t^%d bytes written\n", printf(Y"___printf: \tDecimals: %d %ld\n", 1977, 650000L));
	//printf(G"\t\t^%d bytes written\n", ft_printf(G"ft_printf: \tDecimals: %d %ld\n", 1977, 650000L));
	printf(Y"\t\t^%d bytes written\n", printf(Y"___printf: \tPreceding with blanks [%%10d]: "Y"[%10d]"RST" \n", 1977));
	printf(G"\t\t^%d bytes written\n", ft_printf(G"ft_printf: \tPreceding with blanks [%%10d]: "G"[%10d]"RST" \n", 1977));
	printf(Y"\t\t^%d bytes written\n", printf(Y"___printf: \tPreceding with blanks [%%10d]: "Y"[%10d]"RST" \n", -1977));
	printf(G"\t\t^%d bytes written\n", ft_printf(G"ft_printf: \tPreceding with blanks [%%10d]: "G"[%10d]"RST" \n", -1977));
	printf(Y"\t\t^%d bytes written\n", printf(Y"___printf: \tPreceding with zeros [%%010d]: "Y"[%010d]"RST" \n", 1977));
	printf(G"\t\t^%d bytes written\n", ft_printf(G"ft_printf: \tPreceding with zeros [%%010d]: "G"[%010d]"RST" \n", 1977));
	printf(Y"\t\t^%d bytes written\n", printf(Y"___printf: \tPreceding with zeros [%%010d]: "Y"[%010d]"RST" \n", -1977));
	printf(G"\t\t^%d bytes written\n", ft_printf(G"ft_printf: \tPreceding with zeros [%%010d]: "G"[%010d]"RST" \n", -1977));
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
	printf(Y"\t\t^%d bytes written\n", printf(Y"___printf: Crazy [%%0*.*d]: "Y"[%0*.*d]"RST"\n", 5, 0, 42));
	printf(G"\t\t^%d bytes written\n", ft_printf(G"ft_printf: Crazy [%%0*.*d]: "G"[%0*.*d]"RST"\n", 5, 0, 42));
	printf(Y"\t\t^%d bytes written\n", printf(Y"___printf: Crazy [%%-+10.5d]: "Y"[%-+10.5d]"RST"\n", 987654));
	printf(G"\t\t^%d bytes written\n", ft_printf(G"ft_printf: Crazy [%%-+10.5d]: "G"[%-+10.5d]"RST"\n", 987654));
	printf(Y"\t\t^%d bytes written\n", printf(Y"___printf: Crazy [%%*.*d]: "Y"[%*.*d]"RST"\n", 8, 1<<10, 123));
	printf(G"\t\t^%d bytes written\n", ft_printf(G"ft_printf: Crazy [%%*.*d]: "G"[%*.*d]"RST"\n", 8, 1<<10, 123));
	printf(Y"\t\t^%d bytes written\n", printf(Y"___printf: Crazy [%%*.*d]: "Y"[%*.*d]"RST"\n", 100, 50, 12345));
	printf(G"\t\t^%d bytes written\n", ft_printf(G"ft_printf: Crazy [%%*.*d]: "G"[%*.*d]"RST"\n", 100, 50, 12345));
//	printf(Y"\t\t^%d bytes written\n", printf(Y"___printf: Crazy: [%-+0*.*d]\n", 1<<7, 3, 987));
	ft_printf(R"On next call original func ignores flag '0' when flag '-' is present [%%-+->0*.*d], so doesn't work with that command! Causes segfault\n"R RST);
	printf(G"\t\t^%d bytes written\n", ft_printf(G"ft_printf: Crazy [%%-+->0*.*d]: "G"[%-+0*.*d]"RST"\n", 1<<7, 3, 987));
	printf(Y"\t\t^%d bytes written\n", printf(Y"___printf: Crazy [%%-1000.500d]: "Y"[%-1000.500d]"RST"\n", 87654));
	printf(G"\t\t^%d bytes written\n", ft_printf(G"ft_printf: Crazy [%%-1000.500d]: "G"[%-1000.500d]"RST"\n", 87654));
	printf(Y"\t\t^%d bytes written\n", printf(Y"___printf: Crazy [%%*.*d]: "Y"[%*.*d]"RST"\n", 15, 1<<11, 98765));
	printf(G"\t\t^%d bytes written\n", ft_printf(G"ft_printf: Crazy [%%*.*d]: "G"[%*.*d]"RST"\n", 15, 1<<11, 98765));
//	printf(Y"\t\t^%d bytes written\n", printf(Y"___printf: Crazy: [%-+01000.500d]\n", 123456));
	ft_printf(R"On next call original func ignores flag '0' when flag '-' is present [%%-+->01000.500d], so doesn't work with that command! Causes segfault\n"R RST);
	printf(G"\t\t^%d bytes written\n", ft_printf(G"ft_printf: Crazy [%%-+->01000.500d]: "G"[%-+01000.500d]"RST"\n", 123456));
	printf(Y"\t\t^%d bytes written\n", printf(Y"___printf: Crazy [%%0*.*d]: "Y"[%0*.*d]"RST"\n", 1<<5, 3, 42));
	printf(G"\t\t^%d bytes written\n", ft_printf(G"ft_printf: Crazy [%%0*.*d]: "G"[%0*.*d]"RST"\n", 1<<5, 3, 42));
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
	printf(Y"\t\t^%d bytes written\n", printf(Y"___printf: NULL [%%p] "Y"%p"RST"\n", str));
	printf(G"\t\t^%d bytes written\n", ft_printf(G"ft_printf: NULL [%%p] "G"%p"RST"\n", str));
	printf(Y"\t\t^%d bytes written\n", printf(Y"___printf: [%%p] "Y"%p"RST"\n", ptr));
    printf(G"\t\t^%d bytes written\n", ft_printf(G"ft_printf: [%%p] "G"%p"RST"\n", ptr));
	printf(Y"\t\t^%d bytes written\n", printf(Y"___printf: [%%p]: "Y"[%p]"RST"\n", &n));
	printf(G"\t\t^%d bytes written\n", ft_printf(G"ft_printf: [%%p]: "G"[%p]"RST"\n", &n));
	//printf(Y"\t\t^%d bytes written\n", printf(Y"___printf: [%%#p]: "Y"[%#p]"RST"\n", &n));
	printf(G"\t\t^%d bytes written\n", ft_printf(G"ft_printf: [%%#p]: "G"[%#p]"RST"\n", &n));
	printf(Y"\t\t^%d bytes written\n", printf(Y"___printf: [%%20p]: "Y"[%20p]"RST"\n", &n));
	printf(G"\t\t^%d bytes written\n", ft_printf(G"ft_printf: [%%20p]: "G"[%20p]"RST"\n", &n));
	printf(Y"\t\t^%d bytes written\n", printf(Y"___printf: NULL [%%20p]: "Y"[%20p]"RST"\n", str));
	printf(G"\t\t^%d bytes written\n", ft_printf(G"ft_printf: NULL [%%20p]: "G"[%20p]"RST"\n", str));
	printf(Y"\t\t^%d bytes written\n", printf(Y"___printf: [%%-15p]: "Y"[%-15p]"RST"\n", &n));
	printf(G"\t\t^%d bytes written\n", ft_printf(G"ft_printf: [%%-15p]: "G"[%-15p]"RST"\n", &n));
	printf(Y"\t\t^%d bytes written\n", printf(Y"___printf: NULL [%%-15p]: "Y"[%-15p]"RST"\n", str));
	printf(G"\t\t^%d bytes written\n", ft_printf(G"ft_printf: NULL [%%-15p]: "G"[%-15p]"RST"\n", str));
//	printf(Y"\t\t^%d bytes written\n", printf(Y"___printf: Alternate form: "Y"[%#p]"RST"\n", &n));
	ft_printf(R"On next call original flag '#' results in undefined behavior with 'p' conversion specifier[%%->#p]\n"R RST);
	printf(G"\t\t^%d bytes written\n", ft_printf(G"ft_printf: [%%#p]: "G"[%#p]"RST"\n", &n));
//	printf(Y"\t\t^%d bytes written\n", printf(Y"___printf: Crazy combination: "Y"[%#-20p]"RST"\n", &n));
	ft_printf(R"On next call original flag '#' results in undefined behavior with 'p' conversion specifier[%%->#-20p]\n"R RST);
	printf(G"\t\t^%d bytes written\n", ft_printf(G"ft_printf: [%%#-20p]: "G"[%#-20p]"RST"\n", &n));
//	printf(Y"\t\t^%d bytes written\n", printf(Y"___printf: Precision and width: "Y"[%15.8p]"RST"\n", &n));
	ft_printf(R"On next call original func doesn't use precision with 'p' conversion specifier, resulting in undefined behavior! [%%15->.8p]\n"R RST);
	printf(G"\t\t^%d bytes written\n", ft_printf(G"ft_printf: [%%15.8p]: "G"[%15.8p]"RST"\n", &n));
	ft_printf(R"On next call original func doesn't use precision with 'p' conversion specifier, resulting in undefined behavior! [%%15->.8p]\n"R RST);
	printf(G"\t\t^%d bytes written\n", ft_printf(G"ft_printf: [%%-15.8p]: "G"[%-15.8p]"RST"\n", &n));
	ft_printf(R"On next call original func doesn't use precision with 'p' conversion specifier, resulting in undefined behavior! [%%15->.8p]\n"R RST);
	printf(G"\t\t^%d bytes written\n", ft_printf(G"ft_printf: [%%-15.8p]: "G"[%-15.3p]"RST"\n", &n));
	ft_printf(R"On next call original func doesn't use precision with 'p' conversion specifier, resulting in undefined behavior! [%%15->.8p]\n"R RST);
	printf(G"\t\t^%d bytes written\n", ft_printf(G"ft_printf: null [%%-15.3p]: "G"[%-15.3p]"RST"\n", str));
	printf(Y"\t\t^%d bytes written\n", printf(Y"___printf: [%%4p]: "Y"[%4p]"RST"\n", str));
	printf(G"\t\t^%d bytes written\n", ft_printf(G"ft_printf: [%%4p]: "G"[%4p]"RST"\n", str));
}

void test_X_x()
{
	ft_printf(M"************************* H E X \tT E S T S *************************\n"RST);
	int n = 255;
	printf(Y"\t\t^%d bytes written\n", printf(Y"___printf: [%%X] -1: "Y"%X"RST"\n", -1));
	printf(G"\t\t^%d bytes written\n", ft_printf(G"ft_printf: [%%X] -1: "G"%X"RST"\n", -1));
	printf(Y"\t\t^%d bytes written\n", printf(Y"___printf: [%%x] 255: "Y"[%x]"RST"\n", n));
	printf(G"\t\t^%d bytes written\n", ft_printf(G"ft_printf: [%%x] 255: "G"[%x]"RST"\n", n));
	printf(Y"\t\t^%d bytes written\n", printf(Y"___printf: [%%X] 255: "Y"[%X]"RST"\n", n));
	printf(G"\t\t^%d bytes written\n", ft_printf(G"ft_printf: [%%X] 255: "G"[%X]"RST"\n", n));
	printf(Y"\t\t^%d bytes written\n", printf(Y"___printf: [%%10x] 255: "Y"[%10x]"RST"\n", n));
	printf(G"\t\t^%d bytes written\n", ft_printf(G"ft_printf: [%%10x] 255: "G"[%10x]"RST"\n", n));
	printf(Y"\t\t^%d bytes written\n", printf(Y"___printf: [%%020X] 255: "Y"[%020X]"RST"\n", n));
	printf(G"\t\t^%d bytes written\n", ft_printf(G"ft_printf: [%%020X] 255: "G"[%020X]"RST"\n", n));
	printf(Y"\t\t^%d bytes written\n", printf(Y"___printf: [%%.*x] 5 255: "Y"[%.*x]"RST"\n", 5, n));
	printf(G"\t\t^%d bytes written\n", ft_printf(G"ft_printf:[%%.*x] 5 255: "G"[%.*x]"RST"\n", 5, n));
	printf(Y"\t\t^%d bytes written\n", printf(Y"___printf: [%%.*X] 8 255: "Y"[%.*X]"RST"\n", 8, n));
	printf(G"\t\t^%d bytes written\n", ft_printf(G"ft_printf: [%%.*X] 8 255: "G"[%.*X]"RST"\n", 8, n));
	printf(Y"\t\t^%d bytes written\n", printf(Y"___printf: [%%-15x] 255: "Y"[%-15x]"RST"\n", n));
	printf(G"\t\t^%d bytes written\n", ft_printf(G"ft_printf: [%%-15x] 255: "G"[%-15x]"RST"\n", n));
	printf(Y"\t\t^%d bytes written\n", printf(Y"___printf: [%%-15X] 255: "Y"[%-15X]"RST"\n", n));
	printf(G"\t\t^%d bytes written\n", ft_printf(G"ft_printf: [%%-15X] 255: "G"[%-15X]"RST"\n", n));
	printf(Y"\t\t^%d bytes written\n", printf(Y"___printf: [%%#x] 255: "Y"[%#x]"RST"\n", n));
	printf(G"\t\t^%d bytes written\n", ft_printf(G"ft_printf: [%%#x] 255: "G"[%#x]"RST"\n", n));
	printf(Y"\t\t^%d bytes written\n", printf(Y"___printf: [%%#X] 255: "Y"[%#X]"RST"\n", n));
	printf(G"\t\t^%d bytes written\n", ft_printf(G"ft_printf: [%%#X] 255: "G"[%#X]"RST"\n", n));
	printf(Y"\t\t^%d bytes written\n", printf(Y"___printf: [%%x] 0: "Y"[%x]"RST"\n", 0));
	printf(G"\t\t^%d bytes written\n", ft_printf(G"ft_printf: [%%x] 0: "G"[%x]"RST"\n", 0));
	printf(Y"\t\t^%d bytes written\n", printf(Y"___printf: [%%X] 0: "Y"[%X]"RST"\n", 0));
	printf(G"\t\t^%d bytes written\n", ft_printf(G"ft_printf: [%%X] 0: "G"[%X]"RST"\n", 0));
//	printf(Y"\t\t^%d bytes written\n", printf(Y"___printf: Large value lowercase: [%x]\n", 4294967295));
	ft_printf(R"On next call original func doesnt get the argument long, so doesn't work with that command!\n"R RST);
	printf(G"\t\t^%d bytes written\n", ft_printf(G"ft_printf: Large value lowercase [%%x->lx]: "G"[%x]"RST"\n", 4294967295));
//	printf(Y"\t\t^%d bytes written\n", printf(Y"___printf: Large value uppercase: [%X]\n", 4294967295));
	ft_printf(R"On next call original func doesnt get the argument long, so doesn't work with that command!\n"R RST);
	printf(G"\t\t^%d bytes written\n", ft_printf(G"ft_printf: Large value uppercase [%%X->lX]: [%X]\n", 4294967295));
	printf(Y"\t\t^%d bytes written\n", printf(Y"___printf: Negative value lowercase [%%x] -42: "Y"[%x]"RST"\n", -42));
	printf(G"\t\t^%d bytes written\n", ft_printf(G"ft_printf: Negative value lowercase [%%x] -42: "G"[%x]"RST"\n", -42));
	printf(Y"\t\t^%d bytes written\n", printf(Y"___printf: Negative value uppercase [%%X] -42: "Y"[%X]"RST"\n", -42));
	printf(G"\t\t^%d bytes written\n", ft_printf(G"ft_printf: Negative value uppercase [%%X] -42: "G"[%X]"RST"\n", -42));
}

void	test_u()
{
	ft_printf(M"************************* U I N T \tT E S T S *************************\n"RST);
	printf(Y"\t\t^%d bytes written\n", printf(Y"___printf: [%%-10.3u] 42: "Y"[%-10.3u]"RST"\n", 42));
	printf(G"\t\t^%d bytes written\n", ft_printf(G"ft_printf: [%%-10.3u] 42: "G"[%-10.3u]"RST"\n", 42));
	printf(Y"\t\t^%d bytes written\n", printf(Y"___printf: [%%-10.3u] -42: "Y"[%-10.3u]"RST"\n", -42));
	printf(G"\t\t^%d bytes written\n", ft_printf(G"ft_printf: [%%-10.3u] -42: "G"[%-10.3u]"RST"\n", -42));
//	printf(Y"\t\t^%d bytes written\n", printf(Y"___printf: This is a uint [%- 10.7u]\n", 42));
	ft_printf(R"On next call original func doesn't use flag ' ' results in undefined behavior with 'u' conversion specifier [%%--> 10.7u]!\n"R RST);
	printf(G"\t\t^%d bytes written\n", ft_printf(G"ft_printf: [%%- 10.7u] 42: "G"[%- 10.7u]"RST"\n", 42));
//	printf(Y"\t\t^%d bytes written\n", printf(Y"___printf: This is a uint [% 010.7u]\n", 42));
	ft_printf(R"On next call original func doesn't use flag ' ' results in undefined behavior with 'u' conversion specifier [%%-> 010.7u]!\n"R RST);
	printf(G"\t\t^%d bytes written\n", ft_printf(G"ft_printf: [%% 010.7u] 42: "G"[% 010.7u]"RST"\n", 42));
//	printf(Y"\t\t^%d bytes written\n", printf(Y"___printf: This is a uint [%+-10.7u]\n", 42));
	ft_printf(R"On next call original func doesn't use flag '+' results in undefined behavior with 'u' conversion specifier [%%->+-10.7u]!\n"R RST);
	printf(G"\t\t^%d bytes written\n", ft_printf(G"ft_printf: [%%+-10.7u] 42: "G"[%+-10.7u]"RST"\n", 42));
//	printf(Y"\t\t^%d bytes written\n", printf(Y"___printf: This is a uint [%- 10.*u]\n", 1<<12, 42));
	ft_printf(R"On next call original func doesn't use flag ' ' results in undefined behavior with 'u' conversion specifier [%%--> 10.*u]!\n"R RST);
	printf(G"\t\t^%d bytes written\n", ft_printf(G"ft_printf: [%%- 10.*u] 1<<12 42: "G"[%- 10.*u]"RST"\n", 1<<12, 42));
	printf(Y"\t\t^%d bytes written\n", printf(Y"___printf: [%%0.*u] 1<<8 42: "Y"[%0.*u]"RST"\n", 1<<8, 42));
	printf(G"\t\t^%d bytes written\n", ft_printf(G"ft_printf: [%%0.*u] 1<<8 42: "G"[%0.*u]"RST"\n", 1<<8, 42));
}

void	test_o()
{
	ft_printf(M"************************* O C T \tT E S T S *************************\n"RST);
	printf(Y"\t\t^%d bytes written\n", printf(Y"___printf: [%%-10.3o] 42: "Y"[%-10.3o]"RST"\n", 42));
	printf(G"\t\t^%d bytes written\n", ft_printf(G"ft_printf: [%%-10.3o] 42: "G"[%-10.3o]"RST"\n", 42));
	printf(Y"\t\t^%d bytes written\n", printf(Y"___printf: [%%-10.3o] -42: "Y"[%-10.3o]"RST"\n", -42));
	printf(G"\t\t^%d bytes written\n", ft_printf(G"ft_printf: [%%-10.3o] -42: "G"[%-10.3o]"RST"\n", -42));
//	printf(Y"\t\t^%d bytes written\n", printf(Y"___printf: This is a uint "Y"[%- 10.7o]\n", 42));
	ft_printf(R"On next call original func doesn't use flag ' ' results in undefined behavior with 'o' conversion specifier [%%--> 10.7o]!\n"R RST);
	printf(G"\t\t^%d bytes written\n", ft_printf(G"ft_printf: [%%- 10.7o] 42: "G"[%- 10.7o]"RST"\n", 42));
//	printf(Y"\t\t^%d bytes written\n", printf(Y"___printf: This is a uint "Y"[% 010.7o]\n", 42));
	ft_printf(R"On next call original func doesn't use flag ' ' results in undefined behavior with 'o' conversion specifier [%%-> 010.7o]!\n"R RST);
	printf(G"\t\t^%d bytes written\n", ft_printf(G"ft_printf: [%% 010.7o] 42:This is a uint "G"[% 010.7o]"RST"\n", 42));
//	printf(Y"\t\t^%d bytes written\n", printf(Y"___printf: This is a uint "Y"[%+-10.7o]\n", 42));
	ft_printf(R"On next call original func doesn't use flag '+' results in undefined behavior with 'o' conversion specifier [%%->+-10.7o]!\n"R RST);
	printf(G"\t\t^%d bytes written\n", ft_printf(G"ft_printf: [%%+-10.7o] 42: "G"[%+-10.7o]"RST"\n", 42));
//	printf(Y"\t\t^%d bytes written\n", printf(Y"___printf: This is a uint "Y"[%- 10.*o]\n", 1<<12, 42));
	ft_printf(R"On next call original func doesn't use flag ' ' results in undefined behavior with 'o' conversion specifier [%%--> 10.*o]!\n"R RST);
	printf(G"\t\t^%d bytes written\n", ft_printf(G"ft_printf: [%%- 10.*o] 1<<12 42: "G"[%- 10.*o]"RST"\n", 1<<12, 42));
	printf(Y"\t\t^%d bytes written\n", printf(Y"___printf: [%%0.*o] 1<<8 42: "Y"[%0.*o]"RST"\n", 1<<8, 42));
	printf(G"\t\t^%d bytes written\n", ft_printf(G"ft_printf: [%%0.*o] 1<<8 42: "G"[%0.*o]"RST"\n", 1<<8, 42));
}

void	test_null()
{
	char *null = NULL; 
	ft_printf(M"************************* N U L L \tT E S T S *************************\n"RST);
	printf(Y"\t\t^%d bytes written\n", printf(Y"___printf: string null: "Y"%s"RST"\n", null));
	printf(G"\t\t^%d bytes written\n", ft_printf(G"ft_printf: string null: "G"%s"RST"\n", null));
	printf(Y"\t\t^%d bytes written\n", printf(Y"___printf: string null [%%10s]: "Y"[%10s]"RST"\n", null));
	printf(G"\t\t^%d bytes written\n", ft_printf(G"ft_printf: string null [%%10s]: "G"[%10s]"RST"\n", null));
	printf(Y"\t\t^%d bytes written\n", printf(Y"___printf: ptr NULL: "Y"%p"RST"\n", null));
	printf(G"\t\t^%d bytes written\n", ft_printf(G"ft_printf: ptr NULL: "G"%p"RST"\n", null));
	printf(Y"\t\t^%d bytes written\n", printf(Y"___printf: ptr NULL [%%20p]: "Y"[%20p]"RST"\n", null));
	printf(G"\t\t^%d bytes written\n", ft_printf(G"ft_printf: ptr NULL [%%20p]: "G"[%20p]"RST"\n", null));
	printf(Y"\t\t^%d bytes written\n", printf(Y"___printf: ptr NULL [%%-15p]: "Y"[%-15p]"RST"\n", null));
	printf(G"\t\t^%d bytes written\n", ft_printf(G"ft_printf: ptr NULL [%%-15p]: "G"[%-15p]"RST"\n", null));
}

void test_binary()
{
	ft_printf(M"************************* B I N A R Y \tT E S T S *************************\n"RST);
	//printf(Y"\t\t^%d bytes written\n", printf(Y"___printf: [%%10b] 42: "Y"[%10b]"RST"\n", 42));
	printf(G"\t\t^%d bytes written\n", ft_printf(G"ft_printf: [%%b] 42: "G"[%b]"RST"\n", 42));
	//printf(Y"\t\t^%d bytes written\n", printf(Y"___printf: [%%-10.3b] 42: "Y"[%-10.3b]"RST"\n", 42));
	printf(G"\t\t^%d bytes written\n", ft_printf(G"ft_printf: [%%-10.3b] 42: "G"[%-10.3b]"RST"\n", 42));
	//printf(Y"\t\t^%d bytes written\n", printf(Y"___printf: [%%-10.3b] -42: "Y"[%-10.3b]"RST"\n", -42));
	printf(G"\t\t^%d bytes written\n", ft_printf(G"ft_printf: [%%-10.3b] -42: "G"[%-10.3b]"RST"\n", -42));
//	printf(Y"\t\t^%d bytes written\n", printf(Y"___printf: This is a uint "Y"[%- 10.7o]\n", 42));
	ft_printf(R"On next call original func doesn't use flag ' ' results in undefined behavior with 'o' conversion specifier [%%--> 10.7o]!\n"R RST);
	printf(G"\t\t^%d bytes written\n", ft_printf(G"ft_printf: [%%- 10.7b] 42: "G"[%- 10.7b]"RST"\n", 42));
//	printf(Y"\t\t^%d bytes written\n", printf(Y"___printf: This is a uint "Y"[% 010.7o]\n", 42));
	ft_printf(R"On next call original func doesn't use flag ' ' results in undefined behavior with 'o' conversion specifier [%%-> 010.7o]!\n"R RST);
	printf(G"\t\t^%d bytes written\n", ft_printf(G"ft_printf: [%% 010.7b] 42:This is a uint "G"[% 010.7b]"RST"\n", 42));
//	printf(Y"\t\t^%d bytes written\n", printf(Y"___printf: This is a uint "Y"[%+-10.7o]\n", 42));
	ft_printf(R"On next call original func doesn't use flag '+' results in undefined behavior with 'o' conversion specifier [%%->+-10.7o]!\n"R RST);
	printf(G"\t\t^%d bytes written\n", ft_printf(G"ft_printf: [%%+-10.7b] 42: "G"[%+-10.7b]"RST"\n", 42));
//	printf(Y"\t\t^%d bytes written\n", printf(Y"___printf: This is a uint "Y"[%- 10.*o]\n", 1<<12, 42));
	ft_printf(R"On next call original func doesn't use flag ' ' results in undefined behavior with 'o' conversion specifier [%%--> 10.*o]!\n"R RST);
	printf(G"\t\t^%d bytes written\n", ft_printf(G"ft_printf: [%%- 10.*b] 1<<12 42: "G"[%- 10.*b]"RST"\n", 1<<12, 42));
//	printf(Y"\t\t^%d bytes written\n", printf(Y"___printf: [%%0.*b] 1<<8 42: "Y"[%0.*b]"RST"\n", 1<<8, 42));
	printf(G"\t\t^%d bytes written\n", ft_printf(G"ft_printf: [%%0.*b] 1<<8 42: "G"[%0.*b]"RST"\n", 1<<8, 42));
}

void test_other()
{
	ft_printf(M"************************* M O R E \tT E S T S *************************\n"RST);
	char long_string[5000];
	memset(long_string, 'a', 5000);
	long_string[4999] = 0;
	printf(Y"\t\t^%d bytes written\n", printf(Y"___printf: string with 5000 chars in buf: "Y"%s"RST"\n", long_string));
	printf(G"\t\t^%d bytes written\n", ft_printf(G"ft_printf: string with 5000 chars in buf: "G"%s"RST"\n", long_string));
	//printf(Y"\t\t^%d bytes written\n", printf(Y"___printf: specifiers > args [%%s %%d %%c %%x] \"Hello\", 10, 'R': "Y"[%s %d %c %x]"RST"\n", "Hello", 10, 'R'));
	printf(G"\t\t^%d bytes written\n", ft_printf(G"ft_printf: specifiers > args [%%s %%d %%c %%x] \"Hello\", 10, 'R': "G"[%s %d %c %x]"RST"\n", "Hello", 10, 'R'));
	printf(Y"\t\t^%d bytes written\n", printf(Y"___printf: specifiers < args [%%s %%d %%c] \"Hello\", 10, 'R': "Y"[%s %d %c %x]"RST"\n", "Hello", 10, 'R', 314));
	printf(G"\t\t^%d bytes written\n", ft_printf(G"ft_printf: specifiers < args [%%s %%d %%c] \"Hello\", 10, 'R': "G"[%s %d %c %x]"RST"\n", "Hello", 10, 'R', 314));
	//printf(Y"\t\t^%d bytes written\n", printf(Y"___printf: No specifier, but is arg [%%] "Y"[%]"RST"\n", 314));
	printf(G"\t\t^%d bytes written\n", ft_printf(G"ft_printf: No specifier, but is arg [%%] "Y"[%]"RST"\n", 314));
}

void test_man() 
{
	int n = 10;
	ft_printf(M"************************* I N T \tT E S T S *************************\n"RST);
	printf(Y"\t\t^%d bytes written\n", printf(Y"___printf: [%%d] 42: "Y"[%d]"RST"\n", 42));
	printf(G"\t\t^%d bytes written\n", ft_printf(G"ft_printf: [%%d] 42: "G"[%d]"RST"\n", 42));
	printf(Y"\t\t^%d bytes written\n", printf(Y"___printf: [%%d] -42: "Y"[%d]"RST"\n", -42));
	printf(G"\t\t^%d bytes written\n", ft_printf(G"ft_printf: [%%d] -42: "G"[%d]"RST"\n", -42));
	printf(Y"\t\t^%d bytes written\n", printf(Y"___printf: [%%d] 0: "Y"[%d]"RST"\n", 0));
	printf(G"\t\t^%d bytes written\n", ft_printf(G"ft_printf: [%%d] 0: "G"[%d]"RST"\n", 0));
	printf(Y"\t\t^%d bytes written\n", printf(Y"___printf: [%%d] INT_MAX: "Y"[%d]"RST"\n", INT_MAX));
	printf(G"\t\t^%d bytes written\n", ft_printf(G"ft_printf: [%%d] INT_MAX: "G"[%d]"RST"\n", INT_MAX));
	printf(Y"\t\t^%d bytes written\n", printf(Y"___printf: [%%d] INT_MIN: "Y"[%d]"RST"\n", INT_MIN));
	printf(G"\t\t^%d bytes written\n", ft_printf(G"ft_printf: [%%d] INT_MIN: "G"[%d]"RST"\n", INT_MIN));
	printf(Y"\t\t^%d bytes written\n", printf(Y"___printf: [%%i] 42: "Y"[%i]"RST"\n", 42));
	printf(G"\t\t^%d bytes written\n", ft_printf(G"ft_printf: [%%i] 42: "G"[%i]"RST"\n", 42));
	printf(Y"\t\t^%d bytes written\n", printf(Y"___printf: [%%i] -42: "Y"[%i]"RST"\n", -42));
	printf(G"\t\t^%d bytes written\n", ft_printf(G"ft_printf: [%%i] -42: "G"[%i]"RST"\n", -42));
	printf(Y"\t\t^%d bytes written\n", printf(Y"___printf: [%%i] 0: "Y"[%i]"RST"\n", 0));
	printf(G"\t\t^%d bytes written\n", ft_printf(G"ft_printf: [%%i] 0: "G"[%i]"RST"\n", 0));
	printf(Y"\t\t^%d bytes written\n", printf(Y"___printf: [%%i] INT_MAX: "Y"[%i]"RST"\n", INT_MAX));
	printf(G"\t\t^%d bytes written\n", ft_printf(G"ft_printf: [%%i] INT_MAX: "G"[%i]"RST"\n", INT_MAX));
	printf(Y"\t\t^%d bytes written\n", printf(Y"___printf: [%%i] INT_MIN: "Y"[%i]"RST"\n", INT_MIN));
	printf(G"\t\t^%d bytes written\n", ft_printf(G"ft_printf: [%%i] INT_MIN: "G"[%i]"RST"\n", INT_MIN));
	
	ft_printf(M"************************* C H A R \tT E S T S *************************\n"RST);
	printf(Y"\t\t^%d bytes written\n", printf(Y"___printf: "Y"[%%]"RST"\n"));
	printf(G"\t\t^%d bytes written\n", ft_printf(G"ft_printf: "G"[%%]"RST"\n"));
	printf(Y"\t\t^%d bytes written\n", printf(Y"___printf: Characters: "Y"%c %c"RST" \n", 'a', 65));
	printf(G"\t\t^%d bytes written\n", ft_printf(G"ft_printf: Characters: "G"%c %c"RST" \n", 'a', 65));
    printf(Y"\t\t^%d bytes written\n", printf(Y"___printf: [%%c]: "Y"[%c]"RST"\n", 'A'));
	printf(G"\t\t^%d bytes written\n", ft_printf(G"ft_printf: [%%c]: "G"[%c]"RST"\n", 'A'));

	ft_printf(M"************************* S T R \tT E S T S *************************\n"RST);
	char *null = NULL; 
	printf(Y"\t\t^%d bytes written\n", printf(Y"___printf: string null: "Y"%s"RST"\n", null));
	printf(G"\t\t^%d bytes written\n", ft_printf(G"ft_printf: string null: "G"%s"RST"\n", null));
	printf(Y"\t\t^%d bytes written\n", printf(Y"___printf: \t"Y"%s"RST" \n", "A string"));
	printf(G"\t\t^%d bytes written\n", ft_printf(G"ft_printf: \t"G"%s"RST" \n", "A string"));
	char *s = "42 Vienna is the best school in the world!";
	printf(Y"\t\t^%d bytes written\n", printf(Y"___printf: [%%s]: "Y"[%s]"RST"\n", s));
	printf(G"\t\t^%d bytes written\n", ft_printf(G"ft_printf: [%%s]: "G"[%s]"RST"\n", s));
	ft_printf(M"************************* P T R \tT E S T S *************************\n"RST);
	n = 42;
	char *name = "Andrey";
	char *ptr;
	ptr = name;
	printf(Y"\t\t^%d bytes written\n", printf(Y"___printf: NULL [%%p] "Y"%p"RST"\n", null));
	printf(G"\t\t^%d bytes written\n", ft_printf(G"ft_printf: NULL [%%p] "G"%p"RST"\n", null));
	printf(Y"\t\t^%d bytes written\n", printf(Y"___printf: [%%p] "Y"%p"RST"\n", ptr));
    printf(G"\t\t^%d bytes written\n", ft_printf(G"ft_printf: [%%p] "G"%p"RST"\n", ptr));
	printf(Y"\t\t^%d bytes written\n", printf(Y"___printf: [%%p]: "Y"[%p]"RST"\n", &n));
	printf(G"\t\t^%d bytes written\n", ft_printf(G"ft_printf: [%%p]: "G"[%p]"RST"\n", &n));

	ft_printf(M"************************* H E X \tT E S T S *************************\n"RST);
	n = 255;
	printf(Y"\t\t^%d bytes written\n", printf(Y"___printf: [%%X] -1: "Y"%X"RST"\n", -1));
	printf(G"\t\t^%d bytes written\n", ft_printf(G"ft_printf: [%%X] -1: "G"%X"RST"\n", -1));
	printf(Y"\t\t^%d bytes written\n", printf(Y"___printf: [%%x] 255: "Y"[%x]"RST"\n", n));
	printf(G"\t\t^%d bytes written\n", ft_printf(G"ft_printf: [%%x] 255: "G"[%x]"RST"\n", n));
	printf(Y"\t\t^%d bytes written\n", printf(Y"___printf: [%%X] 255: "Y"[%X]"RST"\n", n));
	printf(G"\t\t^%d bytes written\n", ft_printf(G"ft_printf: [%%X] 255: "G"[%X]"RST"\n", n));
	printf(Y"\t\t^%d bytes written\n", printf(Y"___printf: [%%x] 0: "Y"[%x]"RST"\n", 0));
	printf(G"\t\t^%d bytes written\n", ft_printf(G"ft_printf: [%%x] 0: "G"[%x]"RST"\n", 0));
	printf(Y"\t\t^%d bytes written\n", printf(Y"___printf: [%%X] 0: "Y"[%X]"RST"\n", 0));
	printf(G"\t\t^%d bytes written\n", ft_printf(G"ft_printf: [%%X] 0: "G"[%X]"RST"\n", 0));
	printf(Y"\t\t^%d bytes written\n", printf(Y"___printf: Negative value lowercase [%%x] -42: "Y"[%x]"RST"\n", -42));
	printf(G"\t\t^%d bytes written\n", ft_printf(G"ft_printf: Negative value lowercase [%%x] -42: "G"[%x]"RST"\n", -42));
	printf(Y"\t\t^%d bytes written\n", printf(Y"___printf: Negative value uppercase [%%X] -42: "Y"[%X]"RST"\n", -42));
	printf(G"\t\t^%d bytes written\n", ft_printf(G"ft_printf: Negative value uppercase [%%X] -42: "G"[%X]"RST"\n", -42));

	ft_printf(M"************************* O C T \tT E S T S *************************\n"RST);
	printf(Y"\t\t^%d bytes written\n", printf(Y"___printf: [%%o] 42: "Y"[%o]"RST"\n", 42));
	printf(G"\t\t^%d bytes written\n", ft_printf(G"ft_printf: [%%o] 42: "G"[%o]"RST"\n", 42));
	printf(Y"\t\t^%d bytes written\n", printf(Y"___printf: [%%o] -42: "Y"[%o]"RST"\n", -42));
	printf(G"\t\t^%d bytes written\n", ft_printf(G"ft_printf: [%%o] -42: "G"[%o]"RST"\n", -42));

	ft_printf(M"************************* U I N T \tT E S T S *************************\n"RST);
	printf(Y"\t\t^%d bytes written\n", printf(Y"___printf: [%%u] 42: "Y"[%u]"RST"\n", 42));
	printf(G"\t\t^%d bytes written\n", ft_printf(G"ft_printf: [%%u] 42: "G"[%u]"RST"\n", 42));
	printf(Y"\t\t^%d bytes written\n", printf(Y"___printf: [%%u] -42: "Y"[%u]"RST"\n", -42));
	printf(G"\t\t^%d bytes written\n", ft_printf(G"ft_printf: [%%u] -42: "G"[%u]"RST"\n", -42));

	ft_printf(M"************************* N U L L \tT E S T S *************************\n"RST);
	printf(Y"\t\t^%d bytes written\n", printf(Y"___printf: string null: "Y"%s"RST"\n", null));
	printf(G"\t\t^%d bytes written\n", ft_printf(G"ft_printf: string null: "G"%s"RST"\n", null));
	printf(Y"\t\t^%d bytes written\n", printf(Y"___printf: string null [%%10s]: "Y"[%10s]"RST"\n", null));
	printf(G"\t\t^%d bytes written\n", ft_printf(G"ft_printf: string null [%%10s]: "G"[%10s]"RST"\n", null));
	printf(Y"\t\t^%d bytes written\n", printf(Y"___printf: ptr NULL: "Y"%p"RST"\n", null));
	printf(G"\t\t^%d bytes written\n", ft_printf(G"ft_printf: ptr NULL: "G"%p"RST"\n", null));
	printf(Y"\t\t^%d bytes written\n", printf(Y"___printf: ptr NULL [%%20p]: "Y"[%20p]"RST"\n", null));
	printf(G"\t\t^%d bytes written\n", ft_printf(G"ft_printf: ptr NULL [%%20p]: "G"[%20p]"RST"\n", null));
	printf(Y"\t\t^%d bytes written\n", printf(Y"___printf: ptr NULL [%%-15p]: "Y"[%-15p]"RST"\n", null));
	printf(G"\t\t^%d bytes written\n", ft_printf(G"ft_printf: ptr NULL [%%-15p]: "G"[%-15p]"RST"\n", null));
	ft_printf(M"************************* M O R E \tT E S T S *************************\n"RST);
	char long_string[5000];
	memset(long_string, 'a', 5000);
	long_string[4999] = 0;
	printf(Y"\t\t^%d bytes written\n", printf(Y"___printf: string with 5000 chars in buf: "Y"%s"RST"\n", long_string));
	printf(G"\t\t^%d bytes written\n", ft_printf(G"ft_printf: string with 5000 chars in buf: "G"%s"RST"\n", long_string));
	printf(Y"\t\t^%d bytes written\n", printf(Y"___printf: specifiers > args [%%s %%d %%c %%x] \"Hello\", 10, 'R': "Y"[%s %d %c %x]"RST"\n", "Hello", 10, 'R'));
	printf(G"\t\t^%d bytes written\n", ft_printf(G"ft_printf: specifiers > args [%%s %%d %%c %%x] \"Hello\", 10, 'R': "G"[%s %d %c %x]"RST"\n", "Hello", 10, 'R'));
	printf(Y"\t\t^%d bytes written\n", printf(Y"___printf: specifiers < args [%%s %%d %%c] \"Hello\", 10, 'R': "Y"[%s %d %c]"RST"\n", "Hello", 10, 'R', 314));
	printf(G"\t\t^%d bytes written\n", ft_printf(G"ft_printf: specifiers < args [%%s %%d %%c] \"Hello\", 10, 'R': "G"[%s %d %c]"RST"\n", "Hello", 10, 'R', 314));
	printf(Y"\t\t^%d bytes written\n", printf(Y"___printf: No specifier, but is arg [%%] "Y"[%]"RST"\n", 314));
	printf(G"\t\t^%d bytes written\n", ft_printf(G"ft_printf: No specifier, but is arg [%%] "Y"[%]"RST"\n", 314));
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
			test_null();
			ft_printf("\v");
			test_other();
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
		else if (!strcmp(test, "test_null"))
			test_null();
		else if (!strcmp(test, "test_b"))
			test_binary();
		else if (!strcmp(test, "test_other"))
			test_other();
		else if (!strcmp(test, "test_man"))
			test_man();
		else 
		{
			printf(Y"___printf:\n\tYOUR INPUT: %s\n", test);
			ft_printf(G"ft_printf:\n\tYOUR INPUT: %s\n", test);
		}
	}
	else
		return (1);
}

