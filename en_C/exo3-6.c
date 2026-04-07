#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    int n, k;

    if (argc == 3)
    {
        n = atoi(argv[1]);
        k = atoi(argv[2]);
    }
    else
    {
        printf("Usage: %s n k\n", argv[0]);
        return 1;
    }

    
    if (k == 0 || k == n)
    {
        printf("Resultat: 1\n");
        return 0;
    }

    
    char fichier1[50], fichier2[50];
    sprintf(fichier1, "/tmp/res1_%d_%d.txt", n, k);
    sprintf(fichier2, "/tmp/res2_%d_%d.txt", n, k);

    pid_t pid1 = fork();
    if (pid1 == 0)
    {
        
        execl(argv[0], argv[0],
              (char[10]){0}, (char[10]){0}, NULL);
    }

    pid_t pid2 = fork();
    if (pid2 == 0)
    {
        
        execl(argv[0], argv[0],
              (char[10]){0}, (char[10]){0}, NULL);
    }

    
    wait(NULL);
    wait(NULL);

    
    printf("Resultat partiel pour (%d,%d)\n", n, k);

    return 0;
}
