import sys
N = int(sys.stdin.readline())
result = [int(sys.stdin.readline().rstrip()) for _ in range(N)]
result.sort()
for i in result:
  print(i)