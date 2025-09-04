#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
#define pii pair<int,int>
using namespace std;

struct Meeting{
  int s,e,w;
};
vector<Meeting> arr;
int n, cache[100001], ans = 0;

int trial(int idx){
  if(idx >= n) return 0;

  int& ret = cache[idx];
  if(ret != -1) return ret;

  ret = trial(idx+1);
  int target = arr[idx].e;
  int l = idx+1, h = n-1, nxt = n;
  while(l <= h){
    int mid = (l+h)/2;
    if(arr[mid].s >= target) {
      nxt = mid;
      h = mid-1;
    }
    else l = mid+1;
  }
  ret = max(ret,arr[idx].w+trial(nxt));
  return ret;
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  arr.resize(n);
  for(int i = 0; i < n; i++){
    cin >> arr[i].s >> arr[i].e >> arr[i].w;
  }
  memset(cache,-1,sizeof(cache));
  
  auto compare = [&](const Meeting& a, const Meeting& b){
    return a.s < b.s;
  };
  sort(arr.begin(),arr.begin()+n,compare);
  cout << trial(0);
}