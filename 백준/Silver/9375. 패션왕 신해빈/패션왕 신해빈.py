import sys
input = sys.stdin.readline
T = int(input())
for _ in range(T):
  dic = {}
  n = int(input())
  for i in range(n):
    clothes, kind = input().rstrip().split()
    if kind in dic:
      dic[kind] += 1
    else:
      dic[kind] = 1
  ans = 1
  kind_cnt = list(dic.values())
  for i in range(len(kind_cnt)):
    ans *= (kind_cnt[i]+1)
  print(ans-1)