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
    int p, t;
    cin >> p >> t;    
    vector<string> teams;
    for(int i = 0; i < t; i++) {
        string s;
        cin >> s;
        bool valid = true;
        vector<bool> present(p, 0);
        for(char c : s) {
            if(c - 'A' >= p || present[c - 'A']) {
                valid = false;
                break;
            } else {
                present[c - 'A'] = 1;
            }
        }
        if(valid) {
            teams.pb(s);
        }
    }
    int m = teams.size();
    // for(string s : teams) {
    //     cout << s << " ";
    // }
    // cout << "\n";
    auto check = [&](int mask) -> bool {
        vector<bool> present(p, 0);
        for(int i = 0; i < m; i++) {
            if(mask & (1 << i)) {
                for(char c : teams[i]) {
                    if(present[c - 'A']) return false;
                    present[c - 'A'] = 1;
                }
            }
        }
        return true;
    };
    int ans = 0;
    for(int i = 0; i < (1 << m); i++) {
        if(check(i)) {
            int cnt = 0, temp = i;
            while(temp) {
                cnt += (temp & 1);
                temp /= 2;
            }
            ans = max(ans, cnt);
        }
    }
    cout << ans << "\n";
    /*
    
    */


    return 0;
}

/* stuff you should look for
    * int overflow, array bounds
    * special cases (n=1?)
    * do smth instead of nothing and stay organized
    * WRITE STUFF DOWN
    * DON'T GET STUCK ON ONE APPROACH
*/

