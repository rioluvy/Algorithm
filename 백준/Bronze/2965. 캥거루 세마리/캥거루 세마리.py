a, b, c = map(int, input().split())
tmp1 = b-a
tmp2 = c-b
if tmp1 > tmp2:
    print(tmp1-1)
else:
    print(tmp2-1)