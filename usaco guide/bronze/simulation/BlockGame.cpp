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
    ifstream cin("blocks.in");
    ofstream cout("blocks.out");

    int n;
    cin >> n;
    vector<int> cnt(26, 0);
    for(int i = 0; i < n; i++) {
        string s, t;
        cin >> s >> t;
        vector<int> temp(26, 0), temp1(26, 0);
        for(char c : s) {
            temp[c - 'a']++;
        }
        for(char c : t) {
            temp1[c - 'a']++;
        }
        for(int j = 0; j < 26; j++) {
            cnt[j] = cnt[j] + max(temp[j], temp1[j]);
        }
    }

    for(int i = 0; i < 26; i++) {
        cout << cnt[i] << "\n";
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

