#include <stdio.h>
#include <date.h>

int main() {

    int month = 0;
    printf("Give me a month number, such as 1 or 9 ");
    scanf("%d", &month);

    int days = date_days_in_month(month);
    if (days != 0)
    {
        printf("The %d month has %d days\n", month, days);
    }

    return 0;
}