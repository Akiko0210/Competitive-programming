#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<pair<int, int> > a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i].first;
    }
    map<string, int> mp;
    mp["ppp"] = 0;
    mp["pp"] = 1;
    mp["p"] = 2;
    mp["mp"] = 3;
    mp["mf"] = 4;
    mp["f"] = 5;
    mp["ff"] = 6;
    mp["fff"] = 7;

    vector<pair<int, string> > b(m);
    vector<pair<int, int> > c(n);
    for(int i = 0; i < m; i++) {
        cin >> b[i].first >> b[i].second;
        if(i > 0) {
            for(int j = b[i - 1].first - 1; j < b[i].first - 1; j++) {
                a[j].second = mp[b[i - 1].second];
            }
        }
    }
    for(int j = b[m - 1].first - 1; j < n; j++) {
        a[j].second = mp[b[m - 1].second];
    }
    sort(a.begin(), a.end(), [](pair<int, int> x, pair<int, int> y) -> bool {
        if(x.first < y.first) return 1;
        if(x.first > y.first) return 0;
        return x.second > y.second;
    });
    vector<int> cnt(8, 0);
    long long ans = 0;
    for(int i = 0; i < n; i++) {
        int ind = a[i].second;
        for(int j = ind + 1; j < 8; j++) {
            ans += cnt[j];
        }
        cnt[ind]++;
    }
    cout << ans << "\n";
    return 0;
}