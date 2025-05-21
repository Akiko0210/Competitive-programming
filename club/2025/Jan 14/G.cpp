#include <iostream>

using namespace std;

int main() {
    string s;
    cin >> s;
    int cntupper = 0, cntlower = 0;
    for(char c : s) {
        if(islower(c)) {
            cntlower++;
        } else {
            cntupper++;
        }
    }
    for(int i = 0; i < s.size(); i++) {
        if(cntlower >= cntupper) {
            s[i] = tolower(s[i]);
        } else {
            s[i] = toupper(s[i]);
        }
    }
    cout << s << "\n";



    return 0;
}