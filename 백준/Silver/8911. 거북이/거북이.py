import sys
input = sys.stdin.readline
t = int(input())
for _ in range(t):
    footprint = [(0,0)]
    x = 0; y = 0
    direction = 1     ##[1,2,3,4] 북,동,남,서
    command = list(input().rstrip())
    for i in command:
        if i == 'F':
            if direction % 4 == 1:
                y += 1
            elif direction % 4 == 2:
                x += 1
            elif direction % 4 == 3:
                y -= 1
            else:
                x -= 1
            footprint.append((x,y))
        elif i == 'B':
            if direction % 4 == 1:
                y -= 1
            elif direction % 4 == 2:
                x -= 1
            elif direction % 4 == 3:
                y += 1
            else:
                x += 1
            footprint.append((x,y))
        elif i == 'R':
            direction += 1
        else:
            direction -= 1
    footprint.sort()
    max_x = footprint[-1][0]
    min_x = footprint[0][0]
    footprint.sort(key = lambda x : x[1])
    max_y = footprint[-1][1]
    min_y = footprint[0][1]
    print((max_x-min_x)*(max_y-min_y))