import sys
from collections import Counter
input = sys.stdin.readline
n, m = map(int, input().split())
num = list(map(int, input().split()))
sum_list_divided = [0]
answer = 0
## value Combination 2
def com(value):
  if value == 0 or value == 1:
    return 0
  else:
    total = value*(value-1) // 2
    return total

## 합 배열을 m으로 나눈 나머지 배열 생성
for i in range(n):
  remainder = (sum_list_divided[-1] + num[i]) % m
  sum_list_divided.append(remainder)
  if remainder == 0:
    answer += 1
sum_list_divided.remove(0)

## 나머지 배열에서 개수 세기
dic = Counter(sum_list_divided)
for key in dic:
  answer += com(dic[key])
print(answer)