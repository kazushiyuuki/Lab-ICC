a = float(input())
b = float(input())
c = float(input())

if c>a+b or a>b+c or b>c+a:
    print("INVALIDO")
else: 
    if a!=b and b!=c and a!=c:
        print("ESCALENO")
    elif a==b==c:
        print("EQUILATERO")
    elif a==b or b==c or c==a:
        print ("ISOSCELES")
     


