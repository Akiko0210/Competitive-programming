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
mt19937_64 rng((unsigned int) chrono::steady_clock::now().time_since_epoch().count());

const ll MOD = 1e9 + 7;

int main() {
    string s, t;
    cin >> s >> t;
    int n = s.size(), m = t.size();
    vector<int> pos(26, -1);
    vector<int> pos1(26, -1);
    for(int i = 1; i < n; i++) {
        if(pos[s[i] - 'a'] == -1)
            pos[s[i] - 'a'] = i;
    }
    int ans = INF, bestchar;
    for(int i = m - 2; i >= 0; i--) {
        int c = t[i] - 'a';
        if(pos1[c] == -1) {
            pos1[c] = i;
            if(pos[c] > 0 && ans > m - i + pos[c]) {
                ans = m - i + pos[c];
                bestchar = c;
            }
        }
    }
    if(ans == INF) {
        cout << "-1\n";
        return 0;
    }

    cout << s.substr(0, pos[bestchar]) + t.substr(pos1[bestchar]) << "\n";
    return 0;
}

/* stuff you should look for
    * int overflow, array bounds
    * special cases (n=1?)
    * do smth instead of nothing and stay organized
    * WRITE STUFF DOWN
    * DON'T GET STUCK ON ONE APPROACH
*/

