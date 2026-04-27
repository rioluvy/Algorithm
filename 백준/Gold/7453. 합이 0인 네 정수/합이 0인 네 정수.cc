#include <iostream>
#include <algorithm>
#define lint long long
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    int arr[4][4001];
    cin >> n;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < 4; j++){
            cin >> arr[j][i];
        }
    }
    const int SIZE = 16000000;
    int *ab = new int[SIZE];
    int *cd = new int[SIZE];
    int len = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            ab[len] = arr[0][i]+arr[1][j];
            cd[len] = arr[2][i]+arr[3][j];
            len++;
        }
    }
    sort(ab,ab+len);
    sort(cd,cd+len);
    int left = 0, right = len-1;
    lint cnt = 0;
    while(left < len && right >= 0){
        if(ab[left]+cd[right] == 0){
            int tmpAB = ab[left], tmpCD = cd[right];
            lint cntAB = 0, cntCD = 0;
            //tmpAB와 같은수의 개수 카운트
            while(left < len && tmpAB == ab[left]){
                cntAB++;
                left++;
            }
            //tmpCD와 같은수의 개수 카운트
            while(right >= 0 && tmpCD == cd[right]){
                cntCD++;
                right--;
            }
            cnt += (cntAB*cntCD);
            continue;
        }
        if(ab[left]+cd[right] > 0){
            right--;
        }
        else if(ab[left]+cd[right] < 0){
            left++;
        }
    }
    cout << cnt;
}