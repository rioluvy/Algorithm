#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
using namespace std;

int n, prime[100001], scores[100001], psum[100001];
string name[100001], num;

void sieve(int k){
  prime[0] = prime[1] = 1;
  for(int i = 2; i*i <= k; i++){
    if(!prime[i]){
      for(int j = i*i; j <= k; j+=i){
        prime[j] = 1;
      }
    }
  }
}

void primePsum(){
  int tmp = 0;
  for(int i = 2; i <= 100000; i++){
    if(!prime[i]) tmp++;
    psum[i] = tmp;
  }
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);cout.tie(0);

  cin >> n;
  sieve(100000);
  primePsum();

  for(int i = 0; i < n; i++){
    cin >> name[i] >> num;

    int x = stoi(num.substr(0,5));
    int y = stoi(num.substr(num.size()-5,5));
    if(x > y) swap(x,y);

    if(!prime[x] && !prime[y]) scores[i] = psum[y]-psum[x]+1;
    else if(!prime[x] && prime[y]) scores[i] = psum[y]-psum[x]+1;
    else if(prime[x] && !prime[y]) scores[i] = psum[y]-psum[x];
    else scores[i] = psum[y]-psum[x];
  }

  int maxScore = *max_element(scores,scores+n);
  int minScore = *min_element(scores,scores+n);
  vector<string> ans1;
  vector<string> ans2;
  for(int i = 0; i < n; i++){
    if(maxScore == scores[i]) ans1.push_back(name[i]);
    if(minScore == scores[i]) ans2.push_back(name[i]);
  }

  sort(ans1.begin(),ans1.end());
  sort(ans2.begin(),ans2.end());
  cout << ans1[0] << "\n" << ans2[0];
  
}