import sys
from collections import deque
input = sys.stdin.readline

t = int(input())
while t:
    t-=1
    n = int(input())
    arr = input().split()
    dq = deque(arr[0])
    for i in range(1,n):
        if arr[i] <= dq[0]:
            dq.appendleft(arr[i])
        else:
            dq.append(arr[i])
    print(''.join(dq))