soma = 0
num = 0
idosos = 0
maiores = 0
aux = 1
while aux > 0:
    idade = int(input())
    if idade < 0:
        aux = idade
    else:
        soma += idade
        num += 1
        if idade >= 18:
            maiores += 1
            if idade > 75:
                idosos += 1
media = soma / num
perc_idosos = (idosos / num) * 100
print(f'{media:.2f}')
print(f'{maiores}')
print(f'{perc_idosos:.2f}%')

    
