n = int(input())
cont = 0
soma = 0
while cont < n:
    num = int(input())
    if cont == 0:
        maior = num
        menor = num
    elif num > maior:
        maior = num
    elif num < menor:
        menor = num
    soma += num
    cont += 1
print(maior)
print(menor)
print(soma)