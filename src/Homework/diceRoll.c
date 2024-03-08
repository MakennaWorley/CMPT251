#include <stdio.h>
#include <time.h>

int diceRoll(int *a, int *b, int *c);
int rand(void);
void srand(int seed);
int min(int a, int b);
int max (int a, int b);

int main()
{
    int *a, *b, *c;

    srand(time(NULL));

    printf("Dice roll! I am rolling four six-sided dice and dropping the lowest.\n\n");

    int total = diceRoll(&a, &b, &c);

    printf("%d!\n%d!\n%d!\n", a, b, c);
    printf("\n%d + %d + %d = %d\n", a, b, c, total);

    return 0;

}

int diceRoll(int *a, int *b, int *c)
{
    int d1, d2, d3, d4, a1, a2, a3, temp1, temp2;
    d1 = (rand() % 6) + 1;
    d2 = (rand() % 6) + 1;
    d3 = (rand() % 6) + 1;
    d4 = (rand() % 6) + 1;

    a1 = max(d1,d2);
    a2 = max(d3,d4);
    temp1 = min(d1,d2);
    temp2 = min(d3,d4);
    a3 = max(temp1,temp2);

    *a = a1;
    *b = a2;
    *c = a3;

    return a1+a2+a3;
}

int min(int a, int b)
{
    if (a>b)
        return b;
    else
        return a;
}

int max(int a, int b)
{
    if (a>b)
        return a;
    else
        return b;
}
