
#include <stdio.h>

//Author Makenna Worley

double convertedValue(double something);

int main()
{
    double input, output;

    printf("\nLets convert Fahrenheit to Kelvin. Please give me a temperature in Fahrenheit: ");
    scanf("%lf", &input);

    output = convertedValue(input);

    if (input <= 32)
    {
        printf("The temperature of %.2lf in Fahrenheit is %.2lf in Kelvin. That's too cold!\n", input, output);
    }
    else if (input >= 212)
    {
        printf("The temperature of %.2lf in Fahrenheit is %.2lf in Kelvin. That's too hot!\n", input, output);
    }
    else
    {
        printf("The temperature of %.2lf in Fahrenheit is %.2lf in Kelvin. That's just right? Maybe?\n", input, output);
    }

    return 0;
}

double convertedValue(double something)
{
//My brain has to things in steps cause I'm paranoid that I'll forget some step
    double constantMultiple = 5.0/9.0;
    double constantAdd = 273.15;

    double temp1, temp2, temp3;

    temp1 = something - 32;
    temp2 = temp1 * constantMultiple;
    temp3 = temp2 + constantAdd;

    return temp3;
    
}
