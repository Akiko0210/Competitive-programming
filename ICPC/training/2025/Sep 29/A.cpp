#include <bits/stdc++.h>

using namespace std;

int main() {
    int x, y;
    cin >> x >> y;
    int val = min(x, y);
    int ans = val * 10;
    y -= val;
    x -= val;
    ans += x / 3 * 10;
    x %= 3;
    ans += x / 2 * 3;
    x %= 2;
    ans += x;
    cout << ans << "\n";
    return 0;
}