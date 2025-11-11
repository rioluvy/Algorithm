#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
#include<map>
#include<queue>
#include<stack>
#include<string>
#include<cstring>
#include<sstream>
#include<climits>
#define pii pair<int,int>
#define piii pair<int,pair<int,int>>
#define ll long long
#define mod 1000000007
using namespace std;

int n, q, num, tmp1, tmp2, cnt;
map<int,int> m;

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);cout.tie(0);

  cin >> n;
  cnt = n;
  for(int i = 0; i < n; i++) {
    cin >> num;
    m[num]++;
  }
  cin >> q;
  while(q--){
    vector<int> a;
    vector<int> b;
    cin >> tmp1;
    for(int i = 0; i < tmp1; i++){
      cin >> num;
      a.push_back(num);
    }
    cin >> tmp2;
    for(int i = 0; i < tmp2; i++){
      cin >> num;
      b.push_back(num);
    }

    bool flag = true;
    for(int i = 0; i < tmp1; i++){
      if(m.find(a[i]) == m.end() || m[a[i]] == 0){
        flag = false;
        for(int j = 0; j < i; j++){
          m[a[j]]++;
          cnt++;
        }
        break;
      }
      m[a[i]]--;
      cnt--;
    }
    if(flag){
      for(int i = 0; i < b.size(); i++){
        m[b[i]]++;
        cnt++;
      }
    }
  }
  cout << cnt << "\n";
  for(auto v : m){
    for(int i = 0; i < v.second; i++) cout << v.first << " ";
  }
}