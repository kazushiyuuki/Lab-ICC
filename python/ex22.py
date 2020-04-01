num = int(input())
x = num
cont = 0
while x >= 0:
    x = int(input())
    if x == num:
        cont += 1
print(cont)