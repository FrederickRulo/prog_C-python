#include <stdio.h>
#include <unistd.h>

int main() {
    int pid = fork();

    if (pid == 0) {
        
        printf("je suis le fils\n");
    } else {
        
        printf("je suis le père\n");
    }

    return 0;
}
