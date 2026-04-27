import sys
input = sys.stdin.readline
s = []
for i in range(5):
    num = int(input())
    if not s:
        s.append(num)
    elif num in s:
        s.remove(num)
    else:
        s.append(num)
print(s[0])