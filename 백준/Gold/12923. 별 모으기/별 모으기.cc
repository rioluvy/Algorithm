#include <iostream>
#include <algorithm>
#include <deque>
#define pii pair<int,int>
#define INF 1000000000
using namespace std;

bool compare(pii x, pii y){
	return x.second < y.second;
}

int main() {
	int n, a, b, star = 0, stageCnt = 0;
	deque<pii> info;
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> a >> b;
		info.push_back({a,b});
	}
    sort(info.begin(),info.end(),compare);
	while(!info.empty()){
		if(info[0].second <= star){
			star++;
			stageCnt++;
			if(info[0].first != INF) star++;
			info.pop_front();
		}
		else{
			int saveStar = star;
			for(int i = info.size()-1; i >= 0; i--){
				if(info[i].first <= star){
					info[i].first = INF;
					stageCnt++;
					star++;
					break;
				}
			}
			if(star == saveStar) {
				cout << "Too Bad";
				return 0;
			}
		}
	}
	cout << stageCnt;
}