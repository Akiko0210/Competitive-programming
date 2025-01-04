#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<string> my_map(n);

    int startx, starty, destx, desty;

    for(int i = 0; i < n; i++) {
        cin >> my_map[i];
        for(int j = 0; j < m; j++) {
            if(my_map[i][j] == 'S') {
                startx = i;
                starty = j;
            }
            if(my_map[i][j] == 'D') {
                destx = i;
                desty = j;
            }
        }
    }

    queue<pair<int, int> > q;
    q.push({startx, starty});
    vector<vector<int> > dist(n, vector<int> (m));
    vector<vector<bool> > vis(n, vector<bool> (m, false));
    vector<vector<pair<int, int> > > prev(n, vector<pair<int, int> > (m));
    dist[startx][starty] = 0;
    vis[startx][starty] = 1;

    int dx[] = {0, 1, 0, -1};
    int dy[] = {1, 0, -1, 0};

    // dx[0], dy[0] -> right? 
    // dx[1], dy[1] -> down
    // dx[2], dy[2] -> left
    // dx[3], dy[3] -> up


    while(!q.empty()) {
        auto cur = q.front(); // pair<int, int>
        q.pop();

        for(int i = 0; i < 4; i++) {
            int nx = cur.first + dx[i], ny = cur.second + dy[i];
            if(nx < 0 || nx >= n || ny < 0 || ny >= m || 
                vis[nx][ny] || my_map[nx][ny] == '#') {
                // 1. out of map
                // 2. visited 
                // 3. obstacles
                continue;
            }

            vis[nx][ny] = 1;
            dist[nx][ny] = dist[cur.first][cur.second] + 1;
            prev[nx][ny] = cur;
            q.push({nx, ny});
        }
    }

    pair<int, int> cur = {destx, desty};
    while(cur != make_pair(startx, starty)) {
        cout << cur.first << " " << cur.second << " -> ";
        cur = prev[cur.first][cur.second];
    }

    cout << cur.first << " " << cur.second << "\n";


    cout << dist[destx][desty] << " is answer\n";
    
 

    return 0;
}