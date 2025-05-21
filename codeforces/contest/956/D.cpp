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

ll count_inversion(vector<int>& a, int l, int r) {
    if(l == r) {
        return 0;
    }
    ll m = (l + r) / 2, x = count_inversion(a, l, m), y = count_inversion(a, m + 1, r);
    ll lp = l, rp = m + 1, val = 0, ind = 0;
    vector<int> nums_in_order(r - l + 1, 0);

    while(lp <= m && rp <= r) {
        if(a[lp] > a[rp]) {
            nums_in_order[ind++] = a[rp++];
        } else {
            val += rp - m - 1;
            nums_in_order[ind++] = a[lp++];
        }
    }
    while(lp <= m) {
        val += rp - m - 1;
        nums_in_order[ind++] = a[lp++];
    }
    while(rp <= r) {
        nums_in_order[ind++] = a[rp++];
    }

    ind = 0;
    while(l <= r) {
        a[l++] = nums_in_order[ind++];
    }
    return x + y + val;
}

void solve() {

    /*
    1. swapping numbers at position l and r of a takes dis * 2 - 1 (dis = r - l + 1) operations if we only swap 2 adjacent numbers.
    Meanwhile, swapping 2 numbers at position p and q from array b takes dis1 * 2 - 1(dis1 = q - p + 1) operations if we only swap 2 adjacent numbers. 
    In 2 move, we can always any 2 adjacent numbers and put them back. 
    => We can redefine our operation as: swap any 2 numbers from array a and we can swap any 2 numbers from array b in 1 operation. 
    
    2. let's say we swapped the numbers at position l and r, 
    and there was x numbers less than array[l] in interval [l, r]
    and there was y numbers greater than array[r] in interval [l, r]
    the number of inversions will count -= x + y - (r - l + 1 - x) - (r - l + 1 - y) = count -= 2 * (x + y - r + l - 1)
    => parity of number of inversion does not change. => in order to answer to be YES, 
    parity of numbers of inversions has to be same in array a and b and they have to have same number set. 

    3. To calculate the number of inversions in the array, do divide and conquer. 
    */
    int n;
    cin >> n;
    vector<int> a(n), b(n), ca, cb;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for(int i = 0; i < n; i++) {
        cin >> b[i];
    }
    ca = a;
    cb = b;
    sort(ca.begin(), ca.end());
    sort(cb.begin(), cb.end());
    if(ca != cb || count_inversion(a, 0, n - 1) % 2 != count_inversion(b, 0, n - 1) % 2) {
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
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

