#include <stdio.h>

int print_int_bits(int n);

int main()
{
    int n = 3492;
    printf("%d in bits\n", print_int_bits(n));
    return 0;
}


int print_int_bits(int n)
{
    for (int bit = 31; bit >= 0; --bit)
    {
        printf("%c", (n & 0x80000000) ? '1' : '0');
        n = n << 1;
    }

    return n;
}
