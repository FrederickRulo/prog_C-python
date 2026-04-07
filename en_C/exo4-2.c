#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

int main()
{
    int p1[2], p2[2]; 
    pid_t pid;
    char mot[100];
    char mot_lu[100];
    int trouve = 0;
    FILE *f;

    pipe(p1);
    pipe(p2);

    pid = fork();

    if (pid == 0)
    {
        
        close(p1[0]); 
        close(p2[1]); 

        
        dup2(p2[0], STDIN_FILENO); 
        dup2(p1[1], STDOUT_FILENO); 

        printf("Entrez un mot : ");
        fflush(stdout);

        scanf("%s", mot);

        printf("%s\n", mot);
        fflush(stdout);

        
        scanf("%d", &trouve);

        if (trouve)
            printf("Mot trouvé !\n");
        else
            printf("Mot non trouvé !\n");

        exit(0);
    }
    else
    {

        close(p1[1]); 
        close(p2[0]); 

        
        dup2(p1[0], STDIN_FILENO);  
        dup2(p2[1], STDOUT_FILENO); 

        
        scanf("%s", mot);

        f = fopen("texte.txt", "r");
        if (f == NULL)
        {
            printf("Erreur fichier\n");
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

        
        printf("%d\n", trouve);
        fflush(stdout);

        wait(NULL);
    }

    return 0;
}
