import sys
test_case = int(sys.stdin.readline())
for _ in range(test_case):
  h,w,n = map(int,sys.stdin.readline().split())
  if n % h != 0:
    a = n // h + 1 #호텔 호수
    b = n % h      #호텔 층수
  else:
    a = n // h
    b = h
  if a<10:
    print(b,0,a, sep="")
  else:
    print(b,a,sep="")