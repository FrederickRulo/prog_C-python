import os

while True:
    rep = input("Entrez un repertoire (ou 'quit') : ")

    if rep == "quit":
        print("Fin du programme")
        break

    os.system("cp -r . " + rep)
    print("Copie vers", rep, "terminée")
