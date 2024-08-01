#include <bits/stdc++.h>

using namespace std;

int main () {
    int n, k, ans = 0;
    cin >> n >> k;
    multiset<int> s;
    vector<pair<int, int> > p(n);
    for(int i = 0; i < n; i++) {
        cin >> p[i].second >> p[i].first;
    }
    sort(p.begin(), p.end());
    for(int i = 0; i < n; i++) {
        auto it = s.lower_bound(-p[i].second);
        // cout << p[i].second << " " << p[i].first << "\n";

        if(it != s.end()) {
            // replace
            // cout << "replace\n";
            ans++;
            s.erase(it);
            s.insert(-p[i].first);
            continue;
        }

        if(s.size() < k) {
            // cout << "pushed\n";
            ans++;
            s.insert(-p[i].first);
        }
    }

    cout << ans << "\n";

    return 0;
}