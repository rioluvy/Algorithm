n,m=map(int,input().split())

num=1

for I in range(n):

    for j in range(m):

        if j==m-1:

          print(num)

        else:

          print(num,end=" ")

        num+=1