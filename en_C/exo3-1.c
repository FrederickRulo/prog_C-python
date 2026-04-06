#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        printf("Erreur : donne 2 nombres\n");
        return 1;
    }

    
    int a = atoi(argv[1]);
    int b = atoi(argv[2]);

    int somme = a + b;
    printf("La somme est : %d\n", somme);

    return 0;
}
