#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>
#define endl "\n"
#define pii pair<int, int>
using namespace std;

vector<int> seq;
vector<pair<int, int>> Segtree;

pair<int, int> make_Segtree(int node, int start, int end) {
  if (start == end) {
    if (seq[start] % 2)
      return Segtree[node] = {1, 0};
    else
      return Segtree[node] = {0, 1};
  }
  int mid = (start + end) / 2;
  pii left = make_Segtree(node * 2, start, mid);
  pii right = make_Segtree(node * 2 + 1, mid + 1, end);
  return Segtree[node] = {left.first + right.first, left.second + right.second};
}
void update_tree(int node, int start, int end, int idx, int change) {
	if(idx < start || idx > end) return;
	if(change){
		Segtree[node].first++;
		Segtree[node].second--;
	}else{
		Segtree[node].first--;
		Segtree[node].second++;
	}
	if(start != end){
		int mid = (start+end)/2;
		update_tree(node*2, start, mid, idx, change);
		update_tree(node*2+1, mid+1, end, idx, change);
	}
}
pair<int, int> query(int node, int start, int end, int left, int right) {
  if (start > right || end < left)
    return {0, 0};
  if (start >= left && end <= right)
    return Segtree[node];
  int mid = (start + end) / 2;
  pii left_part = query(node * 2, start, mid, left, right);
  pii right_part = query(node * 2 + 1, mid + 1, end, left, right);
  return {left_part.first + right_part.first,
          left_part.second + right_part.second};
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n, m, num, com, l, r;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> num;
    seq.push_back(num);
  }
  int height, tree_size;
  height = (int)ceil(log2(n));
  tree_size = (1 << (height + 1));
  Segtree.resize(tree_size, {0, 0});
  make_Segtree(1, 0, n - 1);

  cin >> m;
  for (int i = 0; i < m; i++) {
    cin >> com >> l >> r;
    if (com == 1) {
			if(seq[l-1]%2 == r%2) continue;
			else{
				if(seq[l-1]%2) update_tree(1, 0, n-1, l-1, 0);
				else update_tree(1, 0, n-1, l-1, 1);
				seq[l-1] += 1;
			}
    } else if (com == 2) {
      cout << query(1, 0, n - 1, l - 1, r - 1).second << endl;
    } else {
      cout << query(1, 0, n - 1, l - 1, r - 1).first << endl;
    }
  }
}