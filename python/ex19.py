idade = int(input())
if idade < 16:
    print('DISPENSADO')
elif idade < 18:
    print('FACULTATIVO')
elif idade < 70:
    print('OBRIGATORIO')
else:
    print('DISPENSADO')
