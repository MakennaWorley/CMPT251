#include <stdio.h>

struct person {
    char given_name[100];
    char family_name[100];
    int age;
};

typedef struct person person_t;

void inputPerson(person_t *person);
void printPerson(person_t *person);

int main()
{

    struct person person;
    inputPerson(&person);
    printPerson(&person);

    return 0;
}

void inputPerson(person_t *person)
{
    // Add code here to prompt the user for each field
    // in struct person, then scanf() them into the
    // person pointed to by the struct.
    //
    // DO NOT declare any variables in this function.
    // scanf() directly into person.
    printf("Please enter your given name: ");
    scanf("%s", &person -> given_name);
    printf("Please enter you family name: ");
    scanf("%s", &person -> family_name);
    printf("PLease enter you age: ");
    scanf("%d", &person -> age);

}

void printPerson(person_t *person)
{
    // Add code here to print out all fields of the person.
    // Use -> to access its fields.
    printf("Your whole name is %s, %s. Last, First\n", person -> family_name, person -> given_name);
    printf("Your age is %d\n", person -> age);

}
