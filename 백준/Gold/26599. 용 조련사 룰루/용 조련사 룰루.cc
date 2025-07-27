#include<iostream>
#include<algorithm>
#define pii pair<int,int>
using namespace std;

int n, m;
pii arr[1000001];

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
  cin >> n >> m;
  for(int i = 1; i <= n; i++){
    int force;
    cin >> force;
    arr[i] = {force,i};
  }
  if(n == 1){
    cout << "YES\n" << 1;
    return 0;
  }
  sort(arr+1, arr+n+1);
  bool flag = true;
  for(int i = n; i > n-3; i--){
    if(i == 1) break;
    if(arr[i].first-arr[i-1].first > m) flag = false;
  }
  if(!flag){
    cout << "NO";
    return 0;
  }
  cout << "YES\n" << arr[n].second << " " << arr[n-1].second << " ";
  for(int i = 1; i <= n-2; i++){
    cout << arr[i].second << " ";
  }
}