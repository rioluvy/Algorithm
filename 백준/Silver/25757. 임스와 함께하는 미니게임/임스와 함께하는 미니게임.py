import sys
input = sys.stdin.readline
n = input().rstrip().split()
if n[1] == 'Y':
    num = 2
elif n[1] == 'F':
    num = 3
else:
    num = 4

people = []
for i in range(int(n[0])):
    p = input().rstrip()
    people.append(p)
people_num = len(set(people))

print(people_num//(num-1)) 