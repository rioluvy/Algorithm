#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
using namespace std;

int r, c, visited[300][301], a, b;
int dx[4] = {0,1,-1,0};
int dy[4] = {-1,0,0,1};
char arr[300][301];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    queue<pii> q;
    vector<pii> v;
    cin >> r >> c;
    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            cin >> arr[i][j];
            if(arr[i][j] == 'v' ){
                v.push_back({i,j});
                b++;
            }
            else if(arr[i][j] == 'o') a++;
        }
    }

    for(int k = 0; k < v.size(); k++){
        q.push(v[k]);
        int tmpa = 0;
        int tmpb = 1;
        while(!q.empty()){
            auto [x,y] = q.front();
            visited[x][y] = 1;
            q.pop();
            
            for(int i = 0; i < 4; i++){
                int nx = x+dx[i];
                int ny = y+dy[i];
                if(arr[nx][ny] != '#' && !visited[nx][ny]) {
                    visited[nx][ny] = 1;
                    if(arr[nx][ny] == 'o') tmpa++;
                    if(arr[nx][ny] == 'v') tmpb++;
                    q.push({nx,ny});
                }
            }
        }
        if(tmpa > tmpb){
            b -= tmpb;
        }
        else a -= tmpa;
    }
    cout << a << " " << b;
}