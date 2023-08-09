import sys
input = sys.stdin.readline
n = int(input())
score = []
for i in range(n):
    score.append(float(format(float(input()), ".3f")))
score.sort()
for i in range(7):
    print(format(score[i],".3f"))