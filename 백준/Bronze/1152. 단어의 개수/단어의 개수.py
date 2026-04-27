a=input()
b=a.split(' ')
c=[]
for i in b:
    if i != '':
        c.append(i)
    else:
        pass
print(len(c))