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

int k;

void solve() {
    int n;
    string s;
    cin >> n >> s;
    /*
    s = concat of COW, OWC, WCO
    */
    vector<int> inds(n), cnt(3, 0);
    if(n & 1) {
        cout << "-1\n";
        return;
    }

    int len = n * 3;
    if(s.substr(0, len / 2) == s.substr(len / 2)) {
        cout << "1\n";
        for(int i = 0; i < len; i++) {
            cout << "1" << " \n"[i / (len - 1)];
        }
        return;
    }



    cout << "2\n";
    vector<int> ans(len);

    auto deal = [&] (int i, int j) {
        string a = s.substr(i * 3, 3), b = s.substr(j * 3, 3);
        if(a == b) {
            ans[i * 3] = 1;
            ans[i * 3 + 1] = 1;
            ans[i * 3 + 2] = 1;
            ans[j * 3] = 1;
            ans[j * 3 + 1] = 1;
            ans[j * 3 + 2] = 1;
        }
        if(a > b) {
            swap(a, b);
            swap(i, j);
        }
        if(a == "COW" && b == "OWC") {
            ans[i * 3] = 1;
            ans[i * 3 + 1] = 2;
            ans[i * 3 + 2] = 2;
            ans[j * 3] = 2;
            ans[j * 3 + 1] = 2;
            ans[j * 3 + 2] = 1;
        }
        if(a == "COW" && b == "WCO") {
            ans[i * 3] = 2;
            ans[i * 3 + 1] = 2;
            ans[i * 3 + 2] = 1;
            ans[j * 3] = 1;
            ans[j * 3 + 1] = 2;
            ans[j * 3 + 2] = 2;
        }
        if(a == "OWC" && b == "WCO") {
            ans[i * 3] = 1;
            ans[i * 3 + 1] = 2;
            ans[i * 3 + 2] = 2;
            ans[j * 3] = 2;
            ans[j * 3 + 1] = 2;
            ans[j * 3 + 2] = 1;
        }
    };

    for(int i = 0; i < n / 2; i++) {
        int j = n / 2 + i;
        deal(i, j);
    }

    for(int i = 0; i < len; i++) {
        cout << ans[i] << " \n"[i / (len - 1)];
    }


}

int main() {
    int t = 1;
    cin >> t >> k;
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

