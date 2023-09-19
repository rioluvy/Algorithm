import sys
input = sys.stdin.readline
H1, W1 = map(int,input().split())
standard = [list(input().rstrip()) for _ in range(H1)]
H2, W2 = map(int,input().split())
make = [list(input().rstrip()) for _ in range(H2)]

coin_1 = []
for i in range(H1):
    for j in range(W1):
        if standard[i][j] != '.':
            coin_1.append([i,j])

coin_2 = []
for i in range(H2):
    for j in range(W2):
        if make[i][j] != '.':
            coin_2.append([i,j])
            
if not coin_1:
    print(0)
    sys.exit()

ans = int(1e9)
for i in range(len(coin_1)):
    x1,y1 = coin_1[i]
    for j in range(len(coin_2)):
        x2,y2 = coin_2[j]
        diff_x = x2-x1; diff_y = y2-y1
        cnt = 0
        for k in range(H1):
            for l in range(W1):
                if standard[k][l] == '.':
                    continue
                if 0 <= k + diff_x < H2 and 0 <= l + diff_y < W2:
                    if make[k + diff_x][l + diff_y] == 'O':
                        cnt += 1
        move = len(coin_1) - cnt         
        if move < ans:
            ans = move
print(ans)