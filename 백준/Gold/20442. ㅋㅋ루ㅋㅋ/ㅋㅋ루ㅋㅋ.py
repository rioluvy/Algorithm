import sys
input = sys.stdin.readline
def Sol():
  jammin = list(input().rstrip())
  r_count = 0
  k_count = []
  r_pos = []
  total_k = 0

  for i in range(len(jammin)):
    if jammin[i] == 'R':
      r_count += 1
      r_pos.append(i)
      k_count.append(i-r_count + 1)
    else:
      total_k += 1

  if r_count == 0:
    print(0)
    sys.exit()


  max_zzfzz = 0
  i, j = 0, -1
  left = r_pos[i]
  right = r_pos[j]
  while left <= right:
    left_k = k_count[i]
    right_k = total_k - k_count[j]
    max_zzfzz = max(max_zzfzz, min(left_k, right_k)*2 + r_count)
    if left_k > right_k:
      j -= 1
      r_count -= 1
    elif left_k < right_k:
      i += 1
      r_count -= 1
    else:
      i += 1
      j -= 1
      r_count -= 2
    try:
      left = r_pos[i]
      right = r_pos[j]
    except:
      break
  print(max_zzfzz)

if __name__ == "__main__":
  Sol()