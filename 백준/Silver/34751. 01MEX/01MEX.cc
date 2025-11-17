#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<string>
#include<cstring>
#include<climits>
#define pii pair<int,int>
#define ll long long
using namespace std;

int n, arr[500001];
ll cnt;

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);cout.tie(0);

  cin >> n;
  queue<int> zero;
  queue<int> one;
  for(int i = 0; i < n; i++){
    cin >> arr[i];
    if(arr[i]) one.push(i);
    else zero.push(i);
  }

  for(int i = 0; i < n; i++){
    int pivot = arr[i];
    int tmp;
    if(pivot){
      while(!zero.empty()){
        tmp = zero.front();
        if(tmp < i) zero.pop();
        else {
          cnt += (n-tmp)*2;
          break;
        }
      }
    }
    else{
      while(!one.empty()){
        tmp = one.front();
        if(tmp < i) one.pop();
        else{
          cnt += (tmp-i);
          cnt += (n-tmp)*2;
          break;
        }
      }
      if(one.empty()) cnt += (n-i);
    }
  }
  cout << cnt;
}