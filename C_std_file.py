from array import *
from math import *

i = N = int(0)
std = valori = num = somma = media = float(0)

dati = array('f')

f = open("pianoinclinato.dat", "r")
for line in f:
    valori = [float(valori) for valori in line.split()]
    dati.extend(valori)
    N += 1
f.close

print(dati,"\n")



N = int(input("Quanti numeri vuoi inserire?: "))
print("Inseriscili:")

for i in range(N):
    num = float(input(""))
    dati.append(num)
    somma += dati[i]
    
media = somma/N

i = somma = 0
for i in range(N):
    somma += pow((media - dati[i]), 2)

std = sqrt(somma/(N-1))

print("La media dei numeri è: ", media)
print("La deviazione standard è: ", std)