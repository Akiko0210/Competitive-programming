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

    /*
    if we know how many consonants and vowels, the answer is trivial.
    */
    string s, vowels = "AEIOU";
    cin >> s;
    vector<int> cnt(26, 0);
    for(char c : s) {
        cnt[c - 'A']++;
    }
    int vowelSum = 0;
    for(char c : vowels) {
        vowelSum += cnt[c - 'A'];
    }

    int n = s.size(), consSum = n - vowelSum, ans = 0;
    consSum -= cnt['Y' - 'A'] + cnt['N' - 'A'] + cnt['G' - 'A'];

    for(int v = 0; v <= cnt['Y' - 'A']; v++) {
        for(int c = 0; c <= min(cnt['N' - 'A'], cnt['G' - 'A']); c++) {
            int vcnt = vowelSum + v;
            int ccnt = consSum + cnt['Y' - 'A'] - v + cnt['N' - 'A'] + cnt['G' - 'A'] - c;
            // cout << c << ' ' << ccnt << ' ' << vcnt << '\n';
            int extra = min(c, vcnt * 2);
            ans = max(ans, min(vcnt, ccnt / 2) * 3 + extra);
        }
    }
    cout << ans << "\n";

    return 0;
}

/* stuff you should look for
    * int overflow, array bounds
    * special cases (n=1?)
    * do smth instead of nothing and stay organized
    * WRITE STUFF DOWN
    * DON'T GET STUCK ON ONE APPROACH
*/

