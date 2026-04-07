#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

#define TAILLE 100

int main()
{
    int tube1[2], tube2[2];
    pid_t pid;
    char mot[TAILLE], mot_lu[TAILLE];
    FILE *f;
    int trouve = 0;

    pipe(tube1); 
    pipe(tube2); 

    pid = fork();

    if (pid == 0)
    {
        
        close(tube1[0]); 
        close(tube2[1]); 

        printf("Entrez un mot : ");
        scanf("%s", mot);

        write(tube1[1], mot, TAILLE);

        read(tube2[0], &trouve, sizeof(int));

        if (trouve)
            printf("Mot trouvé !\n");
        else
            printf("Mot non trouvé !\n");
    }
    else
    {
        
        close(tube1[1]); 
        close(tube2[0]); 

        read(tube1[0], mot, TAILLE);

        f = fopen("texte.txt", "r");
        if (f == NULL)
        {
            printf("Erreur ouverture fichier\n");
            exit(1);
        }

        
        while (fscanf(f, "%s", mot_lu) != EOF)
        {
            if (strcmp(mot, mot_lu) == 0)
            {
                trouve = 1;
                break;
            }
        }

        fclose(f);

        write(tube2[1], &trouve, sizeof(int));

        wait(NULL);
    }

    return 0;
}
