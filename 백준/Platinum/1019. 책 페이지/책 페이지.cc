#include<bits/stdc++.h>
#define FAST_IO ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

int arr[10] = {0,0,0,0,0,0,0,0,0,0};

void trial(int a, int b, int c){
    while(a%10 != 0 && a <= b){
        arr[a%10] += c;
        a++;
    }
    if(a > b) return;
    while(b%10 != 9 && a <= b){
        int tmp = b;
        while(tmp != 0){
            arr[tmp%10] += c;
            tmp /= 10;
        }
        b--;
    }

    for(int i = 0; i < 10; i++){
        arr[i] += (b/10-a/10+1)*c;
    }
    trial(a/10,b/10,c*10);
}

int main(){
    FAST_IO
    int n;
    cin >> n;

    trial(1,n,1);
    for(auto& i:arr) cout << i << " ";
}