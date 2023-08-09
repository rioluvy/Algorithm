import sys
input = sys.stdin.readline
n = int(input())
tip = []
for i in range(n):
    tip.append(int(input()))
tip.sort(reverse=True)

ans = 0
for i in range(len(tip)):
    total = tip[i]-i
    if total > 0:
        ans += total
print(ans)