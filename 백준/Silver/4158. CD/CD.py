import sys
input = sys.stdin.readline
while True:
    n, m = map(int,input().split())
    if n == 0 and m == 0:
        break
    p1 = []; p2 = []
    for _ in range(n):
        p1.append(int(input()))
    for _ in range(m):
        p2.append(int(input()))
    p1 = set(p1); p2 = set(p2)
    print(len(p1 & p2))