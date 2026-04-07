#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

int main()
{
    char rep[100];
    pid_t pid;

    while (1)
    {
        printf("Entrez un repertoire (ou 'quit' pour quitter) : ");
        scanf("%s", rep);

        
        if (strcmp(rep, "quit") == 0)
        {
            printf("Fin du programme\n");
            break;
        }

        pid = fork();

        if (pid == 0)
        {
            
            execlp("cp", "cp", "-r", ".", rep, NULL);
            perror("Erreur exec");
            exit(1);
        }
        else
        {
            
            wait(NULL);
            printf("Copie vers %s terminée\n", rep);
        }
    }

    return 0;
}
