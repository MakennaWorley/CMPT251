#include <stdio.h>

int global = 5;

int main() {
    int local = 10;

    char *s = "This is a string";
    printf("Address of string: %p\n", s);

    printf("Address of main: %p\n", &main);
    printf("Address of gobal: %p\n", &global);
    printf("Address of local: %p\n", &local);

    int *mallocSomething = (int *)malloc(10 * sizeof(int));
    for (int i = 0; i < 10; i++) {
        mallocSomething[i] = i;
    }

    printf("Address of a malloc address: %p\n", mallocSomething);

    int enter;
    scanf("%d", &enter);
}
