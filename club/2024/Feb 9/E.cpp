#include <bits/stdc++.h>

using namespace std;

int main () {
    int t;
    cin >> t;
    while(t--) {
        int n, m, k;
        cin >> n >> m >> k;
        set<int> sa, sb;
        for(int i = 0; i < n; i++) {
            int x;
            cin >> x;
            sa.insert(x);
        }
        for(int i = 0; i < m; i++) {
            int x;
            cin >> x;
            sb.insert(x);
        }

        vector<int> a, b;
        for(int x : sa) {
            a.push_back(x);
        }
        for(int x : sb) {
            b.push_back(x);
        }

        n = a.size();
        m = b.size();

        int onlya = 0, onlyb = 0, both = 0;
        bool isans = true;
        for(int i = 1; i <= k; i++) {
            // cout << onlya << " " << onlyb << " " << both << "\n"
            if((onlya + both < n && a[onlya + both] == i) && (onlyb + both < m && b[onlyb + both] == i)) {
                both++;
                continue;
            }

            if(onlya + both < n && a[onlya + both] == i && onlya < k / 2) {
                onlya++;
                continue;
            }

            if(onlyb + both < m && b[onlyb + both] == i && onlyb < k / 2) {
                onlyb++;
                continue;
            }
            isans = false;
            break;
        }
        cout << (isans ? "YES\n" : "NO\n");

    }


    return 0;
}