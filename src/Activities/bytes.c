#include <stdio.h>
/*
 * bytes.c
 *
 * Explore how multi-byte values are stored in memory.
 */

// Declare a data type "byte" that is equivalent to
// "unsigned char". (Recall that chars in C are by
// definition single bytes.)
typedef unsigned char byte;

// Print a single byte in memory
void printByte(void *p);

// Print n bytes, starting at address p
void printBytes(void *p, int n);

int main()
{

    //char c = 'A';
    //printByte(&c);
    //char *string = "ABC123";
    //printBytes(string, 6);
    int n = 0x11223344;
    //int* num = &n;
    printBytes(n, 4);
    printf("\n");
    long d = 576.89;
    printBytes(&d, 7);
    printf("\n");
    char c = 'D';
    printBytes(&c, 1);
    printf("\n");
    long burger = 1029698543277;
    printBytes(&burger, 8);

    return 0;
}

// Recall that a void * is a "void pointer" - a pointer
// without saying what data type it points to - in other
// words, a pure memory address.
// To dereference a void pointer, you first need to cast
// it to another type of pointer, so that C knows how to
// interpret the binary data at the memory address.
void printByte(void *p)
{
    // Cast p to a byte pointer
    
    // Dereference the byte pointer and print as a
    // two-digit hex number
    printf("%02x", *(byte*)p);
    printf("\n");
}

void printBytes(void *p, int n)
{
    byte* b = p;

    for (int i = 0; i < n; i++)
    {
        printByte(&b[i]);
        printf("%p\n", &b[i]);
    }
}
