
/*
 * project.c
 *
 * Project 1: split up the fields of a double value to
 * manipulate its value.
 *
 * Makenna Worley
 */

#include <stdio.h>


// These functions will be implemented in a separate file
// (hence "extern") for Steps 1 and 4
extern long double_to_long_bits(double x);
extern double long_bits_to_double(long l);

// Functions to fill in for Step 2
long sign_of(long l);
long exponent_of(long l);
long fraction_of(long l);

// Function to fill in for Step 3
long assemble_long_bits(long sign, long exponent, long fraction);

// Functions to fill in for Step 5
double log_base_2(double x);
double negative_zero();
double infinity();
double halve(double x);

int main()
{
    // Write your code to test your functions here
    // (for Step 5, replace with your final program)
    
    double input;
    printf("Give me a number: ");
    scanf("%lf", &input);
    printf("input is: %lf\n", input);
    long dtob = double_to_long_bits(input);
    printf("double_to_long_bits test: %ld\n", dtob);

    //Testing infinity
    //double i;
    //printf("Give me a number: ");
    //scanf("%lf", &i);
    //printf("input is: %lf\n", i);
    //double number = input/i;
    //long dtob = double_to_long_bits(number);
    
    //Testing step 2
    long f = fraction_of(dtob);
    printf("fraction bits of %ld is %ld\n", dtob, f);
    long e = exponent_of(dtob);
    printf("exponent bits of %ld is %ld\n", dtob, e);
    long s = sign_of(dtob);
    printf("sign bit of %ld is %ld\n", dtob, s);

    //Testing step 3
    long whole = assemble_long_bits(s,e,f);
    printf("The reassembled long is: %ld\n", whole);

    //Testing step 4
    //long input;
    //printf("Give me a long: ");
    //scanf("%ld", &input);
    //double lbtd = long_bits_to_double(input);
    //printf("long_bits_to_double test: %lf\n", lbtd);

    //Testing step 5 method with arguments
    //double log = log_base_2(input);
    //printf("log base 2 of %lf is: %lf\n", input, log);
    //double half = halve(input);
    //printf("half of %lf is: %lf\n", input, half);


    return 0;
}

// -- Functions for Step 2 --
long sign_of(long l)
{
    //get rid of 63 bits
    long signOnly = l>>63;
    return signOnly&0x1;
}

long exponent_of(long l)
{
    //get rid of last 52 bits
    long noFraction = l>>52;
    //0111 - 7
    // 0x7ff
    return noFraction&0x7ff;
}

long fraction_of(long l)
{
    //maskLast52
    // 0xSEEE EEEE EEEE FFFF FFFF FFFF FFFF FFFF FFFF FFFF FFFF FFFF FFFF FFFF FFFF FFFF
    // 0x000fffffffffffff
    return l&0x000fffffffffffff;
}

// -- Function for Step 3 --
long assemble_long_bits(long sign, long exponent, long fraction)
{
    if (sign == 1 && exponent == 0 && fraction == 0)
    {
        printf("This has a negative zero\n");
        printf("%lf\n", negative_zero());
        return negative_zero();
    }
    else if (exponent == 0x7ff)
    {
        printf("This should be infinity\n");
        return infinity();
    }
    else{
    long whole = (sign<<63) | (exponent<<52) | fraction;
    return whole;
    }
}

// -- Functions for Step 5 --
double log_base_2(double x)
{
    //make x into a long
    long l = double_to_long_bits(x);
    //get exponent part
    long e = exponent_of(l);
    //subtract 1023
    e = e - 1023;
    return e;
}

double negative_zero() //This kinda works, doesn't print final right
{
    return -0.0;
}

double infinity() //This is not finished, but can work
{
    return 8734; //unicode for infinity sysmbol in UTF-8
}

double halve(double x)
{
    long l = double_to_long_bits(x);
    long e = exponent_of(l);
    e = e - 1;

    long s = sign_of(l);
    long f = fraction_of(l);

    long newl = assemble_long_bits(s,e,f);
    double a = long_bits_to_double(newl);

    return a;
}
