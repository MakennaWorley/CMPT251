/*
 * shifts.c
 *
 * A program that demonstrates left and right shifts for signed and unsigned
 * integers.
 */

#include <stdio.h>

int shift_left_signed(int i, int bits);
int shift_right_signed(int i, int bits);
unsigned int shift_left_unsigned(unsigned int i, int bits);
unsigned int shift_right_unsigned(unsigned int i, int bits);
int print_int_bits(int i);

int main()
{
    int i, bits, result, resultFinal;
    printf("i = ");
    scanf("%d", &i);
    printf("bits = ");
    scanf("%d", &bits);

    result = shift_right_unsigned(i, bits);
    printf("%d\n", result);
    resultFinal = print_int_bits(shift_right_unsigned(i, bits));
    printf("%u\n", resultFinal);

    return 0;
}

//working
int shift_left_signed(int i, int bits)
{
    // Return the result of shifting i left by bits
    // For example....
    return i<<bits;
    // - shift_left_signed(15,2) should return 60
    // - shift_left_signed(-40, 3) should return -320

}

//working
int shift_right_signed(int i, int bits)
{
    // Return the result of shifting i right by bits
    // For example....
    return i>>bits;
    // - shift_right_signed(15,2) should return 3
    // - shift_right_signed(-40, 3) should return -5

}

//working
unsigned int shift_left_unsigned(unsigned int i, int bits)
{
    // Return the result of shifting i left by bits
    return i<<bits;
    // For example, shift_left_unsigned(15,2) should return 60

}

unsigned int shift_right_unsigned(unsigned int i, int bits)
{
    // Return the result of shifting i right by bits
    return i>>bits;
    // For example, shift_right_unsigned(15,2) should return 3

}

int print_int_bits(int i)
{
    for (int bit = 31; bit >= 0; --bit)
    {
        printf("%c", (i & 0x80000000) ? '1' : '0');
        i = i << 1;
    }
    return i;
}
