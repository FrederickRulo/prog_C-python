import sys

if len(sys.argv) != 3:
    print("Erreur : donne 2 nombres")
    exit()

a = int(sys.argv[1])
b = int(sys.argv[2])

somme = a + b

print("La somme est :", somme)
