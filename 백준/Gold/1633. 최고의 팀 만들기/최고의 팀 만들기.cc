#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cstdio>
#include <cstring>
#define endl "\n"

using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<long,long>;

int white[1001];
int black[1001];
int cache[16][16][1001];
int i = 0;

int trial(int w, int b, int num){
	if(num == 0) return 0;

	int &ret = cache[w][b][num];
	if(ret != -1) return ret;

	ret = 0;
	if(w>0) ret = max(ret,trial(w-1,b,num-1) + white[num-1]);
	if(b>0) ret = max(ret,trial(w,b-1,num-1)+ black[num-1]) ;
	ret = max(ret,trial(w,b,num-1));
	return ret;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);

	memset(cache,-1,sizeof(cache));
	int w,b;
	while(cin >> w >> b){
		white[i] = w;
		black[i] = b;
		i++;
	}
	cout << trial(15,15,i);
}
