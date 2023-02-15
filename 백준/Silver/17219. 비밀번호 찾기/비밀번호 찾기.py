import sys
input = sys.stdin.readline
def Sol():
  N, M = map(int,input().split())
  site = {}
  for i in range(N):
    a, b = input().split()
    site[a] = b
  for _ in range(M):
    want_to_know = input().rstrip()
    print(site[want_to_know])

if __name__ == "__main__":
  Sol()