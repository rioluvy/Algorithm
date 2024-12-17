#include <iostream>
using namespace std;

int main() {
	int n,right,left,a,b,arr[5001];
	cin >> n;
	right=n;left=n-1;
	arr[n] = right;arr[1]=left;
	int tmp=n-2, idx = n-1,c=(n-2)/2;
	while(c--){
		a=tmp;
		b=tmp-1;
		if(right+b >= left+a){
			arr[idx]=b;
			arr[n-idx+1]=a;
			right+=b;
			left+=a;
		}else{
			arr[idx]=a;
			arr[n-idx+1]=b;
			right+=a;
			left+=b;
		}
		idx--;
		tmp-=2;
	}
	if(n%2==1) arr[n/2+1]=1;
	for(int i = 1; i <= n; i++) cout << arr[i] << " ";
}