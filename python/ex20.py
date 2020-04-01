L = float(input())
A = float(input())
C = float(input())
M = float(input())
latas = 0
area = L * A
latas = int(area // M)
if area % M != 0:
    latas +=1
custo = latas * C
print(latas)
print(f'{custo:.2f}')