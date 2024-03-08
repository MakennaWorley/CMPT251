#include <stdio.h>
#include <stdlib.h>

double *inputDoubleArray(int *n);

int main()
{
    int size;
    int *n = &size;

    double *array = inputDoubleArray(n);

    //printing array values from pointer
    int sizeArray = *n;

    //sum
    printf("address of array is %p\n", array);
    double sum = 0;
    double temp;
    for (int i = 0; i < sizeArray; i++)
    {
        temp = array[i];
        sum = sum + temp;
    }
    printf("\nThe sum is %lf\n", sum);

    //average
    double average = sum/sizeArray;
    printf("The average is %lf\n", average);

    free(array);
}

double *inputDoubleArray(int *n)
{
    printf("How many numbers do you have? ");
    scanf("%d", n);

    int size = *n;

    double *array = malloc(size*sizeof(double));

    printf("Enter the numbers separated by spaces: ");
    for (int i = 0; i < size; i++)
    {
        scanf("%lf", &array[i]);
    }

    return array;

}
