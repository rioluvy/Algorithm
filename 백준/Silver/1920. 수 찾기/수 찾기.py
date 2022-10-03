import sys
N = int(sys.stdin.readline())
num_N = set(map(int,sys.stdin.readline().split()))
M = int(sys.stdin.readline())
num_M = list(map(int,sys.stdin.readline().split()))
for i in num_M:
  if i in num_N:
    print(1)
  else:
    print(0)

## list자료형은 삽입, 제거, 탐색, 포함 여부 확인 모두 O(n)에 해당하는 시간 복잡도
## set과 dic은 삽입, 제거, 탑색, 포함 여부 확인 모두 O(1)에 해당하는 시간 복잡도