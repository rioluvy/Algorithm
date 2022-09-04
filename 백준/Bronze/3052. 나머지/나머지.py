remainder = []
result=[]
for _ in range(10):
  num = int(input())
  remainder.append(num%42)
for i in remainder:
  if i not in result:
    result.append(i)
print(len(result))