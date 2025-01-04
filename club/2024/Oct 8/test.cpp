#include <iostream> 
#include <vector>

using namespace std;

int main () {
    int n, m;
    cin >> n >> m;
    vector<vector<int> > a(n, vector<int> (m));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }

    vector pre(n + 1, vector(m + 1, 0));
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            pre[i][j] = pre[i - 1][j] + pre[i][j - 1] - 
            pre[i - 1][j - 1] + a[i - 1][j - 1];
        }
    }

    int q;
    cin >> q;
    while(q--) {
        int r1, c1, r2, c2;
        cin >> r1 >> c1 >> r2 >> c2;
        cout << pre[r2 + 1][c2 + 1] - pre[r2 + 1][c1] - 
        pre[r1][c2 + 1] + pre[r1][c1] << "\n";
    }


    return 0;
}