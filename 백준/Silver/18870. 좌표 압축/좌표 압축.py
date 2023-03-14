import sys
input = sys.stdin.readline
N = int(input())
arr = list(map(int,input().split()))
tmp = []
idx = []
tmp = sorted(list(set(arr)))

for i in range(len(tmp)):
  idx.append(i)
dic = dict(zip(tmp,idx))

for i in arr:
  print(dic[i], end = " ")