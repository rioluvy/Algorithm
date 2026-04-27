#include <algorithm>
#include <cmath>
#include <iostream>
#include <tuple>
#include <vector>
#define endl "\n"
#define MAX 1000000000
using namespace std;
vector<int> seq;
vector<int> Segtree;
vector<tuple<int, int, int>> info;

int make_segment_tree(int node, int start, int end) {
  if (start == end)
    return Segtree[node] = seq[start];
  int mid, left, right;
  mid = (start + end) / 2;
  left = make_segment_tree(node * 2, start, mid);
  right = make_segment_tree(node * 2 + 1, mid + 1, end);
  return Segtree[node] = min(left, right);
}
int update_tree(int node, int start, int end, int idx, int change) {
  if (idx < start || idx > end)
    return Segtree[node];
  if (start == end)
    return Segtree[node] = change;
  else {
    int mid = (start + end) / 2;
    int left = update_tree(node * 2, start, mid, idx, change);
    int right = update_tree(node * 2 + 1, mid + 1, end, idx, change);
    return Segtree[node] = min(left, right);
  }
}
int query(int node, int start, int end, int left, int right) {
  if (start > right || end < left)
    return MAX;
  if (start >= left && end <= right)
    return Segtree[node];
  int mid = (start + end) / 2;
  int left_child = query(node * 2, start, mid, left, right);
  int right_child = query(node * 2 + 1, mid + 1, end, left, right);
  return min(left_child, right_child);
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n, m, num, com, a, b;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> num;
    seq.push_back(num);
  }
  cin >> m;
  for (int i = 0; i < m; i++) {
    cin >> com >> a >> b;
    info.push_back({com, a, b});
  }

  int height, tree_size;
  height = (int)ceil(log2(n));
  tree_size = (1 << (height + 1));
  Segtree.resize(tree_size, MAX);
  make_segment_tree(1, 0, n - 1);

  for (int i = 0; i < m; i++) {
    if (get<0>(info[i]) == 1) {
      update_tree(1, 0, n - 1, get<1>(info[i]) - 1, get<2>(info[i]));
    } else {
      cout << query(1, 0, n - 1, get<1>(info[i]) - 1, get<2>(info[i]) - 1)
           << endl;
    }
  }
}