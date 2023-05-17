from math import factorial
n,m = map(int,input().split())
tar = n-m
r = factorial(m)
total = 1
while n != tar:
  total *= n
  n -= 1
print(total // r)