#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <time.h>

int main() {
    pid_t pid1, pid2;
    time_t start, end;

    srand(time(NULL)); 
    start = time(NULL); 

    pid1 = fork();
    if (pid1 == 0) {
        
        int t = rand() % 10 + 1;
        printf("fils 1 : je vais dormir %d secondes\n", t);
        sleep(t);
        printf("fils 1 terminé\n");
        exit(0);
    } else {
        pid2 = fork();
        if (pid2 == 0) {
        
            int t = rand() % 10 + 1;
            printf("fils 2 : je vais dormir %d secondes\n", t);
            sleep(t);
            printf("fils 2 terminé\n");
            exit(0);
        } else {
            
            wait(NULL);
            wait(NULL);
            end = time(NULL);
            printf("Durée totale : %ld secondes\n", end - start);
        }
    }

    return 0;
}
