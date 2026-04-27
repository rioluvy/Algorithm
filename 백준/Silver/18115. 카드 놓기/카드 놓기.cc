#include <iostream>
#include <vector>
#include <deque>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> card(n);
	for(int i = n-1 ; i >= 0; i--){
		cin >> card[i];
	}
	deque<int> dq;
	int num = 1;
	for(auto v : card){
		if(v == 1) {
			dq.push_back(num);
		}else if(v==2){
			int temp = dq.back();
            dq.pop_back();
            dq.push_back(num);
            dq.push_back(temp);
		}else{
			dq.push_front(num);
		}
		num++;
	}
	while(n--){
		cout << dq.back() << " ";
		dq.pop_back();
	}
}

