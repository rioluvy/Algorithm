import sys
input = sys.stdin.readline
T = int(input())
memoization_0 = {2: 1, 3: 1}
memoization_1 = {2: 1, 3: 2}

def fibonacci_0(n):
  if n in memoization_0:
    return memoization_0[n]
  else:
    temp = fibonacci_0(n-1) + fibonacci_0(n-2)
    memoization_0[n] = temp
    return temp

def fibonacci_1(n):
  if n in memoization_1:
    return memoization_1[n]
  else:
    temp = fibonacci_1(n-1) + fibonacci_1(n-2)
    memoization_1[n] = temp
    return temp

for _ in range(T):
  N = int(input())
  if N == 0:
    print(1, 0)
  elif N == 1:
    print(0, 1)
  else:
    print(fibonacci_0(N), fibonacci_1(N))
