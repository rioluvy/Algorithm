import sys
list=[]
for _ in range(5):
    N=int(sys.stdin.readline())
    if N<= 40:
        N=40
    list.append(N)
print(int(sum(list)/5))