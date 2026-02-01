#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    sort(a.begin(), a.end());
    vector<int> b(n);
    for(int i = 1, j = 0, k = 0; i <= 2 * n; i++) {
        if(j < n && i == a[j]) {
            j++;
            continue;
        }

        b[k] = i;
        k++;
    }

    int mx = 0, mn = n;
    for(int i = 0, j = 0; i < n; i++) {
        if(a[i] > b[j]) {
            mx ++;
            j++;
        }
    }

    for(int i = 0, j = 0; i < n; i++) {
        if(b[i] > a[j]) {
            mn--;
            j++;
        }
    }

    cout << mn << " " << mx << "\n";



    return 0;
}