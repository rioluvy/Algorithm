#include<bits/stdc++.h>
#define FAST_IO ios_base::sync_with_stdio(0);cin.tie(0);
#define pii pair<int,int>
#define piii pair<int,pair<int,int>>
using namespace std;

int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};

int main(){
    FAST_IO
    int t, h, w, key[26], visited[101][101], cnt;
    char arr[101][101];
    string k;
    cin >> t;
    while(t--){
        memset(visited,0,sizeof(visited));
        memset(key,0,sizeof(key));
        cnt = 0;
        cin >> h >> w;
        queue<pii> q;
        vector<piii> door;
        for(int i = 0; i < h; i++){
            for(int j = 0; j < w; j++){
                cin >> arr[i][j];
                if(arr[i][j] != '*' && (i == 0 || j == 0 || i == h-1 || j == w-1)){
                    if('A' <= arr[i][j] && arr[i][j] <= 'Z') door.push_back({arr[i][j],{i,j}});
                    else if('a' <= arr[i][j] && arr[i][j] <= 'z') {
                        key[arr[i][j]-'a'] = 1;
                        visited[i][j] = 1;
                        q.push({i,j});
                    }
                    else if(arr[i][j] == '$'){
                        visited[i][j] = 1;
                        cnt++;
                        q.push({i,j});
                    }
                    
                    else {
                        visited[i][j] = 1;
                        q.push({i,j});
                    }
                }
            }
        }

        cin >> k;
        if(k != "0"){
            for(char c : k) key[c-'a'] = 1;
        }

        for(int i = door.size()-1; i >= 0; i--){
            if(key[door[i].first - 'A'] == 1){
                visited[door[i].second.first][door[i].second.second] = 1;
                q.push(door[i].second);
                door.erase(door.begin()+i);
            }
        }

        while(!q.empty()){
            auto [x,y] = q.front();
            q.pop();

            for(int d = 0; d < 4; d++){
                int nx = x + dx[d];
                int ny = y + dy[d];
                if(nx < 0 || ny < 0 || nx >= h || ny >= w || arr[nx][ny] == '*') continue;

                if('A' <= arr[nx][ny] && arr[nx][ny] <= 'Z'){
                    if(key[arr[nx][ny]-'A'] == 0) {
                        if(!visited[nx][ny]) door.push_back({arr[nx][ny],{nx,ny}});
                        continue;
                    }
                }

                if('a' <= arr[nx][ny] && arr[nx][ny] <= 'z'){
                    key[arr[nx][ny]-'a'] = 1;
                    for(int i = door.size()-1; i >= 0; i--){
                        if(key[door[i].first - 'A'] == 0) continue;
                        if(!visited[door[i].second.first][door[i].second.second]){
                            visited[door[i].second.first][door[i].second.second] = 1;
                            q.push(door[i].second);
                        }
                        door.erase(door.begin()+i);
                    }
                }

                if(!visited[nx][ny]){
                    visited[nx][ny] = 1;
                    q.push({nx,ny});
                    if(arr[nx][ny] == '$') cnt++;
                }
            }
        }
        cout << cnt << "\n";
    } 
}