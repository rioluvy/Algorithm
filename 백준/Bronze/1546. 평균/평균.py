N=int(input())
score=list(map(int,input().split()))
max_score=max(score)
fake_score=[]
for i in score:
    fake_score.append(i/max_score*100)
total=sum(fake_score)
print(total/N)
