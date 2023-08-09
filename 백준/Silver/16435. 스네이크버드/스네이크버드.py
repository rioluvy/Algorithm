import sys
input = sys.stdin.readline
N, L = map(int,input().split())
furits = list(map(int,input().split()))
furits.sort()
for i in range(N):
    if furits[i] <= L:
        L += 1
        continue
    break
print(L)