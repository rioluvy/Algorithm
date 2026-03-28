#include<bits/stdc++.h>
#define FAST_IO ios_base::sync_with_stdio(0);cin.tie(0);
#define pii pair<int,int>
using namespace std;

int n, arr[21][21], ans;
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

void move(int d){
    int startX = (dx[d] == 1) ? n-1 : 0;
    int endX = (dx[d] == 1) ? -1 : n;
    int stepX = (dx[d] == 1) ? -1 : 1;

    int startY = (dy[d] == 1) ? n-1 : 0;
    int endY = (dy[d] == 1) ? -1 : n;
    int stepY = (dy[d] == 1) ? -1 : 1;

    bool visited[21][21]{};
    for(int i = startX; i != endX; i += stepX){
        for(int j = startY; j != endY; j += stepY){
            if(!arr[i][j]) continue;
            
            int x = i, y = j;
            while(true){
                int nx = x + dx[d];
                int ny = y + dy[d];
                if(nx < 0 || ny < 0 || nx >= n || ny >= n) break;
                if(arr[nx][ny] == arr[x][y] && visited[nx][ny]) break;
                if(arr[nx][ny] != 0 && arr[nx][ny] != arr[x][y]) break;
                if(arr[nx][ny] == arr[x][y] && !visited[nx][ny]){
                    visited[nx][ny] = true;
                    arr[nx][ny] += arr[x][y];
                    arr[x][y] = 0;
                    break;
                }
                arr[nx][ny] = arr[x][y];
                arr[x][y] = 0;
                x = nx, y = ny;
            }
        }
    }
}

int trial(int cnt){
    if(cnt == 5){
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                ans = max(ans,arr[i][j]);
            }
        }
        return ans;
    }

    int backup[21][21];
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            backup[i][j] = arr[i][j];
        }
    }

    for(int d = 0; d < 4; d++){
        move(d);
        trial(cnt+1);

        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                arr[i][j] = backup[i][j];
            }
        }

    }
    return ans;
}

int main(){
    FAST_IO

    cin >> n;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> arr[i][j];
        }
    }

    cout << trial(0);
}