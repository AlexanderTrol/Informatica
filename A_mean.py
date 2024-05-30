from array import *

i = N = int(0)
num = somma = media = float(0)

dati = array('f')

N = int(input("Quanti numeri vuoi inserire?: "))
print("Inseriscili:")

for i in range(N):
    num = float(input(""))
    dati.append(num)

somma = sum(dati)
media = somma/N

print("La media dei numeri è: ", media)