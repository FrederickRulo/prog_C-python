#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    pid_t pid1, pid2;

    pid1 = fork();

    if (pid1 == 0) {
        printf("je suis le fils 1\n");
    } else {
    
        pid2 = fork();

        if (pid2 == 0) {
            printf("je suis le fils 2\n");
        } else {
            printf("je suis le père\n");
        }
    }

    return 0;
}