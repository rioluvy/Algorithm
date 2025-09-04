#include<iostream>
#include<vector>
#include<algorithm>
#define pii pair<int,int>
using namespace std;

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  vector<pii> arr(n);
  for(auto& v : arr) cin >> v.first >> v.second;
  auto compare = [&](const pii& a, pii& b){
    if(a.second == b.second) return a.first < b.first;
    return a.second < b.second;
  };
  sort(arr.begin(),arr.end(),compare);
  
  int end = 0;
  int cnt = 0;
  for(auto& v : arr){
    if(end <= v.first){
      cnt++;
      end = v.second;
    }
  }
  cout << cnt;
}