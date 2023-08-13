import sys
input = sys.stdin.readline
n = int(input())
s = input().rstrip()
tmp = ""
for i in range(1,n):
    start = s[:i]
    end = s[-i:]
    diff = 0
    for j in range(i):
        if start[j] != end[j]:
            diff += 1
    if diff == 1:
        print("YES")
        sys.exit()
print("NO")