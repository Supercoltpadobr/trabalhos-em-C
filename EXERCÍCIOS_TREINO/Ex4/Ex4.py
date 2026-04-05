from math import sqrt


P = int(input("DIGITE N : "))

i = 2

while i <= sqrt(P):

    if P%i == 0:

        print("NO PRIMO )=")
        exit()
    
    i += 1

print("EL PRIMO!")