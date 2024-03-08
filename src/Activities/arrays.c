#include <stdio.h>

void f();
void g();
void h();

int main()
{

    printf("--- f() ---\n");
    f();

    printf("--- g() ---\n");
    g();

    printf("--- h() ---\n");
    h();
    
    return 0;
}

void f()
{
    // Declare an array of ints
    // Differences from Java:
    //  - [] come after the variable *name*, not type
    //  - no "new" required
    int numbers[4] = { 1, 2, 3, 4 };

    printf("%d\n", numbers[0]);
    printf("%d\n", numbers[1]);
    printf("%d\n", numbers[2]);
    printf("%d\n", numbers[3]);
    printf("%d\n", sizeof(numbers));
}

void g()
{
    int moreNumbers[4] = {2,4,6,8};

    printf("%d\n", moreNumbers[0]);
    printf("%d\n", moreNumbers[1]);
    printf("%d\n", moreNumbers[2]);
    printf("%d\n", moreNumbers[3]);
    printf("size is %d\n\n", sizeof(moreNumbers));

    moreNumbers[99] = 42;
    printf("%d\n", moreNumbers[99]);
    printf("size is %d\n", sizeof(moreNumbers));

}

void h()
{
    long age;
    char family_name[16];
    char given_name[16];

    // Write code to input age, given name, and family name, then print
    // them out
    printf("Please give me your age: ");
    scanf("%ld", &age);
    printf("Please give me your family name (last name): ");
    scanf("%s", &family_name);
    printf("Please give me your given name (first name): ");
    scanf("%s", &given_name);

    printf("%ld, %s, %s\n", age, given_name, family_name);
    printf("age, given name, family name");
}

