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

bool check(string s) {
    int cnt = 0;
    for(char c : s) {
        if(c == ')') {
            cnt--;
        } else {
            cnt++;
        }

        if(cnt < 0) {
            return false;
        }
    }
    return cnt == 0;
}

void solve() {
    int n;
    string s, t;
    cin >> n >> s;
    t = s;
    reverse(t.begin(), t.end());
    if(check(s) || check(t)) {
        cout << "1\n";
        for(int i = 0; i < n; i++) {
            cout << 1 << ' ';
        }
        cout << '\n';
        return;
    }

    int cnt1 = 0, cnt0 = 0;
    for(int i = 0; i < n; i++) {
        if(s[i] == ')') cnt1++;
        else cnt0++;
    }

    if(cnt1 != cnt0) {
        cout << "-1\n";
        return;
    }

    vector<int> ans(n, 2);
    int l = 0, r = n - 1;
    while(l < r) {
        while(l < r && s[l] != '(') {
            l++;
        }

        while(l < r && s[r] != ')') {
            r--;
        }
        if(l == r) {
            break;
        }
        ans[l] = ans[r] = 1;
        l++, r--;
    }
    cout << 2 << "\n";
    for(int x : ans) {
        cout << x << " ";
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
