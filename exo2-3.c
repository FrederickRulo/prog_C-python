#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main() {
    int i;
    pid_t pid;

    for (i = 0; i < 5; i++) {
        pid = fork();

        if (pid == 0) {
         
            printf("je suis le fils %d\n", i + 1);
            break;
        }
    }

    return 0;
}