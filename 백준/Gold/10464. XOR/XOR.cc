#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
#include <stack>
#include <deque>
#include <set>
#define endl "\n"

using namespace std;
int XOR(int k);
int main(){
  ios::sync_with_stdio(0); cin.tie(0);
  int t;
  int s, f;
  cin >> t;
  while(t--){
    cin >> s >> f;
    cout << (XOR(s-1) ^ XOR(f)) << endl;
  }

}

int XOR(int k){
  int tmp = k % 4;
  if(tmp == 0) return k;
  else if(tmp == 1) return 1;
  else if(tmp == 2) return k+1;
  else return 0;
}