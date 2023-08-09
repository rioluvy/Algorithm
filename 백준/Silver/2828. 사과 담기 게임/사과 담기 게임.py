import sys
input = sys.stdin.readline
n,m = map(int,input().split())
cnt = int(input())
pos = [1,m]
dist = 0
for i in range(cnt):
    apple = int(input())
    if apple > pos[1]:
        diff = apple-pos[1]
        dist += diff
        pos[0] += diff; pos[1] += diff
    elif apple < pos[0]:
        diff = pos[0]-apple
        dist += diff
        pos[0] -= diff; pos[1] -= diff
print(dist)