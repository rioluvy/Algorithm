#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
#include <stack>
#include <deque>
#define endl "\n"

using namespace std;
int main(){
  ios::sync_with_stdio(0); cin.tie(0);
  int n,tmp,m;
  cin >> n;
  vector<int> A(n);
  vector<int> C;
  queue<int> queue;
  for(int i = 0; i < n; i++){
    cin >> A[i];
  }
  for(int i = 0; i < n; i++){
    cin >> tmp;
    if(A[i] == 0) C.push_back(tmp);
  }
  for(int i = C.size()-1; i >= 0; i--){
    queue.push(C[i]);
  }
  cin >> m;
  for(int i = 0; i < m; i++){
    cin >> tmp;
    queue.push(tmp);
  }
  for(int i = 0; i < m; i++){
    cout << queue.front() << ' ';
    queue.pop();
  }

}