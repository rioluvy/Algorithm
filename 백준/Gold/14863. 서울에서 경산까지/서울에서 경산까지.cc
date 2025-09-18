#include<iostream>
#define INF_MIN -2100000000
using namespace std;

struct travel{
  int a,b,c,d; // 도보시간, 도보 모금액, 자전거시간, 자전거 모금액
};

int cache[101][100001];

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n, k;
  cin >> n >> k;
  travel *arr = new travel[n+1];
  for(int i = 1; i <= n; i++){
    cin >> arr[i].a >> arr[i].b >> arr[i].c >> arr[i].d;
  }
  for(int i = 0; i <= n; i++){
    for(int j = 0; j <= k; j++){
      cache[i][j] = INF_MIN;
    }
  }
  cache[0][0] = 0;

  for(int i = 1; i <= n; i++){
    for(int j = 0; j <= k; j++){
      if(j >= arr[i].a) cache[i][j] = max(cache[i][j],cache[i-1][j-arr[i].a]+arr[i].b);
      if(j >= arr[i].c) cache[i][j] = max(cache[i][j],cache[i-1][j-arr[i].c]+arr[i].d);
    }
  }
  int ans = INF_MIN; 
  for(int i = 0; i <= k; i++){
    ans = max(ans,cache[n][i]);
  }
  cout << (ans != INF_MIN ? ans : 0);
}