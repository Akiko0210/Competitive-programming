#include <iostream>

using namespace std;

int main() {
    // int a[100];
    // a[0], a[1], a[2] ... a[99]
    bool seen[26];
    // seen[0] is whether or not we've seen 'a'
    // seen[1] is whether or not we've seen 'b'
    for(int i = 0; i < 26; i++) {
        seen[i] = false;
    }
    string name;
    cin >> name; // "abc"

    // name[i] = {'a', 'b' .... 'z'}
    for(char c : name) {
        // c = 'a' = 97
        // c - 97 = 0
        seen[c - 97] = true; // seen[0] = true
    }

    int cnt = 0;
    for(int i = 0; i < 26; i++) {
        if(seen[i]) {
            cnt++;
        }
    }
    // cnt / 2 = 3 -> whole part.
    // cnt % 2 = 0 -> remainder.
    if(cnt % 2 == 0){
        cout << "CHAT WITH HER!" << endl;
    } else{
        cout << "IGNORE HIM!\n";
    }

    return 0;
}