import sys
N = int(sys.stdin.readline())
x_y =  [ list(map(int,sys.stdin.readline().split())) for _ in range(N) ]
x_y.sort(key = lambda x: (x[1],x[0]))
result = []
for i in x_y:
    for  j in i:
        result.append(j)
    print(result[0],result[1])
    result = []
