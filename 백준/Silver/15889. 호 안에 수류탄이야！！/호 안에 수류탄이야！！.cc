#include<iostream>
using namespace std;

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n, arr[30001], pw[30001];
  cin >> n;
  if(n==1) {
    cout << "권병장님, 중대장님이 찾으십니다";
    return 0;
  }
  for(int i = 0; i < n; i++){
    cin >> arr[i];
  }
  for(int i = 0; i < n-1; i++){
    cin >> pw[i];
  }
  int maxx = 0;
  for(int i = 0; i < n-1; i++){
    maxx = max(maxx, arr[i] + pw[i]);
    if(maxx < arr[i+1]){
      cout << "엄마 나 전역 늦어질 것 같아";
      return 0;
    }
  }
  cout << "권병장님, 중대장님이 찾으십니다";
}