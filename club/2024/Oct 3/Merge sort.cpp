#include <bits/stdc++.h>

using namespace std;

vector<int> conquer(vector<int> a, vector<int> b) {
    int inda = 0, indb = 0;
    vector<int> c;
    while(inda < a.size() && indb < b.size()) {
        if(a[inda] < b[indb]) {
            c.push_back(a[inda]);
            inda++;
        } else {
            c.push_back(b[indb]);
            indb++;
        }
    }

    while(inda < a.size()) {
        c.push_back(a[inda]);
        inda++;
    }

    while(indb < b.size()) {
        c.push_back(b[indb]);
        indb++;
    }
    return c;
}

void divide(vector<int>& arr, int l, int r) {
    if(l == r) {
        return;
    }

    int m = (l + r) / 2;

    divide(arr, l, m);
    divide(arr, m + 1, r);

    vector<int> a, b, c;
    for(int i = l; i <= r; i++) {
        if(i <= m) a.push_back(arr[i]);
        else b.push_back(arr[i]);
    }

    c = conquer(a, b);
    for(int i = l; i <= r; i++) 
        arr[i] = c[i - l];
    
}

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for(int &x : a) {
        cin >> x;
    }

    divide(a, 0, n - 1);

    for(int x : a) {
        cout << x << " ";
    }
    cout << "\n";

    return 0;
}