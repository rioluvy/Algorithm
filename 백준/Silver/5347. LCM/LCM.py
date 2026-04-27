import sys
input = sys.stdin.readline
t = int(input())

def GCD(a,b):
    while b:
        a,b = b, a%b
    return a
for _ in range(t):
    a,b = map(int,input().split())
    print(a*b//GCD(a,b))