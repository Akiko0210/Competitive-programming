#include <bits/stdc++.h>

using namespace std;

int main() {
    string s;
    cin >> s;
    set<char> unique;
    for(char c : s) {
        unique.insert(c);
    }

    cout << (unique.size() == s.size()) << "\n";
    return 0;

}