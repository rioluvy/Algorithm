import sys
input = sys.stdin.readline
n = int(input())
cnt = 0
for i in range(1,n):
    for j in range(i,n):
        k = n - i - j
        if k < j:
            break
        if k < i+j:
            cnt += 1
print(cnt)