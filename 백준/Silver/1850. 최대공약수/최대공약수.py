import sys
input = sys.stdin.readline
a,b = map(int,input().split())
def gcd(a,b):
  if not(a % b):
    return b
  return gcd(b,a%b)
cnt = gcd(a,b)
while cnt:
  print(1,end = "")
  cnt-=1