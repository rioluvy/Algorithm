import sys
n = int(sys.stdin.readline())
num_list = [0] * 10001
index_list = [0] * 10001
for _ in range(n):
  num = int(sys.stdin.readline())
  num_list[num] = num
  index_list[num] += 1
for j in range(10001):
  if num_list[j] != 0:
    for i in range(index_list[j]):
      print(num_list[j])