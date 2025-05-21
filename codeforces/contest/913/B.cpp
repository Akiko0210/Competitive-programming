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
    string s;
    cin >> s;
    int n = s.size();
    vector<bool> del(n, 0);
    stack<int> a, b;
    for(int i = 0; i < n; i++) {
        if(s[i] == 'B') {
            del[i] = 1;
            if(!a.empty()) {
                del[a.top()] = 1;
                a.pop();
            }
            continue;
        }
        if(s[i] == 'b') {
            del[i] = 1;
            if(!b.empty()) {
                del[b.top()] = 1;
                b.pop();
            }
            continue;
        }

        if(s[i] >= 'A' && s[i] <= 'Z') {
            a.push(i);
        } else {
            b.push(i);
        }
    }
    for(int i = 0; i < n; i++) {
        if(!del[i]) cout << s[i];
    }
    cout << "\n";

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

