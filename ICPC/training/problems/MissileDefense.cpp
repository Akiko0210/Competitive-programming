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

double todeg(double rad) {
    return rad * 180.0 / M_PI;
}

int main() {
    // cout << todeg(atan2(1, 0)) << "\n";
    ll Xm, Vx, Vy, Xa, Va, T;
    cin >> Xm >> Vx >> Vy >> Xa >> Va >> T;
    double alpha = atan2(Vy * T - 16 * T * T, Xm - Xa + Vx * T);
    if(alpha <= 0) {
        cout << "start running\n";
        return 0;
    }
    double t = T - (Vy * T - 16 * T * T) / (Va * sin(alpha));
    if(t < 0) {
        cout << "start running\n";
        return 0;
    }
    cout << fixed << setprecision(8) << t << " " << todeg(alpha) << "\n";


    return 0;
}

/* stuff you should look for
    * int overflow, array bounds
    * special cases (n=1?)
    * do smth instead of nothing and stay organized
    * WRITE STUFF DOWN
    * DON'T GET STUCK ON ONE APPROACH
*/

