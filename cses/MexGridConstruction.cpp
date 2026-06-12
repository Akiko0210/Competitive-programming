#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<vector<int> > ans(n, vector<int> (n));

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            unordered_set<int> seen;
            for(int k = 0; k < i; k++) {
                seen.insert(ans[k][j]);
            }
            for(int k = 0; k < j; k++) {
                seen.insert(ans[i][k]);
            }
            for(int k = 0; k < 2 * n; k++) {
                if(seen.find(k) == seen.end()) {
                    ans[i][j] = k;
                    break;
                }
            }
        }
    }

    for(auto &row : ans) {
        for(int x : row) {
            cout << x << " ";
        }
        cout << "\n";
    }

    return 0;
}
