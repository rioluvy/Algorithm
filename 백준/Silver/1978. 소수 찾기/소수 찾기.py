import sys
N = int(sys.stdin.readline())
S = list(map(int,sys.stdin.readline().split()))
find_prime = 0
for i in S:
  count = 0
  for j in range(1,i):
    if i%j == 0:
      count += 1
  if count == 1:
    find_prime += 1
  count = 0
print(find_prime)