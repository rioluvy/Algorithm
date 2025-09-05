#include<iostream>
#include<vector>
using namespace std;

struct tmp{
  int w,v;
};

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n, k;
  cin >> n >> k;
  vector<tmp> info(n);
  for(int i = 0; i < n; i++){
    cin >> info[i].w >> info[i].v;
  }

  vector<int> cache(k+1,0);
  for(int i = 0; i < n; i++){
    for(int j = k; j >= info[i].w; j--){
      cache[j] = max(cache[j],cache[j-info[i].w]+info[i].v);
    }
  }
  cout << cache[k];
}