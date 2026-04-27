a=[]
for i in range(3):
    s=int(input())
    a.append(s)
result=a[0]*a[1]*a[2]
result_list=list(map(int,list(str(result))))
for j in range(10):
    count_num=result_list.count(j)
    print(count_num)