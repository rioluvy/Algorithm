import sys
import string
l = sys.stdin.readline()
word = sys.stdin.readline()
lowerletter = list(string.ascii_lowercase)
h=0

for i in range(len(word)):
  if word[i] in lowerletter:
    a = lowerletter.index(word[i])+1
    h += a * (31 ** i)
H = h % 1234567891
print(H)