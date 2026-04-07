import os

while True:
    fichier = input("Entrez un fichier (ou 'quit') : ")

    if fichier == "quit":
        print("Fin du programme")
        break

    os.system("emacs " + fichier + " &")
