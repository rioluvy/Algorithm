import sys
from collections import Counter

n = sys.stdin.readline()
card = sorted(map(int,sys.stdin.readline().split()))
m = sys.stdin.readline()
card_num = list(map(int,sys.stdin.readline().split()))

count = Counter(card)

for i in range(len(card_num)):
  if card_num[i] in count.keys():
    print(count.get(card_num[i]), end = " ")
  else:
    print(0, end = " ")