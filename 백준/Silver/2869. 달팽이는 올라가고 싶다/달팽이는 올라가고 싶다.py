import sys
A, B, V = map(int,sys.stdin.readline().split())
up_meter = 0
day = (V-B)/(A-B)
if day != int(day):
  day += 1
print(int(day))