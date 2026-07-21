// Problem: Codeforces 2171A - Legs
// Topics: Math, Linear Equations
// Time Complexity: O(S) per query
// Space Complexity: O(1)

#include <bits/stdc++.h>
using namespace std;

void legs(int s){
    int result = 0;
    for (int x = 0; x <= (s/4); x++){
        if (int((-1 * x/2 + s/2)) >= 0) result++;
    }
    cout << result << endl;
}

int main(){
    int n;
    cin >> n;
    for (int i = 0; i < n; i++){
        int s;
        cin >> s;
        if (s % 2 != 0) {
            cout << 0 << endl;
            continue;
        }
        legs(s);
    }
}