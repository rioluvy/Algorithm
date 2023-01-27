import sys
input = sys.stdin.readline
N = int(input())
def Sol():
  for h in range(10000,100000):
    w = N - h
    h = str(h); w = str(w)
    if len(w) == 5 and h[2] == h[3] == w[3] and h[4] == w[1] and len(set(w+h)) == 7:
      if N < 100000:
        print("  ", h, sep = "")
        print("+ ", w, sep = "")
        print("-------")
        print("  ", N, sep= "")
        sys.exit()
      else:
        print("  ", h, sep = "")
        print("+ ", w, sep = "")
        print("-------")
        print(" ", N, sep= "")
        sys.exit()
  print("No Answer")

if __name__ == "__main__":
  Sol()