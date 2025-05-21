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
    string s[2];
    int t, q, n;
    cin >> s[0] >> s[1] >> t >> q;
    n = s[0].size();
    vector<bool> blocked(n, 0), match(n, 1);
    int cnt = 0;
    for(int i = 0; i < n; i++) {
        if(s[0][i] != s[1][i]) {
            cnt++;
        }
    }

    queue<pii> qu; 
    while(q--) {
        if(!qu.empty() && qu.front().first == q) {
            int ind = qu.front().second;
            qu.pop();
            if(s[0][ind] != s[1][ind]) {
                cnt++;
            }
        }
        int type;
        cin >> type;
        if(type == 1) {
            int pos;
            cin >> pos;
            pos--;
            qu.push({q - t, pos});
            if(s[0][pos] != s[1][pos]) {
                cnt--;
            } 
        }
        if(type == 2) {
            int ind1, ind2, pos1, pos2;
            cin >> ind1 >> pos1 >> ind2 >> pos2;
            ind1--, pos1--, ind2--, pos2--;
            cnt -= (s[0][pos1] != s[1][pos1]) + (s[0][pos2] != s[1][pos2]);
            swap(s[ind1][pos1], s[ind2][pos2]);
            cnt += (s[0][pos1] != s[1][pos1]) + (s[0][pos2] != s[1][pos2]);
        }
        if(type == 3) {
            cout << (cnt == 0 ? "YES" : "NO") << "\n";
        }
    }
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
