import sys
input = sys.stdin.readline
test_case = 0
while True:
  N = int(input())
  if N == 0:
    sys.exit()
  manito = {}
  cycle = 0
  for _ in range(N):
    person_1, person_2 = input().split()
    manito[person_1] = person_2
  while manito != {}:
    memorize = list(manito.keys())[0]
    result = manito[memorize]
    while memorize != result:
      remove_p = result
      result = manito[result]
      manito.pop(remove_p)
    manito.pop(memorize)
    cycle += 1
  test_case += 1
  print(test_case, cycle)