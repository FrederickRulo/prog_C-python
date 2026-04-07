#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main()
{
    char fichier[100];
    pid_t pid;

    while (1)
    {
        printf("Entrez un fichier (ou 'quit' pour quitter) : ");
        scanf("%s", fichier);

        if (strcmp(fichier, "quit") == 0)
        {
            printf("Fin du programme\n");
            break;
        }

        pid = fork();

        if (pid == 0)
        {
            
            execl("/usr/bin/emacs", "emacs", fichier, NULL);
            perror("Erreur exec");
            exit(1);
        }
        else
        {
            
            printf("Ouverture de %s...\n", fichier);
        }
    }

    return 0;
}
