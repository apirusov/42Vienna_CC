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
# define TEST(fmt, ...) FTPRINTF("ft_printf:\n^ %d bytes written\n",  
		FTPRINTF(fmt\n, ##__VA_ARGS__)) FTPRINTF("\n") \
		PRINTF("printf:\n^ %d bytes written\n", 
		PRINTF(fmt\n\n, ##__VA_ARGS__)) PRINTF("\n\n")

void    test_char()
{
	TEST("This is a char "Y"[%-*%]"RST"\n", n);
	TEST("c: \t%c\n", 99);
	TEST("%%\n");
	TEST("Characters: %c %c \n\n", 'a', 65);
    TEST("This is a char: "Y"[%c]"RST"\n", 'A');
	TEST("This is a char: "G"[%c]"RST"\n", 'A');
	TEST("This is a char: "Y"[%10c]"RST"\n", 'A');
	TEST("This is a char: "G"[%10c]"RST"\n", 'A');
	TEST("This is a char: "Y"[%-10c]"RST"\n", 'A');
	TEST("This is a char: "G"[%-10c]"RST"\n", 'A');
	int	n = 10;
	TEST("This is a char: "Y"[%-*c]"RST"\n", n, 'A');
	TEST("This is a char: "G"[%-*c]"RST"\n", n, 'A');
}

void test_str()
{
	char *null = NULL;
	TEST("string null: %s\n", null);
	TEST("\t%s \n\n", "A string");
	char *s = "Special Beam Cannon";
	TEST("This is a string: "G"[%s]"RST"\n", s);
	TEST("This is a string: "G"[%10s]"RST"\n", s);
	TEST("This is a string: "G"[%10.3s]"RST"\n", s);
	TEST("This is a string: "G"[%-10.3s]"RST"\n", s);
	TEST("This is a string: "G"[%*.*s]"RST"\n", 10, s);
}

void test_int()
{
	TEST("\t%x\n\n", INT_MIN);
	TEST("\tDecimals: %d %ld\n", 1977, 650000L);
	TEST("\tPreceding with blanks: %10d \n", 1977);
	TEST("\tPreceding with zeros: %010d \n", 1977);
	TEST("\tSome different radices: %d %x %o %#x %#o \n\n", 100, 100, 100, 100, 100);
	TEST("\tWidth trick: %*d \n\n", 5, 10);
	TEST("This is a int "G"[%i]"RST"\n", INT_MIN);
	TEST("This is a int "G"[%i]"RST"\n", INT_MIN);
	TEST("This is a int "G"[%d]"RST"\n", 42);
	TEST("This is a int "G"[%10d]"RST"\n", 42);
	TEST("This is a int "G"[%-10d]"RST"\n", 42);
	TEST("This is a int "G"[%-+10d]"RST"\n", 42);
	TEST("This is a int "G"[% 10d]"RST"\n", 42);
	TEST("This is a int "G"[%1d]"RST"\n", 42);
	TEST("This is a int "G"[%-10.3d]"RST"\n", 42);
	TEST("This is a int "G"[%- 10.7d]"RST"\n", 42);
	TEST("This is a int "G"[% 010.7d]"RST"\n", 42);
	TEST("This is a int "G"[%+-10.7d]"RST"\n", 42);
	TEST("This is a int "G"[%- 10.*d]"RST"\n", 1<<12, 42);
	TEST("This is a int "G"[%0.*d]"RST"\n", 1<<8, 42);
	TEST("Crazy: "G"[%-+10.4d]"RST"\n", 12345);
	TEST("Crazy: "G"[%010.8d]"RST"\n", 9876);
	TEST("Crazy: "G"[%-+*.*d]"RST"\n", 6, 3, 123);
	TEST("Crazy: "G"[%0*.*d]"RST"\n", 1<<5, 2, 42);
	TEST("Crazy: "G"[%0*.*d]"RST"\n", 5, 2, 42);
	TEST("Crazy: "G"[%-+10.5d]"RST"\n", 987654);
	TEST("Crazy: "G"[%*.*d]"RST"\n", 8, 1<<10, 123);
	TEST("Crazy: "G"[%*.*d]"RST"\n", 100, 50, 12345);
	TEST("Crazy: "G"[%-+0*.*d]"RST"\n", 1<<7, 3, 987);
	TEST("Crazy: "G"[%-1000.500d]"RST"\n", 87654);
	TEST("Crazy: "G"[%*.*d]"RST"\n", 15, 1<<11, 98765);
	TEST("Crazy: "G"[%-+01000.500d]"RST"\n", 123456);
	TEST("Crazy: "G"[%0*.*d]"RST"\n", 1<<6, 3, 42);
	TEST("Crazy: "G"[%-+*.*d]"RST"\n", 1<<8, 2, 9876);
	TEST("Max int: "G"[%d]"RST"\n", INT_MAX);
	TEST("Min int: "G"[%d]"RST"\n", INT_MIN);
}

void	test_ptr()
{
	int n = 42;
	char *str = NULL;
	TEST("ptr NULL %p\n", str);
	TEST("Basic pointer: "G"[%p]"RST"\n", &n);
	TEST("Width of 20: "G"[%20p]"RST"\n", &n);
	TEST("Left-justified with width of 15: "G"[%-15p]"RST"\n", &n);
	TEST("Alternate form: "G"[%#p]"RST"\n", &n);
	TEST("Crazy combination: "G"[%#-20p]"RST"\n", &n);
	TEST("Precision and width: "G"[%15.8p]"RST"\n", &n);
}

void test_X_x()
{
	int n = 255;
	TEST("\tThe chars written are %X\n", -1);
	TEST("Hexadecimal lowercase: "G"[%x]"RST"\n", n);
	TEST("Hexadecimal uppercase: "G"[%X]"RST"\n", n);
	TEST("Padded lowercase: "G"[%010x]"RST"\n", n);
	TEST("Zero-padded uppercase: "G"[%020X]"RST"\n", n);
	TEST("Precision lowercase: "G"[%.*x]"RST"\n", 5, n);
	TEST("Precision uppercase: "G"[%.*X]"RST"\n", 8, n);
	TEST("Left-justified lowercase: "G"[%-15x]"RST"\n", n);
	TEST("Left-justified uppercase: "G"[%-15X]"RST"\n", n);
	TEST("Alternate form lowercase: "G"[%#x]"RST"\n", n);
	TEST("Alternate form uppercase: "G"[%#X]"RST"\n", n);
	TEST("Zero value lowercase: "G"[%x]"RST"\n", 0);
	TEST("Zero value uppercase: "G"[%X]"RST"\n", 0);
	TEST("Large value lowercase: "G"[%x]"RST"\n", 4294967295);
	TEST("Large value uppercase: "G"[%X]"RST"\n", 4294967295);
	TEST("Negative value lowercase: "G"[%x]"RST"\n", -42);
	TEST("Negative value uppercase: "G"[%X]"RST"\n", -42);
}

void	test_u()
{
	TEST("This is a uint "G"[%-10.3u]"RST"\n", 42);
    TEST("This is a uint "G"[%- 10.7u]"RST"\n", 42);
	TEST("This is a uint "G"[% 010.7u]"RST"\n", 42);
	TEST("This is a uint "G"[%+-10.7u]"RST"\n", 42);
	TEST("This is a uint "G"[%- 10.*u]"RST"\n", 1<<12, 42);
	TEST("This is a uint "G"[%0.*u]"RST"\n", 1<<8, 42);
}

void	test_o()
{
	TEST("This is a uint "G"[%-10.3o]"RST"\n", 42);
    TEST("This is a uint "G"[%- 10.7o]"RST"\n", 42);
	TEST("This is a uint "G"[% 010.7o]"RST"\n", 42);
	TEST("This is a uint "G"[%+-10.7o]"RST"\n", 42);
	TEST("This is a uint "G"[%- 10.*o]"RST"\n", 1<<12, 42);
	TEST("This is a uint "G"[%0.*o]"RST"\n", 1<<8, 42);
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

