#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
    char fichier[100];

    
    printf("Entrez le nom du fichier : ");
    scanf("%s", fichier);

    execl("/usr/bin/emacs", "emacs", fichier, NULL);


    perror("Erreur exec");
    return 1;
}
