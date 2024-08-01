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
    string s;
    cin >> n >> s;
    if(n & 1) {
        cout << "-1\n";
        return;
    }

    vector<int> cnt(26, 0), cnt1(26, 0);
    int mx = 0;

    for(char c : s) {
        cnt[c - 'a']++;
        mx = max(mx, cnt[c - 'a']);
    }

    if(mx > n / 2) {
        cout << "-1\n";
        return;
    }

    for(int l = 0, r = n - 1; l < r; l++, r--) {
        if(s[l] == s[r]) {
            cnt1[s[l] - 'a']++;
        }
    }

    multiset<int> st;

    for(int x : cnt1) {
        if(x > 0) {
            st.insert(x);
        }
    }

    int ans = 0;
    while(st.size() > 1) {
        int most_frequent = *st.rbegin();
        int least_frequent = *st.begin();
        // debug(most_frequent, least_frequent);
        auto mf = st.find(most_frequent);
        st.erase(mf);
        auto lf = st.find(least_frequent);
        st.erase(lf);
        most_frequent--;
        least_frequent--;
        if(most_frequent > 0) {
            st.insert(most_frequent);
        }
        if(least_frequent > 0) {
            st.insert(least_frequent);
        }
        ans++;
    }

    if(st.empty()) {
        cout << ans << "\n";
        return;
    }

    cout << ans + *st.begin() << "\n";
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

