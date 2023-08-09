import sys
from math import factorial
input = sys.stdin.readline
n,k = map(int,input().split())
print(factorial(n-1)//(factorial(k-1)*factorial(n-k)))