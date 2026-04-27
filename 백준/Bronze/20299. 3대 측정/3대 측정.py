import sys
input=sys.stdin.readline
n,k,l = map(int,input().split())

team = []

for _ in range(n):

    tmp = list(map(int,input().split()))

    if sum(tmp) < k:

        continue

    for I in tmp:

        if I < l:

            break

    else:

        team.append(tmp)

print(len(team))

for i in team:

    print(*i,end = " ")