import sys
input = sys.stdin.readline
cal = [31,28,31,30,31,30,31,31,30,31,30,31]
y,m,d = map(int,input().split())
Y,M,D = map(int,input().split())
if (Y-y == 1000 and M >= m and D >= d) or Y-y > 1000:
    print("gg")
    sys.exit()
def f(year,month,day):
    if (year % 4 == 0 and year % 100 != 0) or (year % 400 == 0):
        if month > 2:
            day += 1
        a_year = 366
    else:
        a_year = 365
    for i in range(month-1):
        day += cal[i]
    return (day,a_year)

tmp = f(y,m,d)
tmp2 = f(Y,M,D)
now = tmp[0]
camp = tmp2[0]

cnt = tmp[1]-now + camp
if Y-y >= 1:
    for i in range(y+1,Y):
        if (i % 4 == 0 and i % 100 != 0) or (i % 400 == 0):
            cnt += 366
        else:
            cnt += 365
else:
    cnt = tmp2[0] - tmp[0]
print("D-", cnt, sep = "")