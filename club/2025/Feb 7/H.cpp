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
    int k;
    cin >> s >> t >> k;
    vector<bool> bad(26);
    for(int i = 0; i < 26; i++) {
        bad[i] = 1 - t[i] + '0';
    }
    unordered_set<string> good;
    int n = s.size();
    for(int i = 0; i < n; i++) {
        string cur = "";
        int curbad = 0;
        for(int j = i; curbad + bad[s[j] - 'a'] <= k && j < n; j++) {
            curbad += bad[s[j] - 'a'];
            cur += s[j];
            good.insert(cur);
        }
    }
    // for(string temp : good) {
    //     cout << temp << "\n";
    // }

    cout << good.size() << "\n";



    return 0;
}

/* stuff you should look for
    * int overflow, array bounds
    * special cases (n=1?)
    * do smth instead of nothing and stay organized
    * WRITE STUFF DOWN
    * DON'T GET STUCK ON ONE APPROACH
*/

