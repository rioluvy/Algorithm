import sys
input = sys.stdin.readline
A, B, C = map(int,input().split())
ans = 1
while B > 0:
  if B % 2:
    ans *= A
    ans %= C
  A *= A
  A %= C
  B //= 2
print(ans)