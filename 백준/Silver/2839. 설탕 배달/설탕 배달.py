import sys
bags = int(sys.stdin.readline())
bag1 = 5
bag2 = 3
count = 0
while True:
  if bags%bag1 == 0:
    count += bags//bag1 
    print(count)
    break
  else:
    bags -= 3
    count += 1
    if bags<0:
      print(-1)
      break