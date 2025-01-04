#include <bits/stdc++.h>

using namespace std;

int main () {
    int n, d;
    cin >> n >> d;
    vector<string> s(d);
    int mx_streak = 0, cur_streak = 0;
    for(int i = 0; i < d; i++) {
        cin >> s[i];
        bool winning = true;
        string t(n, '1');
        if(t == s[i]) 
            winning = false;
        
        if(winning) {
            cur_streak++;
        } else {
            cur_streak = 0;
        }

        mx_streak = max(mx_streak, cur_streak);
    }
    cout << mx_streak << "\n";


    return 0;
}