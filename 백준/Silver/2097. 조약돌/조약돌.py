import sys
input = sys.stdin.readline
n = int(input())

if n == 1 or n == 2:
    print(4)
    sys.exit()

num = int(n**(1/2))
one_len = num-1
tmp = num**2
if tmp == n:
    length = one_len*4
else:
    if n > num + tmp:
        length = one_len*4 + 4
    else:
        length = one_len*4 + 2
print(length)