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
    int n;
    cin >> n;
    stack<pii> b;
    vector<int> d(n), tab(n), space(n);
    int curd = 0;
    for(int i = 0; i < n; i++) {
        string s;
        cin >> s;
        int tb = 0, sp = 0;

        for(int i = 0; i < s.size() - 1; i++) {
            if(s[i] == 't') tb++;
            else sp++;
        }

        if(s.back() == '{') {
            d[i] = curd;
            curd++;
        } else {
            curd--;
            d[i] = curd;
        }
        tab[i] = tb;
        space[i] = sp;
    }

    for(int x = 1; x <= 1000; x++) {
        int y = -1;
        bool can = true;
        for(int i = 0; i < n; i++) {
            int len = tab[i] * x + space[i];
            if(d[i] == 0) {
                if(len != 0) {
                    can = false;
                    break;
                }
                continue;
            }
            if(y == -1) {
                if(len % d[i] == 0) {
                    y = len / d[i];
                    continue;
                } else {
                    can = false;
                    break;
                }
                continue;
            }
            if(y * d[i] != len) {
                can = false;
                break;
            }
        }
        if(can) {
            cout << x << "\n";
            return 0;
        }
    }
    cout << "-1\n";

    return 0;
}

/* stuff you should look for
    * int overflow, array bounds
    * special cases (n=1?)
    * do smth instead of nothing and stay organized
    * WRITE STUFF DOWN
    * DON'T GET STUCK ON ONE APPROACH
*/

