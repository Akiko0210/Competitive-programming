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
    /*
    abb
    bab
    bba

    abc 1
    acb 2
    bac 3
    bca 4
    cab 5
    cba 6

    aaeg 1
    aage 2
    aeag 3
    aega 4
    agae 5
    agea 6
    eaag 7
    eaga 8
    egaa 9
    gaae 10
    gaea 11
    geaa 12
    
    a**a
    agea

    abbcc 
    b***a
    bbccddeea
    */

    string s;
    cin >> s;
    int n = s.size();

    vector<int> cnt(26, 0);
    for(char c : s) {
        cnt[c - 'a']++;
    }

    vector<char> ans(n);

    bool hasrem = false;
    char remchar;

    int l = 0, r = n - 1;
    for(int i = 0; i < 26; i++) {
        if(cnt[i] == 0) continue;
        if(hasrem) {
            if((r - l + 1) == cnt[i] + 1) {
                ans[n / 2] = remchar;
                for(; l <= r; l++) {
                    if(l == n / 2) continue;
                    ans[l] = 'a' + i;
                }
            } else {
                ans[r--] = remchar;
                for(; i < 26; i++) {
                    while(cnt[i]--) {
                        ans[l++] = 'a' + i;
                    }
                }
            }
            break;
        } 
        while(cnt[i] >= 2) {
            ans[l++] = 'a' + i;
            ans[r--] = 'a' + i;
            cnt[i] -= 2;
        }     
        if(cnt[i] == 1) {
            hasrem = true;
            remchar = i + 'a';
        }
    }
    if(l == r) {
        ans[l] = remchar;
    }

    for(char c : ans) {
        cout << c;
    }
    cout << "\n";


}

int main() {
    int t;
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
