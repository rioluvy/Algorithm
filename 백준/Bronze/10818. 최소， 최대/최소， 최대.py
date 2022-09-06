N=int(input())
num = input().split()
num_list = []
for i in num:
  num_list.append(int(i))
print(min(num_list), max(num_list))