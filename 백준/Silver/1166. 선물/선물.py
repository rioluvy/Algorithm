import sys
input = sys.stdin.readline
n,l,w,h = map(int,input().split())
start = 0; end = max(l,w,h)
for _ in range(10000):
    mid = (start + end)/2
    if (l//mid) * (w//mid) * (h//mid) >= n:
        start = mid
    else:
        end = mid
print(mid)