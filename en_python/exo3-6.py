def C(n, k):
    if k == 0 or k == n:
        return 1
    return C(n-1, k) + C(n-1, k-1)

n = int(input("n = "))
k = int(input("k = "))

print("Resultat =", a(n, k))
