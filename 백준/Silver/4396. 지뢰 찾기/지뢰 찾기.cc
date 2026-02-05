#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
using namespace std;

int n;
int dx[8] = {-1,-1,-1,0,0,1,1,1};
int dy[8] = {-1,0,1,-1,1,-1,0,1};

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n;
    vector<string> trap(n), info(n);
    for(int i = 0; i < n; i++){
        cin >> trap[i];
    }
    for(int i = 0; i < n; i++){
        cin >> info[i];
    }
    bool flag = false;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(info[i][j] == 'x' && trap[i][j] == '*') flag = true;
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(info[i][j] == 'x') {
                if(trap[i][j] == '*') cout << "*";
                else{
                    int cnt = 0;
                    for(int k = 0; k < 8; k++){
                        int nx = i+dx[k];
                        int ny = j+dy[k];
                        if(nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
                        if(trap[nx][ny] == '*') cnt++;
                    }
                    cout << cnt;
                }
            }
            else if(trap[i][j] == '*' && flag) cout << "*";
            else cout << ".";

        }
        cout << "\n";
    }
}