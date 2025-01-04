#include <bits/stdc++.h>

using namespace std;

int x[] = {1, 0, -1, 0};
int y[] = {0, 1, 0, -1};
int n, m;

vector<vector<bool> > bfs(int i, int j, vector<string>& maze) {
    vector<vector<bool> > vis(n, vector<bool> (m, 0));
    vis[i][j] = 1;
    queue<pair<int, int> > q;
    q.push({i, j});
    while(!q.empty()) {
        auto cur = q.front();
        q.pop();
        if(maze[cur.first][cur.second] == '#') {
            continue;
        }
        for(int k = 0; k < 4; k++) {
            int nx = cur.first + x[k], ny = cur.second + y[k];
            if(nx < 0 || nx >= n || ny < 0 || ny >= m || vis[nx][ny]) 
                continue;
            
            vis[nx][ny] = 1;
            q.push({nx, ny});
        }
    }

    return vis;
}

void solve() {
    cin >> n >> m;
    vector<string> maze(n);
    for(int i = 0; i < n; i++) {
        cin >> maze[i];
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(maze[i][j] == 'B') {
                for(int k = 0; k < 4; k++) {
                    int nx = i + x[k], ny = j + y[k];
                    if(nx < 0 || nx >= n || ny < 0 || ny >= m || 
                    maze[nx][ny] == '#' || maze[nx][ny] == 'B') 
                        continue;
                    
                    if(maze[nx][ny] == 'G') {
                        cout << "No\n";
                        return;
                    }
                    maze[nx][ny] = '#';
                }
            }
        }
    }

    vector<vector<bool> > possible_escape = bfs(n - 1, m - 1, maze);
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(maze[i][j] == 'G' && !possible_escape[i][j]) {
                cout << "No\n";
                return;
            }
            if(maze[i][j] == 'B' && possible_escape[i][j]) {
                cout << "No\n";
                return;
            }
        }
    }
    cout << "Yes\n";
    return;
    


}

int main() {
    int t = 1;
    cin >> t;
    while(t--) {
        solve();
    }


    return 0;
}

/* stuff you should look for
    * int overflow, array bounds
    * special cases (n=1?)
    * do smth instead of nothing and stay organized
    * WRITE STUFF DOWN
    * DON'T GET STUCK ON ONE APPROACH
*/

