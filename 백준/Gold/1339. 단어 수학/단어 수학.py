import sys
input = sys.stdin.readline
n = int(input())
words = []
alpha_info = {}
for _ in range(n):
  words.append(input().rstrip())
for i in words:
  for j in range(len(i)):
    length = len(i)-j-1
    if i[j] not in alpha_info:
      alpha_info[i[j]] = 10**length
      continue
    alpha_info[i[j]] += 10**length
alpha_info = list(alpha_info.values())
alpha_info.sort(reverse=True)
ans = 0
idx = 0
for i in range(9,9-len(alpha_info),-1):
  ans += alpha_info[idx] * i
  idx += 1
print(ans)