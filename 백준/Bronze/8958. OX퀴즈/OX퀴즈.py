test_case = int(input())
for _ in range(test_case):
  result = input()
  count = 0
  add = 0
  for i in result:
    if i == 'O':
      count += 1
      add += count
    else:
      count = 0
  print(add)