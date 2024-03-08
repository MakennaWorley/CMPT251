#include <stdio.h>
#include <stdlib.h>

ssize_t getline(char **text, size_t *n, FILE *stream);

int main()
{
    char *text;
    size_t size = 0;
    ssize_t final;

    while (1)
    {
        final = getline(&text, &size, stdin);

        if (final == -1)
        {
            break;
        }

        printf("    %s", text);
    }
    //free(text);
    return 0;
}

