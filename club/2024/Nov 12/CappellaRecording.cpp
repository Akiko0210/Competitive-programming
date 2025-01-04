#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, d;
    cin >> n >> d;
    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    sort(a.begin(), a.end());
    int ans = 1, l = a[0];
    for(int i = 0; i < n; i++) {
        if(a[i] - l > d) {
            l = a[i];
            ans++;
        }
    }
    cout << ans << "\n";
 
    return 0;
}