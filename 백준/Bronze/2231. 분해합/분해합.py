N = input()
candidate = []
for i in range(1,int(N)+1):
  M = i + sum(list(map(int, str(i))))
  if M == int(N):
    candidate.append(M)
    break
if candidate == []:
  print(0)
else:
  print(i)