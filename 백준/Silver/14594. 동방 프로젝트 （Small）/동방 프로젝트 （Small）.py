import sys
input = sys.stdin.readline
n = int(input()) ##동아리방 개수
m = int(input()) ##행동회수
room = [1]
for i in range(2,n+1):
    room.append(0)
    room.append(i)

for _ in range(m):
    x,y = map(int,input().split())
    check = False
    for i in range(len(room)):
        if room[i] == x:
            check = True
        if room[i] == y:
            check = False
        if check:
            if not room[i]:
                 room[i] = -1

cnt = 1
for i in room:
    if not i:
        cnt += 1
print(cnt)