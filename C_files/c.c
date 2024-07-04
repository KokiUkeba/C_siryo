#include<stdio.h>

int print_string(char *str);

int main(void)
{
    char str[10] = {"h" "e" "l" "l" "o" "\0"};

    print_string(str);    
    
    return 0;
}

int print_string(char *str)
{
    int n = 0;
    
    while(*str != '\0') {
        n += printf("%c", *(str++));
    }

    n += printf("\n");
    return n;
}
