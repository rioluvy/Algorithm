#include <iostream>

#include <algorithm>

#include <vector>

#include <string>

#define endl "\n"

using namespace std;

string map[1001][1001];

int check[1001][1001];

int dx[4]={1,0,-1,0};

int dy[4]={0,1,0,-1};

string pos[4]={"D","R","U","L"};

int ans=0;

void dfs(int i,int j){

  string c = map[i][j];

  int next_i,next_j,idx;

  check[i][j]=1;

  auto tmp=find(begin(pos),end(pos),c);

  idx = distance(pos,tmp);

  next_i=i+dx[idx]; next_j=j+dy[idx];

  if(check[next_i][next_j]==1) ans++;

  else if(!check[next_i][next_j]) dfs(next_i,next_j);

  check[i][j]=2;

}

int main() {
ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
	int n,m;    string s;

    cin >> n >> m;

    for(int i=1;i<n+1;i++){

      cin >> s;

      for(int j=1;j<m+1;j++){

        map[i][j] = s[j-1];

      }

    }

    

    for(int i=1;i<n+1;i++){

      for(int j=1;j<m+1;j++){

        dfs(i,j);

      }

    }

    cout << ans;

}