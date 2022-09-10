while True:
  line = input()
  if line == '0 0 0':
    break
  A, B, C = line.split()
  li = [float(A),float(B),float(C)]
  li.sort(reverse=False)
  if li[0]**2+li[1]**2==li[2]**2:
    print('right')
  else:
    print('wrong')