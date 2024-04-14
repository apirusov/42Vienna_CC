#include <limits.h>
#include <locale.h>
#include <stdarg.h>
#include <stdbool.h>
//#include <stdint.h>
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
	char *s = "Special Beam Cannon";
	TEST("This is a string: "Y"[%s]"RST"\n", s);
	TEST("This is a string: "G"[%s]"RST"\n", s);
	TEST("This is a string: "Y"[%10s]"RST"\n", s);
	TEST("This is a string: "G"[%10s]"RST"\n", s);
	TEST("This is a string: "Y"[%10.3s]"RST"\n", s);
	TEST("This is a string: "G"[%10.3s]"RST"\n", s);
	TEST("This is a string: "Y"[%-10.3s]"RST"\n", s);
	TEST("This is a string: "G"[%-10.3s]"RST"\n", s);
	TEST("This is a string: "Y"[%*.*s]"RST"\n", 10, s);
	TEST("This is a string: "G"[%*.*s]"RST"\n", 10, s);
}

int	main(int ac, char **av)
{
	if (ac > 1)
	{
		if (av[1] == "run tests")
		{
			test_char();
			test_str();
		}
		else 
		{
			TEST("YOUR INPUT: %s\n", av[1]);
		}
	}
	else
		return (1);
}

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
//	char null_char = '\0';

	count = printf("printf: \t%x\n", INT_MIN);
    count = ft_printf("ft_printf: \t%x\n\n", INT_MIN);
	
	printf ("printf: \tDecimals: %d %ld\n", 1977, 650000L);
	ft_printf ("ft_printf: \tDecimals: %d %ld\n\n", 1977, 650000L);
	printf ("printf: \tPreceding with blanks: %10d \n", 1977);
	ft_printf ("ft_printf: \tPreceding with blanks: %10d \n\n", 1977);
	printf ("printf: \tPreceding with zeros: %010d \n", 1977);
	ft_printf ("ft_printf: \tPreceding with zeros: %010d \n\n", 1977);
	printf ("printf: \tSome different radices: %d %x %o %#x %#o \n", 100, 100, 100, 100, 100);
	ft_printf ("ft_printf: \tSome different radices: %d %x %o %#x %#o \n\n", 100, 100, 100, 100, 100);
	printf ("printf: \tfloats: %4.2f %+.0e %E \n", 3.1416, 3.1416, 3.1416);
	ft_printf ("ft_printf: \tfloats: %4.2f %+.0e %E \n\n", 3.1416, 3.1416, 3.1416);
	printf ("printf: \tWidth trick: %*d \n", 5, 10);
	ft_printf ("ft_printf: \tWidth trick: %*d \n\n", 5, 10);
	printf ("printf: \t%s \n", "A string");
	ft_printf ("ft_printf: \t%s \n\n", "A string");
	printf("printf NULL %s\n", str);
    ft_printf("ft_printf NULL %s\n\n", str);
	printf("printf ptr NULL %p\n", str);
    ft_printf("ft_printf ptr NULL %p\n\n", str);
	printf("printf ptr \t%p\n", ptr);
    ft_printf("ft_printf ptr \t%p\n\n", ptr);
	printf("printf c: \t%c\n", 99);
	ft_printf("ft_printf c: \t%c\n\n", 99);
	printf("printf  \tINT_MIN : \t%d\tINT_MAX : \t%d\n", INT_MIN, INT_MAX);
	ft_printf("ft_printf \tINT_MIN : \t%d\tINT_MAX : \t%d\n\n", INT_MIN, INT_MAX);
	printf("printf :\tage_int(35.03) = %d\n", age_int);
	ft_printf("ft_printf :\tage_int(35.03) = %d\n\n", age_int);
	printf("printf :\tHello, \t%s, you are born @ %u.%o.%d, which means you are %f years old \
or %e%% of 100. (unexpected null!) %s It also is equal to %X or %x in \"hexadecimal\"\n", name, date, month, year, age_f, age_f, str, (int)age_f, (int)age_f);
	ft_printf("ft_printf:\tHello, \t%s, you are born @ %u.%o.%d, which means you are %d \
years old or %d%% of 100. (unexpected null!) %s It also is equal to %X or %x in \"hexadecimal\"\n\n", name, date, month, year, age, age, str, (int)age_f, (int)age_f);
	printf("printf: \tHello, %s, today is %d, in hex is %x or %X, char ->%c\n", "friend", 27, 27, 27, 'R');
	ft_printf("ft_printf: \tHello, %s, today is %d, in hex is %x or %X, char ->%c\n\n", "friend", 27, 27, 27, 'R');
	printf("printf :\t");
	while (i++ < 100)
		printf("%d ", i);
	printf ("\n");
	i = -1;
	ft_printf("ft_printf :\t");
	while (i++ < 100)
		ft_printf("%d ", i);
    printf ("\n\n");

	printf("printf: \tThe chars written are %X\n", -1);
	ft_printf("ft_printf: \tThe chars written are %X\n\n", -1);
//	count = (printf(stderr, "%s\n", explain_malloc(size));
//	ft_printf("Malloc size error = %d\n", count);
}