list = list(map(int,input().split()))
prize = []
if list[0]==list[1]==list[2]:
  prize.append(10000+list[0]*1000)
elif list[0]==list[1]:
  prize.append(1000+list[0]*100)
elif list[0]==list[2]:
  prize.append(1000+list[0]*100)
elif list[1]==list[2]:
  prize.append(1000+list[1]*100)
elif list[0]!=list[1]!=list[2]:
  prize.append(max(list)*100)
print(prize[0])