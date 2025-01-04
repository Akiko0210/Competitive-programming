#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;
        vector<vector<char> > pos(n + 1);
        for(int i = 0; i < 26; i++) {
            pos[0].push_back('a' + i);
        }
        int a[n];
        for(int i = 0; i < n; i++) {
            cin >> a[i];
        }
        bool isans = true;
        string ans = "";
        for(int i = 0; i < n; i++) {
            if(pos[a[i]].empty()) {
                isans = false;
                break;
            }
            char x = pos[a[i]].back();
            ans += x;
            pos[a[i]].pop_back();
            pos[a[i] + 1].push_back(x);
        }
        if(isans) cout << ans << "\n";
    }


    return 0;
}