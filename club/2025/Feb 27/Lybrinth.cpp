#include <bits/stdc++.h>

using namespace std;

int main () {
    int n, m;
    cin >> n >> m;
    vector<string> a(n);
    pair<int, int> start, end;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        for(int j = 0; j < m; j++) {
            if(a[i][j] == 'A') start = {i, j};
            if(a[i][j] == 'B') end = {i, j};
        }
    }

    vector<pair<char, vector<int> > > moves = {{'U', {-1, 0}}, {'R', {0, 1}}, {'D', {1, 0}}, {'L', {0, -1}}};

    // dist[i][j] is the distance of node (i, j) from start position. Initially every node has infinity(1e9) distance. 
    vector<vector<int> > dist(n, vector<int> (m, 1e9));
    // bestmove[i][j] is the index of a move that leads to shortest route to reach (i, j).
    vector<vector<int> > bestmove(n, vector<int> (m));
    // start position cost is 0.
    cost[start.first][start.second] = 0;


    return 0;
}