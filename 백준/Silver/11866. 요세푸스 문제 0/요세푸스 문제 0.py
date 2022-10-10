from collections import deque
N, K = map(int,input().split())
permutation = deque([])
for i in range(1,N+1):
  permutation.append(i)
print("<", end = "")
while permutation:
  for _ in range(K-1):
    permutation.append(permutation[0])
    permutation.popleft()
  print(permutation.popleft(), end ="")
  if permutation:
    print(", ", end = "")
  else:
    break
print(">")