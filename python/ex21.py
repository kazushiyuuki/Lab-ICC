x = float(input())
v1 = float(input())
v2 = float(input())
a = float(input())
if x >= a:
    custo = a * v1
else:
    custo = a * v2
print(f'{custo:.2f}')