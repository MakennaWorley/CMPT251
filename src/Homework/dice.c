#include <stdio.h>
#include <time.h>

int diceRoll(int sideNumber);
int rand(void);
void srand(int seed);

int main()
{
    int diceNumber, sideNumber, diceRollValue, diceTotal, d20;

    srand(time(NULL));

    printf("\nHow many dice do you want to roll? ");
    scanf("%d", &diceNumber);

    printf("\nHow many sides on the dice? ");
    scanf("%d", &sideNumber);

    for (int i = 0; i < diceNumber; i++)
    {
        diceRollValue = diceRoll(sideNumber);

        if (i == (diceNumber - 1)) {
            printf("%d ", diceRollValue);
        }
        else
        {
            printf("%d + ", diceRollValue);
        }

        if (sideNumber == 20 && diceRollValue == 20)
        {
            d20++;
        }
        
        diceTotal = diceTotal + diceRollValue;

    }

    printf("= %d\n", diceTotal);

    if (d20 > 0)
    {
        printf("Wow! You got %d natural 20(s)!\n", d20);
    }
    return 0;
}

int diceRoll(int sideNumber)
{
    return (rand() % sideNumber) + 1;
}
