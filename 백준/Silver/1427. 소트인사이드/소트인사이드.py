import sys
import heapq
input = sys.stdin.readline
def Sol():
  num_sort = []
  heap = []
  num = input().rstrip()
  for i in range(len(num)):
    temp = int(num[i])
    heapq.heappush(heap,-temp)


  for i in range(len(num)):
    num_sort.append(-heapq.heappop(heap))
  print(*num_sort, sep = "")

if __name__ == "__main__":
  Sol()