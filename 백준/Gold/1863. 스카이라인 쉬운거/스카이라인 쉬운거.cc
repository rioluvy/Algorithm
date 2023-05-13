#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
#include <stack>
#include <deque>
#include <set>
#define endl "\n"

using namespace std;
int main(){
  ios::sync_with_stdio(0); cin.tie(0);
  int n,x,y,cnt = 0;
  cin >> n;
  stack<int> stack;
  set<int> set;
  for(int i = 0; i < n; i++){
    cin >> x >> y;
    while(!stack.empty() && y < stack.top()){
      int tmp = stack.top();
      stack.pop();
      cnt++;
      if(!stack.empty() && y < stack.top()){
        int tmpp = stack.top();
        if(tmp == tmpp) cnt--;
      }
    }
    stack.push(y);
  }
  int stack_size = stack.size();
  for(int i = 0; i < stack_size; i++){
    if(stack.top() != 0){
      set.insert(stack.top());
    }
    stack.pop();
  }
  int ans = cnt + set.size();
  cout << ans;
}