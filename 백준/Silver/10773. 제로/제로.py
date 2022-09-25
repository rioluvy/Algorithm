
K = int(input())
total_list = [0]
for _ in range(K):
  num = int(input())
  if num == 0:
    total_list.pop()
  else:
    total_list.append(num)
print(sum(total_list))
