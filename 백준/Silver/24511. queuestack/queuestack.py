import sys
from collections import deque
input = sys.stdin.readline


N = int(input())
sequence_A = list(map(int, input().split())) ## queue == 0, stack == 1
sequence_B = list(map(int, input().split())) ## i번 자료구조에 들어있는 원소
M = int(input())                             ## 삽입할 수열의 길이
sequence_C = list(map(int, input().split())) ## 삽입할 수열


queue = deque([])
for i in range(N):
  if sequence_A[i] == 0:
    queue.appendleft(sequence_B[i])
else:
  if queue == []:
    print(*sequence_C)
    sys.exit()

for i in range(M):
  queue.append(sequence_C[i])
  print(queue.popleft(), end = " ")