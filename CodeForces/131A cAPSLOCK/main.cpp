// Problem: Codeforces 131A - cAPS lOCK
// Link: https://codeforces.com/problemset/problem/131/A
// Topics: Strings, Implementation
// Time Complexity: O(N)
// Space Complexity: O(N)

#include <bits/stdc++.h>
using namespace std;

int main() {
    string s, r;
    cin >> s;
    int onlyUpper = 0, onlyFirst = 0;

    for (int i = 0; i < s.size(); i++) {
        if (isupper(s[i])) {
            onlyUpper++;
            if (i != 0) onlyFirst++;
        } else {
            if(i == 0) onlyFirst++;
        }
    }

    if (onlyFirst == s.size() || onlyUpper == s.size()){
        for (int i = 0; i < s.size(); i++) {
            if(isupper(s[i])){
                r += tolower(s[i]);
            } else {
                r += toupper(s[i]);
            }
        }
        cout << r << endl;
        return 0;
    }
    cout << s << endl;
}