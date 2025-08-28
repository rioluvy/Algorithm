#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
#include<tuple>
#define lint long long
using namespace std;

lint n, h, ans = -1;
vector<tuple<lint,lint,lint>> cows;

int main(){
  cin >> n >> h;
  for(int i = 0; i < n; i++){
    lint a, b, c;
    cin >> a >> b >> c;
    cows.push_back({b+c,a,b});
  }
  sort(cows.rbegin(),cows.rend());

  for(int i = 0; i < (1<<n); i++){
    lint height = 0;
    lint capacity = LLONG_MAX;
    bool flag = true;
    for(int j = 0; j < n; j++){
      if(!(i&(1<<j))) continue;
      auto [tmp, cowH, cowW] = cows[j];
      if(capacity < cowW){
        flag = false;
        break;
      }
      height += cowH;
      capacity = min(capacity-cowW,tmp-cowW);
    }
    if(!flag || (height < h)) continue;
    ans = max(ans,capacity);
  }
  if(ans == -1) cout << "Mark is too tall";
  else cout << ans;
}