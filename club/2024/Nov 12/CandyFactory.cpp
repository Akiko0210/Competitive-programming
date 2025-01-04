#include <bits/stdc++.h>
#define ll long long 
using namespace std;

int main() {
    ll n, k, mx = 0, sum = 0;

    cin >> n >> k;
    vector<ll> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        mx = max(mx, a[i]);
        sum += a[i];
    }


    if(sum > mx * k) {
        ll rem = sum % k;

        if(rem == 0) {
            cout << "0\n";
        } else {
            cout << k - rem << "\n";
        }
        return 0;
    }

    cout << mx * k - sum << "\n";
    return 0;
}