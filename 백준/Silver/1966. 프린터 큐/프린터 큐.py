import sys
Test_case = int(sys.stdin.readline())
for _ in range(Test_case):
  sequence = 0
  N, M = map(int,sys.stdin.readline().split())
  importance = list(map(int,sys.stdin.readline().split()))
  keys = [ i for i in range(len(importance))]
  key_m = keys[M]
  dic = dict(zip(keys,importance))
  sequence = 0
  while True:
    if importance[0] == max(importance):
      a = importance.pop(0)
      b = keys.pop(0)
      dic.pop(b)
      sequence += 1
      if key_m not in dic:
        print(sequence)
        break
      else:
        pass
    else:
      importance.append(importance[0])
      importance.pop(0)
      keys.append(keys[0])
      keys.pop(0)