A, B = input().split()
right_numA = list(A)
right_numB = list(B)
wrong_numA = []
wrong_numB = []
for i in range(len(right_numA)-1,-1,-1):
  wrong_numA.append(right_numA[i])
for j in range(len(right_numB)-1,-1,-1):
  wrong_numB.append(right_numB[j])
wrong_numAA=int(''.join(wrong_numA))
wrong_numBB=int(''.join(wrong_numB))
if wrong_numAA>wrong_numBB:
  print(wrong_numAA)
else:
  print(wrong_numBB)
  
# 파이썬을 사용하면 모듈 사용에 익숙해지자  
# A, B = input().split()
# print(max(int(A[::-1]), int(B[::-1])))
