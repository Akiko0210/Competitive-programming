#include <iostream>
#include <vector>
#include <map> 

using namespace std;

vector<vector<int> > G;
vector<int> a;

void dfs(int cur, int par) {
    cout << a[cur] << " ";
    for(int child : G[cur]) {
        if(child != par) {
            dfs(child, cur);
        }
    }
}

int main () {
    int n;
    cin >> n;
    a.resize(n);
    G.resize(n);

    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for(int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }

    map<int, vector<int> > G;
    /*
    0
    1
    2
    3
    4
    ..
    n - 1


    A
    B
    C
    D
    ..
    
    
    */

    dfs(0, -1);
    cout << "\n";



    return 0;
}