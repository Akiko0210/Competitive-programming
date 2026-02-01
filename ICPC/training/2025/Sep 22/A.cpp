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

    int n = s.size(), consSum = n - vowelSum;
    if(vowelSum * 2 > consSum) {
        int ans = consSum / 2 * 3;
        if(consSum % 2 == 1 && cnt['N' - 'A'] > 0 && cnt['G' - 'A'] > 0) {
            ans++;
        }
        return 0;
    }
    /*
    Y -> vowel
    NG -> 1 cons
    CVC - syllable

    - never can increase the number of cons. 
    AANGNGNGNG -> 10

    when vowelSum * 2 <= consSum

    */ 
    consSum -= cnt['Y' - 'A'] + cnt['N' - 'A'] + cnt['G' - 'A'];
    int syl = min(consSum / 2, vowelSum), ans = syl * 3;
    vowelSum -= syl;
    consSum -= syl * 2;
    if((vowelSum + cnt['Y' - 'A']) * 2 <= consSum + cnt['N' - 'A'] + cnt['G' - 'A']) {
        int vow = (vowelSum + cnt['Y' - 'A']);
        while(vow * 2 <= consSum + cnt['N' - 'A'] + cnt['G' - 'A'] && cnt['N' - 'A'] && cnt['G' - 'A']) {
            consSum ++;
            cnt['N' - 'A']--;
            cnt['G' - 'A']--;
        }
        ans += (vowelSum + cnt['Y' - 'A']) * 3;
        cout << ans << "\n";
    } else {

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

