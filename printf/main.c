#include <limits.h>
#include <locale.h>
#include <stdarg.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <wchar.h>

# define FTPRINTF ft_printf
# define PRINTF printf
# define TEST(fmt, ...) ({FTPRINTF("ft_printf:\n^ %d bytes written\n", \
		FTPRINTF(fmt, ##__VA_ARGS__)); \
		FTPRINTF("\n"); \
		PRINTF("printf:\n^ %d bytes written\n", PRINTF(fmt, ##__VA_ARGS__)); \
		PRINTF("\n\n");})

void    test_char()
{
	TEST("This is a char [%-*%]\n", n);
	TEST("c: \t%c\n", 99);
	TEST("%%\n");
	TEST("Characters: %c %c \n\n", 'a', 65);
    TEST("This is a char: [%c]\n", 'A');
	TEST("This is a char: [%c]\n", 'A');
	TEST("This is a char: [%10c]\n", 'A');
	TEST("This is a char: [%10c]\n", 'A');
	TEST("This is a char: [%-10c]\n", 'A');
	TEST("This is a char: [%-10c]\n", 'A');
	int	n = 10;
	TEST("This is a char: \"Y\"[%-*c]\"RST\"\n", n, 'A');
	TEST("This is a char: \"G\"[%-*c]\"RST\"\n", n, 'A');
}

void test_str()
{
	char *null = NULL;
	TEST("string null: %s\n", null);
	TEST("\t%s \n\n", "A string");
	char *s = "Special Beam Cannon";
	TEST("This is a string: 'G'[%s]'RST'\n", s);
	TEST("This is a string: 'G'[%10s]'RST'\n", s);
	TEST("This is a string: 'G'[%10.3s]'RST'\n", s);
	TEST("This is a string: 'G'[%-10.3s]'RST'\n", s);
	TEST("This is a string: 'G'[%*.*s]'RST'\n", 10, s);
}

void test_int()
{
	TEST("\t%x\n\n", INT_MIN);
	TEST("\tDecimals: %d %ld\n", 1977, 650000L);
	TEST("\tPreceding with blanks: %10d \n", 1977);
	TEST("\tPreceding with zeros: %010d \n", 1977);
	TEST("\tSome different radices: %d %x %o %#x %#o \n\n", 100, 100, 100, 100, 100);
	TEST("\tWidth trick: %*d \n\n", 5, 10);
	TEST("This is a int [%i]\"RST\"\n", INT_MIN);
	TEST("This is a int [%i]\"RST\"\n", INT_MIN);
	TEST("This is a int [%d]\n", 42);
	TEST("This is a int [%10d]\n", 42);
	TEST("This is a int [%-10d]\n", 42);
	TEST("This is a int [%-+10d]\n", 42);
	TEST("This is a int [% 10d]\n", 42);
	TEST("This is a int [%1d]\n", 42);
	TEST("This is a int [%-10.3d]\n", 42);
	TEST("This is a int [%- 10.7d]\n", 42);
	TEST("This is a int [% 010.7d]\n", 42);
	TEST("This is a int [%+-10.7d]\n", 42);
	TEST("This is a int [%- 10.*d]\n", 1<<12, 42);
	TEST("This is a int [%0.*d]\n", 1<<8, 42);
	TEST("Crazy: [%-+10.4d]\n", 12345);
	TEST("Crazy: [%010.8d]\n", 9876);
	TEST("Crazy: [%-+*.*d]\n", 6, 3, 123);
	TEST("Crazy: [%0*.*d]\n", 1<<5, 2, 42);
	TEST("Crazy: [%0*.*d]\n", 5, 2, 42);
	TEST("Crazy: [%-+10.5d]\n", 987654);
	TEST("Crazy: [%*.*d]\n", 8, 1<<10, 123);
	TEST("Crazy: [%*.*d]\n", 100, 50, 12345);
	TEST("Crazy: [%-+0*.*d]\n", 1<<7, 3, 987);
	TEST("Crazy: [%-1000.500d]\n", 87654);
	TEST("Crazy: [%*.*d]\n", 15, 1<<11, 98765);
	TEST("Crazy: [%-+01000.500d]\n", 123456);
	TEST("Crazy: [%0*.*d]\n", 1<<6, 3, 42);
	TEST("Crazy: [%-+*.*d]\n", 1<<8, 2, 9876);
	TEST("Max int: [%d]\n", INT_MAX);
	TEST("Min int: [%d]\n", INT_MIN);
}

void	test_ptr()
{
	int n = 42;
	char *str = NULL;
	TEST("ptr NULL %p\n", str);
	TEST("Basic pointer: [%p]\n", &n);
	TEST("Width of 20: [%20p]\n", &n);
	TEST("Left-justified with width of 15: [%-15p]\n", &n);
	TEST("Alternate form: [%#p]\n", &n);
	TEST("Crazy combination: [%#-20p]\n", &n);
	TEST("Precision and width: [%15.8p]\n", &n);
}

void test_X_x()
{
	int n = 255;
	TEST("\tThe chars written are %X\n", -1);
	TEST("Hexadecimal lowercase: [%x]\n", n);
	TEST("Hexadecimal uppercase: [%X]\n", n);
	TEST("Padded lowercase: [%010x]\n", n);
	TEST("Zero-padded uppercase: [%020X]\n", n);
	TEST("Precision lowercase: [%.*x]\n", 5, n);
	TEST("Precision uppercase: [%.*X]\n", 8, n);
	TEST("Left-justified lowercase: [%-15x]\n", n);
	TEST("Left-justified uppercase: [%-15X]\n", n);
	TEST("Alternate form lowercase: [%#x]\n", n);
	TEST("Alternate form uppercase: [%#X]\n", n);
	TEST("Zero value lowercase: [%x]\n", 0);
	TEST("Zero value uppercase: [%X]\n", 0);
	TEST("Large value lowercase: [%x]\n", 4294967295);
	TEST("Large value uppercase: [%X]\n", 4294967295);
	TEST("Negative value lowercase: [%x]\n", -42);
	TEST("Negative value uppercase: [%X]\n", -42);
}

void	test_u()
{
	TEST("This is a uint [%-10.3u]\n", 42);
    TEST("This is a uint [%- 10.7u]\n", 42);
	TEST("This is a uint [% 010.7u]\n", 42);
	TEST("This is a uint [%+-10.7u]\n", 42);
	TEST("This is a uint [%- 10.*u]\n", 1<<12, 42);
	TEST("This is a uint [%0.*u]\n", 1<<8, 42);
}

void	test_o()
{
	TEST("This is a uint [%-10.3o]\n", 42);
    TEST("This is a uint [%- 10.7o]\n", 42);
	TEST("This is a uint [% 010.7o]\n", 42);
	TEST("This is a uint [%+-10.7o]\n", 42);
	TEST("This is a uint [%- 10.*o]\n", 1<<12, 42);
	TEST("This is a uint [%0.*o]\n", 1<<8, 42);
}

int	main(int ac, char **av)
{
    char			*name = "Andrey";
    unsigned int	date =  28;
    int				month = 3;
    int				year = 1989;
	int				age = 35;
	float			age_f = 35.03;
	int				age_int = (int)age_f;
    int				i = -1;
	int				count;
	char			*str = NULL;
	char			*ptr = name; 
	if (ac > 1)
	{
		if (av[1] == "tests")
		{
			test_char();
			test_str();
			test_int();
			test_ptr();
			test_X_x();
			test_u();
			test_o();
			TEST("\tHello, \t%s, you are born @ %u.%o.%d, which means you are %f years old \
or %e%% of 100. (unexpected null!) %s It also is equal to %X or %x in \"hexadecimal\"\n", name, date, month, year, age_f, age_f, str, (int)age_f, (int)age_f);
			TEST("\tHello, %s, today is %d, in hex is %x or %X, char ->%c\n", "friend", 27, 27, 27, 'R');
		}
		else if (av[1] == "test_char")
			test_char();
		else if (av[1] == "test_str")
			test_str();
		else if (av[1] == "test_int")
			test_int();
		else if (av[1] == "test_ptr")
			test_ptr();
		else if (av[1] == "test_X_x")
			test_X_x();
		else if (av[1] == "test_u")
			test_u();
		else if (av[1] == "test_o")
			test_o();
		else 
		{
			TEST("YOUR INPUT: %s\n", av[1]);
		}
	}
	else
		return (1);
}

