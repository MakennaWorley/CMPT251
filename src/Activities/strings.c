#include <stdio.h>
#include <stdlib.h>

// Return the length of the string by counting the number of
// characters (bytes) *before* the NUL terminator. E.g.
// length("ABC") should return 3, not 4.
unsigned int length(const char *string);

// Copy all characters (bytes) of a string from one memory
// location to another, stopping after copying the NUL
// terminator.
void copy(const char *from, char *to);

// Returns a new string consisting of the concatenation of first and second
// (for example, concatenate("ABC", "123") returns a new string "ABC123").
// This function uses malloc() to allocate memory for the new string, so
// the caller must free() it when done using it.
char *concatenate(const char *first, const char *second);

int main(int argc, char *argv[])
{

    /*char *hello = "Hello";
    char *test1 = "ABC123";
    char *zero1 = "";
    char *zero2 = " ";

    printf("Hello is %d characters long\n", length(hello));
    printf("test1 is %d characters long\n", length(test1));
    printf("zero1 is %d characters long\n", length(zero1));
    printf("zero2 is %d characters long\n", length(zero2));

    if (argc != 2)
    {
        printf("You didn't give me an argument\n");
    }
    else
    {
        printf("Your input is %d characters long\n", length(argv[1]));
    } */

    // For testing copy() (delete line below when ready to test)
    // Note: in C, if you put multiple string literals ("...") consecutively
    // in a program, the compiler joins them into a single string. (This is
    // helpful because C doesn't have a string concatenation operator!)
    /*char source[500] =
        "An examination of a computer system from the programmer's perspective. "
        "Examines how your programs interact with the compiler, the assembler, "
        "the operating system, and hardware, enabling students to write "
        "software that is efficient, modular, and versatile. Introduces the C "
        "programming language, the Linux operating system, and assembly "
        "programming.";

    char dest[500];

    copy(source, dest);
    printf("CMPT 251 catalog description:\n%s\n", dest);*/
    // End of copy() testing code
    //

    char *hello = "Hello ";
    char *world = "World!\n";
    printf("%s", concatenate(hello, world));
    free(concatenate(hello, world));

    return 0;
}

unsigned int length(const char *string)
{
    int counter = 0;
    int i = 0;

    while(string[i] != '\0')
    {
        counter = counter + 1;
        i = i + 1;
    }

    return counter;
}

void copy(const char *from, char *to)
{
    int i = 0;
    while(from[i] != '\0')
    {
        to[i] = from[i];
        i = i + 1;
    }

}

char *concatenate(const char *first, const char *second)
{
    int length1 = length(first);
    int length2 = length(second);
    int size = length1 + length2;

    char *newString = (char *)malloc(size);
    int i = 0;
    int counter = 0;
    while(first[i] != '\0')
    {
        newString[counter] = first[i];
        counter = counter + 1;
        i = i + 1;
    }
    i = 0;
    while(second[i] != '\0')
    {
        newString[counter] = second[i];
        counter = counter + 1;
        i = i + 1;
    }

    return newString; // Delete and replace with your own code
}

