#include<iostream>
#include<vector>
#include<stack>
#define lint long long
using namespace std;

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> height(n,0);
  for(auto& v:height) cin >> v;

  lint ans = 0;
  stack<int> building;
  building.push(height[0]);
  for(int i = 1; i < n; i++){
    int nxt = height[i];
    while(!building.empty() && building.top() <= nxt) building.pop();
    ans += building.size();
    building.push(nxt);
  }
  cout << ans;
}