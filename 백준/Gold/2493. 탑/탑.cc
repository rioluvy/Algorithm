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
  int n, top;
  cin >> n;
  stack<pair<int,int>> stack;
  vector<int> top_num;
  for(int i = 0; i < n; i++){
    cin >> top;
    while(!stack.empty()){
      if(stack.top().second > top){
        top_num.push_back(stack.top().first + 1);
        break;
      }else stack.pop();
    }
    if(stack.empty()){
      top_num.push_back(0);
    }
    stack.push(make_pair(i,top));
  }
  for(auto loop : top_num){
    cout << loop << ' ';
  }
}