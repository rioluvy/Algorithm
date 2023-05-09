#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#define endl "\n"

using namespace std;
bool compare(pair<int,int> x, pair<int,int> y);
int main(){
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  int a, b;
  cin >> n;
  vector<pair<int,int>> num(n);
  for(int i = 0; i < n; i++){
    cin >> a >> b;
    num[i] = (make_pair(a,b));
  }
  sort(num.begin(), num.end(), compare);

  for(int i = 0; i < n; i++){
    cout << num[i].first << ' ' << num[i].second << endl;
  }
}

bool compare(pair<int,int> x, pair<int,int> y){
  if(x.first == y.first) return x.second < y.second;
  else return x.first < y.first;
}