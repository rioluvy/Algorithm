#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#define endl "\n"

using namespace std;
bool compare(pair<int,string> x, pair<int,string> y);
int main(){
  ios::sync_with_stdio(0); cin.tie(0);
  int n, a;
  string b;
  cin >> n;
  vector<pair<int,string>> num(n);
  for(int i = 0; i < n; i++){
    cin >> a >> b;
    num[i] = (make_pair(a,b));
  }
  stable_sort(num.begin(), num.end(), compare);

  for(int i = 0; i < n; i++){
    cout << num[i].first << ' ' << num[i].second << endl;
  }
}

bool compare(pair<int,string> x, pair<int,string> y){
  return x.first < y.first;
}