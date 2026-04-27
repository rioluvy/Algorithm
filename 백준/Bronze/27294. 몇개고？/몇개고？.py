import sys
T,S = map(int,sys.stdin.readline().split())
if S == 1:
    print(280)
else:
    if T<=11 or T>16:
        print(280)
    else:
        print(320)