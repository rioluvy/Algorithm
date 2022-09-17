A, B = input().split()
a= int(A)
b= int(B)
while b>0:
  a, b = b, a%b
print(a)
print(int(A)*int(B)//a)