import sys
x = int(sys.stdin.readline())
stick = [64]
while(sum(stick)!=x):
  stick[stick.index(min(stick))] = min(stick)/2
  stick.append(min(stick))
  if sum(stick[:len(stick)-1]) >= x:
    stick.pop()
print(len(stick))