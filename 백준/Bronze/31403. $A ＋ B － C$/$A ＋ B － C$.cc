#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#define endl "\n"
#define ll long long
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	
	int a,b,c;
	cin >> a >> b >> c;
	cout << a+b-c << endl;
	string str = to_string(a);
	string str_a = to_string(b);
	str += str_a;
	int num = stoi(str);
	cout << num-c;
}