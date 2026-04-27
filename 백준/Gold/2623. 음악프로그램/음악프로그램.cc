#include <iostream>

#include <algorithm>

#include <vector>

#include <queue>

#define endl "\n"

using namespace std;

int main(){

  ios_base::sync_with_stdio(0);

	cin.tie(NULL);cout.tie(NULL);	int n,m,num,tmp,next;

	cin >> n >> m;

	vector<int> adj[1001];

	int check[1001]={0,};

	for(int i=0;i<m;i++){

		cin >> num >> tmp;

		while(--num){

			cin >> next;

			adj[tmp].push_back(next);

      tmp = next;

			check[next]++;

		}

	}

	queue<int> q;

	for(int i=1;i<n+1;i++){

		if(!check[i]){

			q.push(i);

		}

	}

	

  vector<int> ans;

  while(!q.empty()){

		tmp=q.front();

		q.pop();

    ans.push_back(tmp);

		for(int i=0;i<adj[tmp].size();i++){

			next=adj[tmp][i];

			check[next]--;

      if(!check[next]) q.push(next);

		}

	}

	if (ans.size()!=n){

    cout<<0;

		return 0;

	}else{

		for(auto v : ans) cout << v << endl;

	}

}