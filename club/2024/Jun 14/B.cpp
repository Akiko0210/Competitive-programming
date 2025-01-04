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

bool p[1001];

void sieve() {
    for(int i = 2; i * i <= 1000; i++) 
        if(!p[i])
            for(int j = i * i; j <= 1000; j += i) 
                p[j] = 1;
            
}

void solve() {
    string s;
    cin >> s;
    int n = s.size(); // 1000 N^2
    /*
    cnt[0] -> number of a in the string
    cnt[1] -> number of b in the string
    ...
    cnt[25] -> number of z in the string
    -> p[0] = 2, p[1] = 3 ... 
    -> num[0] = n / p[0] - 0, num[i] = n / p[i] - i
    6 -> 2, 3
    sum ({nums[x], ... nums[y]}) = cnt[0]
    sum ({nums[a], ... nums[b]}) = cnt[1]
    ...
    We just need to count the number of prime numbers that is (lets say that number is p) p * 2 > n
    Lets say that number is x. x + 1
    */

    vector<pair<int, char> > cnt(26);
    for(int i = 0; i < 26; i++) {
        cnt[i] = {0, char('a' + i)};
    }
    for(char c : s) {
        cnt[c - 'a'].ff++;
    }

    sort(cnt.rbegin(), cnt.rend());
    int x = 1; // we have freedom to choose the color of 1. 

    vector<bool> pos(n + 1, 0);
    for(int i = 2; i <= n; i++) {
        if(p[i]) {
            pos[i] = 1;
            continue;
        }

        // i is prime
        if(i * 2 > n) {
            x++;
        } else {
            pos[i] = 1;
        }
    }
    // debug(x);

    if(cnt[0].ff >= n - x) {
        cout << "YES\n";
        int j = 1;
        for(int i = 1; i <= n; i++) {
            // debug(pos[i]);
            if(pos[i]) {
                s[i - 1] = cnt[0].ss;
            } else {
                while(j < 26 && cnt[j].ff == 0) {
                    j++;
                }

                if(j == 26) {
                    j = 0;
                }

                // cnt[j].ff > 0;
                s[i - 1] = cnt[j].ss;
                cnt[j].ff--;
            }
        }
        cout << s << "\n";

    } else {
        cout << "NO\n";
    }


}

int main() {
    sieve();
    int t = 1;
    // cin >> t;
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

