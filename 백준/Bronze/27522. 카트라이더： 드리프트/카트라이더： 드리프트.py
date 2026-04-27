import sys
record = []
red = 0
blue = 0
score = {1:10,2:8,3:6,4:5,5:4,6:3,7:2,8:1}

for _ in range(8):
  time, team = sys.stdin.readline().rstrip().split()
  M, SS, sss = map(int,time.rstrip().split(':'))
  record.append((M,SS,sss,team))
record.sort(key=lambda x : (x[0],x[1],x[2]))

for i in range(len(record)):
  if record[i][3] == 'R':
    red += score[i+1]
  else:
    blue += score[i+1]

if red > blue:
  print('Red')
else:
  print('Blue')