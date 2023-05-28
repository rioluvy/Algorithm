import sys
input = sys.stdin.readline
N = int(input())
tree = {}
for _ in range(N):
  node, left, right = input().rstrip().split()
  tree[node] = (left, right)

traverse = []
def preorder(node):
  if node == '.':
    return
  traverse.append(node)
  for i in range(2):
    preorder(tree[node][i])
preorder('A')
print(*traverse,sep="")

traverse = []
def inorder(node):
  if node == '.':
    return
  inorder(tree[node][0])
  traverse.append(node)
  inorder(tree[node][1])
inorder('A')
print(*traverse,sep="")

traverse = []
def postorder(node):
  if node == '.':
    return
  postorder(tree[node][0])
  postorder(tree[node][1])
  traverse.append(node)
postorder('A')
print(*traverse,sep="")