import sys
input = sys.stdin.readline
N = int(input())
word = []
start_l = ""
end_l = ""
for i in range(N):
    tmp = input().rstrip()
    word.append(tmp)
    if tmp == '?':
        pos = i
if N == 1:
    M = int(input())
    print(input().rstrip())
    sys.exit()
if pos == 0:
    end_l = word[pos+1][0]
elif pos == N-1:
    start_l = word[pos-1][-1]
else:
    start_l = word[pos-1][-1]
    end_l = word[pos+1][0]

M = int(input())
check_word = []
for i in range(M):
    tmp = input().rstrip()
    if tmp in word:
        continue
    check_word.append(tmp)

for i in check_word:
    if start_l != "" and end_l != "" and i[0] == start_l and i[-1] == end_l:
        print(i)
        break
    elif start_l == "" and end_l != "" and i[-1] == end_l:
        print(i)
        break
    elif end_l == "" and start_l != "" and i[0] == start_l:
        print(i)
        break
