#include <iostream>

#include <algorithm>

#include <queue>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
	int n,m,front,behind;    cin >>n>>m;

    vector<int> stu[32001];

    int check[32001] = {0,};

    int ans[32000];

    queue<int> q;

    for(int i=0;i<m;i++){

      cin >> front >> behind;

      stu[front].push_back(behind);

      check[behind]++;

    }

    for(int i=1;i<n+1;i++){

      if(!check[i]) q.push(i);

    }

    

    for(int i=0;i<n;i++){

      if(q.empty()) break;

      int tmp = q.front();

      q.pop();

      ans[i]= tmp;

      for(int j=0;j<stu[tmp].size();j++){

        int adj= stu[tmp][j];

        check[adj]--;

        if(!check[adj]) q.push(adj);

      }

    }

    for(int i=0;i<n;i++) cout << ans[i] << " ";

}