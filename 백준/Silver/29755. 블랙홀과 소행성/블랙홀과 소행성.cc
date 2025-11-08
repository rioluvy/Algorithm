#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<stack>
#include<cstring>
#define pii pair<int,int>
#define piii pair<int,pair<int,int>>
using namespace std;

int n, m, b[200001], a, w, ans;

int bin(int a, int w){
  int left = 0, right = n-1;
  int p = 2147483647;
  while(left <= right){
    int mid = (left + right)/2;
    p = min(p,w*abs(b[mid]-a));

    if(b[mid] < a) left = mid+1;
    else right = mid-1;
  }
  return p;
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> m;
  for(int i = 0; i < n; i++){
    cin >> b[i];
  }
  sort(b,b+n);
  for(int i = 0; i < m; i++){
    cin >> a >> w;
    ans = max(ans,bin(a,w));
  }
  cout << ans;
}