#include <stdio.h>
#include <unistd.h>

int main()
{
    // Call fork() here and print out the result

    printf("pid: %d\n", getpid());
    printf("ppid: %d\n\n", getppid());

    printf("fork: %d\n\n", fork());

    printf("pid: %d\n", getpid());
    printf("ppid: %d\n\n", getppid());


    // Wait until the user hits Enter to exit
    char *line;
    size_t n;
    printf("\nHit Enter to exit!\n");
    getline(&line, &n, stdin);

    return 0;
}
