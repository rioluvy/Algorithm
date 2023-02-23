import sys
def Sol():
  input = sys.stdin.readline
  N = int(input())
  meeting = []
  for _ in range(N):
    start, end = map(int,input().split())
    meeting.append((start,end))

  meeting.sort(key=lambda x: (x[1], x[0]))
  cnt = 0
  temp = -1
  for i in meeting:
    if i[0] >= temp:
      temp = i[1]
      cnt += 1
  print(cnt)
if __name__ == "__main__":
  Sol()