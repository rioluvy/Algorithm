import string
import sys
upper_letter=input().upper()
a=[]
b=[]
c=[]
ascii_upper=list(string.ascii_uppercase)
for i in ascii_upper:
    upper_letter.count(i)
    a.append(upper_letter.count(i))

max_num=max(a)

for j in a:
    if j==max_num:
        b.append(j)
        if len(b)>=2:
            print("?")
            sys.exit()
    elif j != max_num:
        c.append(j)
print(ascii_upper[a.index(max_num)])