import sys
n, k = map(int,sys.stdin.readline().split())

def fac(a):
  total =1
  for i in range(a,0,-1):
    total *= i
  return total

print(int(fac(n)/(fac(k)*fac(n-k))))