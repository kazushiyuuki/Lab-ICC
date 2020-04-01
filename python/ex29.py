n = int(input())
i = 0
while i < n:
    if i == 0:
        maior = int(input())
        qtd_maior = 1
    else:
        temp = int(input())
        if temp > maior:
            maior = temp
            qtd_maior = 1
        elif temp == maior:
            qtd_maior += 1 
    i += 1
print(qtd_maior)