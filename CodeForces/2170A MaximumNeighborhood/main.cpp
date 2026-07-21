// Problem: Codeforces 2170A - Base Cases
// Topics: Math, Pattern Recognition
// Time Complexity: O(1) per query
// Space Complexity: O(1)

#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    unordered_map<int,int> baseCases;
    baseCases[1] = 1;
    baseCases[2] = 9;
    baseCases[3] = 29;
    baseCases[4] = 56;
    baseCases[5] = 95;

    for (int i = 0; i < t; i++) {
        int n;
        cin >> n;
        if (baseCases.count(n)){
            cout << baseCases[n] << endl;
        } else {
            int sum = 5*n*n - 5*n -5;
            cout << sum << endl;
        }
    }
}