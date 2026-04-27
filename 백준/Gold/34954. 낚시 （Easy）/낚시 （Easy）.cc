#include <bits/stdc++.h>
#define ll long long
using namespace std;

int n, m, tmp;
ll ans;
priority_queue<int, vector<int>, greater<int>> b, f;

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);cout.tie(0);

  cin >> n >> m;
  for(int i = 0; i < n; i++){
    cin >> tmp;
    b.push(tmp);
  }
  for(int i = 0; i < m; i++){
    cin >> tmp;
    f.push(tmp);
  }

  priority_queue<int, vector<int>, greater<int>> s;

  for(int i = 0; i < m; i++){
    if(b.empty()){
      if(s.top() < f.top()){
        s.pop();
        s.push(f.top());
        f.pop();
      }
      else f.pop();
      continue;
    }
    if(b.top() < f.top()){
      b.pop();
      s.push(f.top());
      f.pop();
    }
    else if(!s.empty() && (s.top() < f.top())){
      s.pop();
      s.push(f.top());
      f.pop();
    }
    else f.pop();
  }

  while(!s.empty()){
    ans += s.top();
    s.pop();
  }
  cout << ans;
}