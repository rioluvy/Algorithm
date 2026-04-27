import sys
input = sys.stdin.readline
d1, d2, x = map(int,input().split())
if d1 > d2:
  tmp = (d2 * x)/((100-x)*d1)
  m1 = d1 * tmp
  v1 = tmp
  m2 = d2
  v2 = 1
else:
  tmp = (d1 * x)/((100-x)*d2)
  m2 = d2 * tmp
  v2 = tmp
  m1 = d1
  v1 = 1
print((m1+m2)/(v1+v2))