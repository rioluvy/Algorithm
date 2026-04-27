import sys
input = sys.stdin.readline
N, M = map(int,input().split())
Pokemon = {}
for i in range(N):
  Pokemon[i] = input().rstrip()
Pokemon_reverse = {v:k for k,v in Pokemon.items()}
for i in range(M):
  test = input().rstrip()
  try:
    test = int(test)-1
    print(Pokemon[test])
  except:
    print(Pokemon_reverse[test]+1)
