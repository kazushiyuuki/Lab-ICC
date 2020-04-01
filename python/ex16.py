def mult(x, y):
  mult = 0
  while(y>0):
    mult += x
    y -= 1
  return mult
def pot(a, b):
  pot = 1
  while(b>0):
    pot = mult(pot, a)
    b -= 1
  return pot
a = int(input())
b = int(input())
print(pot(a,b))