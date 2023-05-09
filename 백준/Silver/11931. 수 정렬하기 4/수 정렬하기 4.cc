#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#define endl "\n"

using namespace std;
int main(){
  int n;
  cin >> n;
  vector<int> tmp(n);
  for(int i = 0; i < n; i++){
    cin >> tmp[i];
  }
  sort(tmp.rbegin(), tmp.rend());
  for(auto loop : tmp){
    cout << loop << endl;
  }
}