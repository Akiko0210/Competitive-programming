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

void solve() {
    int n;
    cin >> n;
    string cur = "";
    bool turn = false;
    while(n--) {
        if(turn) {
            string temp = "1" + cur;
            cout << "? " << temp << endl;
            bool ans;
            cin >> ans;
            if(!ans) {
                cur = "0" + cur;
            } else {
                cur = "1" + cur;
            }
        } else {
            string temp = cur + "1";
            cout << "? " << temp << endl;
            bool ans;
            cin >> ans;
            if(!ans) {
                temp = cur + "0";
                cout << "? " << temp << endl;
                cin >> ans;
                if(!ans) {
                    turn = true;
                    n++;
                    continue;
                }
            }
            cur = temp;
        }
    }
    cout << "! " << cur << endl;
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

