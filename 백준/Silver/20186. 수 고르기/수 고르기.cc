#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<stack>
#include<cstring>
#include<climits>
#define pii pair<int,int>
#define piii pair<int,pair<int,int>>
#define ll long long
using namespace std;

int n, k, arr[5001];
ll ans;

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);cout.tie(0);

  cin >> n >> k;
  for(int i = 0; i < n; i++){
    cin >> arr[i];
  }
  for(int i = 0; i < k; i++){
    int tmp = *max_element(arr,arr+n);
    int idx = max_element(arr,arr+n)-arr;
    ans += tmp;
    arr[idx] = 0;
  }
  int psum = 0;
  for(int i = 1; i < k; i++){
    psum += i;
  }
  cout << ans-psum;
}