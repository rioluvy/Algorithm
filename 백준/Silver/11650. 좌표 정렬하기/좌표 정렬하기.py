import sys
num_of_dot = int(sys.stdin.readline())
x_y = [list(map(int, sys.stdin.readline().rstrip().split())) for _ in range(num_of_dot)]
x_y.sort(key=lambda x:(x[0],x[1]))
result = []
for i in x_y:
  for j in i:
    result.append(j)
  print(result[0], result[1])
  result =[]