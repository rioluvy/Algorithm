#include <iostream>

#include <algorithm>

#include <vector>

#include <tuple>

#include <cmath>

#define endl "\n"

using namespace std;

int parent[101];

int find(int u){

  if(parent[u]==u) return u;

	return parent[u] = find(parent[u]);}

void merge(int u,int v){

  u=find(u);

  v=find(v);

	if(u==v) return;

	else if(u<v) parent[v]=u;

	else parent[u]=v;

}

int main(){

	ios_base::sync_with_stdio(0);

	cin.tie(NULL);cout.tie(NULL);

	

	int n;

	cin>>n;

	double x1,y1,tmp,x2,y2;

	vector<pair<double,double>> star;

	vector<tuple<double,double,double>> dist;

	star.push_back({0,0});

	for(int i=0;i<n;i++){

		cin >> x1 >> y1;

		star.push_back({x1,y1});

	}

  for(int i=1;i<n+1;i++){

    x1=star[i].first;

		y1=star[i].second;

		for(int j=i+1;j<n+1;j++){

			x2=star[j].first;

			y2=star[j].second;

			tmp=sqrt(pow(x2-x1,2) + pow(y2-y1,2));

      dist.push_back({tmp,i+1,j+1});

		}

	}

	for(int i=1;i<n+1;i++){

		parent[i] += i;

	}

	sort(dist.begin(),dist.end());

	double a,b,c,ans=0;

	int cnt=0,i=0;

	while(cnt != n-1){

		c=get<0>(dist[i]);

		a=get<1>(dist[i]);

    b=get<2>(dist[i]);

    if(find(a)!=find(b)){

			merge(a,b);

      cnt++;

			ans+=c; 

		}

		i++;

	}

	cout<<round(ans*100)/100;

}