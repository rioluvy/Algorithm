#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;
int main(){
  vector<int> tmp(9);
  for(int i = 0; i < 9; i++){
    cin >> tmp[i];
  }
  int max = *max_element(tmp.begin(), tmp.end());
  int idx = max_element(tmp.begin(), tmp.end())-tmp.begin();
  cout << max << endl << idx+1;
}