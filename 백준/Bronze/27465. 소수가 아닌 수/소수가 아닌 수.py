import sys
input = sys.stdin.readline
N = int(input())
def prime(num):
  for i in range(2, int(num**(1/2))):
    if num % i == 0:
      return False
  else:
    return True
for i in range(N,10**9+1):
  if not prime(i):
    print(i)
    sys.exit()