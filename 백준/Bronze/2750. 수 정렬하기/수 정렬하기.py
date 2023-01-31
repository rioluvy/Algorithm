import sys
input = sys.stdin.readline

## 버블 소트
def Sol():
  N = int(input())
  num = [0] * N
  for i in range(N):
    num[i] = int(input())
  
  temp = 0
  i = 0
  while True:
    if i == len(num) - 1 and temp == len(num) - 1:
      break
    elif i == len(num) - 1:
      i = 0
      temp = 0

    if num[i] > num[i+1]:
      left = num[i]
      num[i] = num[i+1]
      num[i+1] = left
    else:
      temp += 1
    i += 1

  for i in range(N):
    print(num[i])

if __name__ == "__main__":
  Sol()
