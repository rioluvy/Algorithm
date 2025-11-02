#include<iostream>
#include<vector>
#include<tuple>
#define pii pair<int,int>
#define piii pair<int,pair<int,int>>
using namespace std;

bool flag[100001];
int n, s, e, idx, cur;
vector<int> ans;
vector<pii> ranges;

tuple<int,int,int> intersect(int left, int right, int idx){
  for(int i = 1; i < n; i++){
    if(left < ranges[i].first && right > ranges[i].second){
      left = ranges[i].first; right = ranges[i].second;
      flag[i] = true;
    }
    else if(left > ranges[i].first && right < ranges[i].second){
      flag[i] = true;
    }
    else if(left < ranges[i].second && ranges[i].first < left){
      right = ranges[i].second;
      flag[i] = true;
    } 
    else if(right > ranges[i].first && ranges[i].second > right){
      left = ranges[i].first;
      flag[i] = true;
    }
    else break;
    idx++;
  }
  return {idx,left,right};
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
  cin >> n;
  for(int i = 0; i < n; i++){
    cin >> s >> e;
    ranges.push_back({s,e});
  }
  if(n == 1){
    cout << ranges[0].first << "\n";
    return 0;
  }
  
  auto [k,start,end] = intersect(ranges[0].first, ranges[0].second,idx);
  if(k+1 < n){
    if(abs(start-ranges[k+1].second) < abs(end-ranges[k+1].first)){
      cur = start;
    }
    else cur = end;
  }


  idx = 1;
  ans.push_back(cur);
  while(flag[idx]){
    ans.push_back(cur);
    idx++;
  }
  
  int life = 0;
  for(int i = idx; i < n; i++){
    if(ranges[i].first <= cur && cur <= ranges[i].second){
      ans.push_back(cur);
    }
    else{
      if(abs(cur-ranges[i].first) < abs(cur-ranges[i].second)){
        life += abs(cur-ranges[i].first);
        cur = ranges[i].first;
        ans.push_back(cur);
      }
      else{
        life += abs(cur-ranges[i].second);
        cur = ranges[i].second;
        ans.push_back(cur);
      }
    }
  }

  cout << life << "\n";
  for(auto v : ans) cout << v << "\n";
}