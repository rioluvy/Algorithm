from itertools import combinations

total = []
diff = []
num_of_spread, M = input().split()
num_of_cards = list(map(int,input().split()))
for i in combinations(num_of_cards,3):
  total.append(sum(i))
for j in total:
    if int(M)-j >= 0:
      diff.append(j)
print(max(diff))