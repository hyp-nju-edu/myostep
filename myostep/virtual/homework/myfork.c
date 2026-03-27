#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
int main(int argc, char *argv[]) {
    int x = 100;
    printf("before fork, parent sets x = %d\n", x);

    int rc = fork();
    if (rc < 0) {
        fprintf(stderr, "fork failed\n");
        exit(1);
    } else if (rc == 0) {
        printf("child process: x = %d\n", x);
    } else {
        printf("parent process: x = %d\n", x);
    }

    return 0;
}