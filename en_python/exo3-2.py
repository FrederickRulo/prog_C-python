mot = input("Entrez un mot : ")

with open("texte.txt", "r") as f:
    mots = f.read().split()

if mot in mots:
    print("Mot trouvé !")
else:
    print("Mot non trouvé !")
