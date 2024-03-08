/*
 * switch.c
 *
 * A demonstration of C's switch statement
 */

#include <stdio.h>

const char *day_name(int day);
const char *month_name(int day);

int main()
{

    printf("%s\n", day_name(4));
    printf("%s\n", day_name(-5));

    printf("%s\n", month_name(4));
    printf("%s\n", month_name(0));

    return 0;
}

const char *day_name(int day)
{
    switch (day)
    {
        case 0:
            return "Monday";
            break;
        case 1:
            return "Tuesday";
            break;
        case 2:
            return "Wednesday";
            break;
        case 3:
            return "Thursday";
            break;
        case 4:
            return "Friday";
            break;
        case 5:
            return "Saturday";
            break;
        case 6:
            return "Sunday";
            break;
        default:
            return "Invalid day number!";
    }
}


const char *month_name(int month)
{
    switch (month)
    {
        case 0:
            return "Jan";
            break;
        case 1:
            return "Feb";
            break;
        case 2:
            return "Mar";
            break;
        case 3:
            return "Apr";
            break;
        case 4:
            return "May";
            break;
        case 5:
            return "Jun";
            break;
        case 6:
            return "Jul";
            break;
        case 7:
            return "Aug";
            break;
        case 8:
            return "Sep";
            break;
        case 9:
            return "Oct";
            break;
        case 10:
            return "Nov";
            break;
        case 11:
            return "Dec";
            break;
        default:
            return "Invalid month number!";
    }
}