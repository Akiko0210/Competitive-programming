#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    // vector<string> a(n);
    vector<vector<int> > pos(n, vector<int> (k));
    for(int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for(int j = 0; j < k; j++) {
            pos[i][s[j] - 'A'] = j;
        }
    }

    vector<vector<bool> > before(k, vector<bool> (k, false));
    for(int i = 0; i < k; i++) {
        for(int j = 0; j < k; j++) {
            bool inall = true;
            for(int ind = 0; ind < n; ind++) {
                inall &= (pos[ind][i] < pos[ind][j]);
            }
            before[i][j] = inall;
        }
    }

    int ans = 0;
    vector<vector<bool> > dp(k, vector<bool> (k, false));
    dp[0] = vector<bool> (k, true);
    for(int i = 1; i < k; i++) {
        for(int j = 0; j < k; j++) {
            for(int l = 0; l < k; l++) {
                if(before[j][l] && dp[i - 1][j]) {
                    dp[i][l] = 1;
                }
            }
        }
    }

    for(int i = k - 1; i >= 0; i--) {
        for(int j = 0; j < k; j++) {
            if(dp[i][j]) {
                cout << i + 1 << "\n";
                return 0;
            }
        }
    }

 
    return 0;
}