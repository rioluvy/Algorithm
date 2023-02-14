import sys
from collections import deque
input = sys.stdin.readline
M = int(input())
N = int(input())
min_prime = deque([])
total = 0
def prime(k):
    for i in range(2,int(k**(0.5)+1)):
        if k%i == 0:
            return False
    else:
        return True
for i in range(M,N+1):
    if i == 1:
        continue
    if prime(i):
        total += i
        min_prime.append(i)
if len(min_prime) == 0:
    print(-1)
    sys.exit()
print(total)
print(min_prime.popleft())