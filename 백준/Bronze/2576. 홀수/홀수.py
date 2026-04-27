import sys
a = []
for i in range(7):
    n = int(sys.stdin.readline())
    if n%2!=0:
        a.append(n)
    else:
        pass
if a==[]:
    print(-1)
else:
    print(sum(a))
    print(min(a))