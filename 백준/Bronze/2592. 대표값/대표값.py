import sys
meungzi = []
for i in range(10):
  a = int(sys.stdin.readline())
  meungzi.append(a)
if sum(meungzi)%10==0:
  print(round(sum(meungzi)/10))
else:
  print(sum(meungzi)/10)

max = 0
meungzizi = list(set(meungzi))
for i in meungzizi:
  count = meungzi.count(i)
  if count > max:
    max = count
    num = i
print(num)