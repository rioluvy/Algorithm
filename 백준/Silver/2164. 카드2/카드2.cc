#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
#include <stack>
#include <deque>
#define endl "\n"

using namespace std;
int main(){
  ios::sync_with_stdio(0); cin.tie(0);
  deque<int> deque;
  int n;
  cin >> n;
  for(int i = 1; i <= n; i++){
    deque.push_back(i);
  }
  while(deque.size() != 1){
    deque.pop_front();
    int tmp = deque.front();
    deque.pop_front();
    deque.push_back(tmp);
  }
  cout << deque.front();
}