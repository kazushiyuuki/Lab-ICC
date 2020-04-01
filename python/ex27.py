n = int(input())
soma = 0
while n!= 0:
    dig = n % 10
    soma += dig
    n = n // 10
print(soma)
