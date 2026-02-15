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

struct Frac {
    // a / b
    ll a, b;
    Frac(ll x, ll y) {
        a = x;
        b = y;
    }
    Frac(int x) {
        a = x;
        b = 1;
    }
};

ll gcd(ll a, ll b) {
    if(b == 0) return a;
    return gcd(b, a % b);
}

Frac clean(ll a, ll b) {
    // a, b
    ll g = abs(gcd(a, b));
    if(b < 0) {
        b *= -1;
        a *= -1;
    }
    return Frac(a / g, b / g);
}

Frac operator -(Frac x, Frac y) {
    ll denom = x.b * y.b;
    ll num = x.a * y.b - y.a * x.b;
    return clean(num, denom);
}
Frac operator +(Frac x, Frac y) {
    ll denom = x.b * y.b;
    ll num = x.a * y.b + y.a * x.b;
    return clean(num, denom);
}
Frac operator *(Frac x, Frac y) {
    ll denom = x.b * y.b;
    ll num = x.a * y.a;
    return clean(num, denom);
}
Frac operator /(Frac x, Frac y) {
    ll denom = x.b * y.a;
    ll num = x.a * y.b;
    return clean(num, denom);
}
bool operator <=(Frac x, Frac y) {
    Frac d = y - x;
    return d.a >= 0;
}
bool operator >=(Frac x, Frac y) {
    Frac d = x - y;
    return d.a >= 0;
}
bool operator ==(Frac x, Frac y) {
    return x.a == y.a && x.b == y.b;
}

using Loc = pair<Frac, Frac>;

Loc top(Loc A, Frac m) {
    // top = (x, 1)
    // 1 = A.y + t * m;
    // x = A.x + t
    Frac t = (Frac(1) - A.second) / m;
    Frac x = A.first + t;
    if(Frac(-1) <= x && x <= Frac(1)) {
        return make_pair(x, Frac(1));
    }

    return make_pair(Frac(0), Frac(0));
}
Loc bottom(Loc A, Frac m) {
    // bottom = (x, -1)
    // -1 = A.y + t * m;
    // x = A.x + t
    Frac t = (Frac(-1) - A.second) / m;
    Frac x = A.first + t;
    if(Frac(-1) <= x && x <= Frac(1)) {
        return make_pair(x, Frac(-1));
    }

    return make_pair(Frac(0), Frac(0));
}
Loc left(Loc A, Frac m) {
    // left = (-1, y)
    // -1 = A.x + t
    // y = A.y + t * m;
    Frac t = (Frac(-1) - A.first);
    Frac y = A.second + t * m;
    if(Frac(-1) <= y && y <= Frac(1)) {
        return make_pair(Frac(-1), y);
    }

    return make_pair(Frac(0), Frac(0));
}
Loc right(Loc A, Frac m) {
    // right = (1, y)
    // 1 = A.x + t
    // y = A.y + t * m
    Frac t = (Frac(1) - A.first);
    Frac y = A.second + t * m;
    if(Frac(-1) <= y && y <= Frac(1)) {
        return make_pair(Frac(1), y);
    }

    return make_pair(Frac(0), Frac(0));
}

void print(Loc start) {
    cout << start.first.a << " " << start.first.b << " " << start.second.a << " " << start.second.b << "\n";
}

int main() {
    int a, b, n;
    cin >> a >> b >> n;
    Frac m(a, b);
    Loc start = make_pair(Frac(-1), Frac(0));
    Loc impossible = make_pair(Frac(0), Frac(0));
    int side = 0;
    for(int i = 0; i <= n; i++) {
        // print(start);
        // cout << m.a << " " << m.b << " is slope\n";
        if(side != 1 && top(start, m) != impossible) {
            side = 1;
            start = top(start, m);
            m.a *= -1;
            // cout << "top\n";
            continue;
        }
        if(side != 3 && bottom(start, m) != impossible) {
            side = 3;
            start = bottom(start, m);
            m.a *= -1;
            // cout << "bottom\n";
            continue;
        }
        if(side != 0 && left(start, m) != impossible) {
            side = 0;
            start = left(start, m);
            m.a *= -1;
            // cout << "left\n";
            continue;
        }
        if(side != 2 && right(start, m) != impossible) {
            side = 2;
            start = right(start, m);
            m.a *= -1;
            // cout << "right\n";
            continue;
        }
    }
    print(start);

    return 0;
}

/* stuff you should look for
    * int overflow, array bounds
    * special cases (n=1?)
    * do smth instead of nothing and stay organized
    * WRITE STUFF DOWN
    * DON'T GET STUCK ON ONE APPROACH
*/

