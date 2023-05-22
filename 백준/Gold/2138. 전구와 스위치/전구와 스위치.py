import sys
input = sys.stdin.readline
n = int(input())
bulb = list(map(int,input().rstrip()))
want = list(map(int,input().rstrip()))
cnt = 0

def flip_bits(num):
    flipped_num = num ^ 1
    return flipped_num

first_on = []
for i in range(len(bulb)):
  first_on.append(bulb[i])
first_on[0] = flip_bits(first_on[0]); first_on[1] = flip_bits(first_on[1])

def turn(bulb):
  global cnt
  for i in range(1,n):
    if bulb[i-1] != want[i-1]:
      for j in range(i-1,i+2):
        try:
          bulb[j] = flip_bits(bulb[j])
        except:
          pass
      cnt += 1
    if bulb == want:
      print(cnt)
      sys.exit()

turn(bulb)
cnt = 1
turn(first_on)
print(-1)