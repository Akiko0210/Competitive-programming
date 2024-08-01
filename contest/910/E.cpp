#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define ss second
#define ff first
#define pb push_back
#define pii pair<int, int>
#define INF INT_MAX
using namespace std;
void debug_out() { cerr << endl; }
template<typename Head, typename... Tail> void debug_out(Head H, Tail... T) { cerr << ' ' << H; debug_out(T...); }
#ifdef AKIKO_DEBUG
#define debug(...) cerr << "\033[1;31m(" << #__VA_ARGS__ << "):\033[0m", debug_out(__VA_ARGS__)
#else
#define debug(...)
#endif

#define FAST ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const ll MOD = 1e9 + 7;

void solve() {
    /*
    s[i] < s[j]
    but 
    ind[s[i]] > ind[s[j]]
    NO
    */
    int n, m;
    string s, t;
    cin >> n >> m >> s >> t;
    vector<queue<int> > inds(26);
    for(int i = 0; i < n; i++) {
        inds[s[i] - 'a'].push(i);
    }

    vector<int> latest(26, -1);
    for(int i = 0; i < m; i++) {
        int cur = t[i] - 'a', mx = -1;
        for(int j = cur + 1; j < 26; j++) {
            mx = max(mx, latest[j]);
        }

        while(inds[cur].size() > 0 && inds[cur].front() < mx) {
            inds[cur].pop();
        }

        if(inds[cur].size() == 0) {
            cout << "NO\n";
            return;
        }
        latest[cur] = inds[cur].front();
        inds[cur].pop();
    }
    cout << "YES\n";

}

int main() {
    int t = 1;
    cin >> t;
    while(t--) {
        solve();
    }


    return 0;
}

/* stuff you should look for
    * int overflow, array bounds
    * special cases (n=1?)
    * do smth instead of nothing and stay organized
    * WRITE STUFF DOWN
    * DON'T GET STUCK ON ONE APPROACH
*/

