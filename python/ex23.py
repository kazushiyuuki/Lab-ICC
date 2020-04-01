n = int(input())
cont = 0
while cont < n:
    num = int(input())
    if cont == 0:
        maior = num
    elif num > maior:
        maior = num
    cont += 1
print(maior)
    