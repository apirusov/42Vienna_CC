#include <stdio.h>

void *check(char *str)
{
    str = NULL;
    return (str);
}

int main(void)
{
    char *str = "Hello World!";
    char *res;

    printf("%p\n", str);
    res = check(str);
    printf("%p\n", str);
    printf("%p\n", res);
}