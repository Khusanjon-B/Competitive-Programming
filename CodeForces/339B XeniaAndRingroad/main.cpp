// Problem: Codeforces 339B - Xenia and Ringroad
// Link: https://codeforces.com/problemset/problem/339/B
// Topics: Math, Implementation
// Time Complexity: O(M)
// Space Complexity: O(1)

#include <bits/stdc++.h>
using namespace std;

int main(){
    long long n, m, sum = 0, current = 1;
    cin >> n >> m;
    for (int i = 0; i < m; i++){
        int house;
        cin >> house;
        if (current <= house) {
            sum += house - current;
        } else {
            sum += n - current + house;
        }
        current = house;
    }
    cout << sum << endl;
}