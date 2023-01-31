import sys
input = sys.stdin.readline

def Sol():
  N = int(input())
  dic = {}
  for i in range(N):
    dic[i] = int(input())
  sort_num = sorted(dic.values())

  sort_dic = {}
  for i in range(len(sort_num)):
    sort_dic[i] = sort_num[i]

  sort_dic = dict(map(reversed, sort_dic.items())) ## 정렬 후 딕셔너리 뒤집기
  max = 0
  j = 0
  for i in dic.values():
    if max < j - sort_dic[i]:
      max = j - sort_dic[i]
    j += 1
  print(max + 1)
     

if __name__ == "__main__":
  Sol()