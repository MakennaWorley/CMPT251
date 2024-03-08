/*
 * 12days.c
 *
 * Taking advantage of switch statement fallthrough to
 * print the "Twelve Days of Christmas" carol
 */

#include <stdio.h>

// Returns the ordinal numeral for n (e.g. "first", "second",
// "third")
const char *ordinal_numeral(int n);

// Prints the nth verse of the Twelve Days of Christmas song
void print_verse(int n);

int main()
{
    for (int i = 1; i <= 12; ++i) {
        printf("On the %s day of Chirstmas my true love gave to me\n", ordinal_numeral(i));
        print_verse(i);
    }

    return 0;
}

const char *ordinal_numeral(int n)
{
    // Use a switch statement to return the correct string
    // for 1 <= n <= 12
        switch (n)
    {
        case 1:
            return "first";
            break;
        case 2:
            return "second";
            break;
        case 3:
            return "third";
            break;
        case 4:
            return "fourth";
            break;
        case 5:
            return "fifth";
            break;
        case 6:
            return "sixth";
            break;
        case 7:
            return "seventh";
            break;
        case 8:
            return "eighth";
            break;
        case 9:
            return "nineth";
            break;
        case 10:
            return "tenth";
            break;
        case 11:
            return "eleventh";
            break;
        case 12:
            return "twelveth";
            break;
        default:
            return "Invalid number";
    }
}

void print_verse(int n)
{
    // Use ordinal_numeral() to get the ordinal numeral
    // from the first line ("first", "second", etc.)


    // Then use a switch statement with fallthrough to
    // print the lines of the verse
    n = 12-(n-1);
    switch (n)
    {
        case 1:
            printf("Twelve drummers drumming\n");
        case 2:
            printf("Eleven pipers piping\n");
        case 3:
            printf("Ten lords a-leaping\n");
        case 4:
            printf("Nine ladies dancing\n");
        case 5:
            printf("Eight maids a-milking\n");
        case 6:
            printf("Seven swans a-swimming\n");
        case 7:
            printf("Six geese a-laying\n");
        case 8:
            printf("Five gold rings\n");
        case 9:
            printf("Four calling birds\n");
        case 10:
            printf("Three french hens\n");
        case 11:
            printf("Two turtle doves\n");
        case 12:
            printf("A partridge in a pear tree\n\n\n");
        default:
            return "\n\n";
    }
    
}
