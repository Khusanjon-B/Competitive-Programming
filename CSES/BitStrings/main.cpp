// Problem: CSES - Bit Strings
// Link: https://cses.fi/problemset/task/1617
// Topics: Math, Modular Arithmetic
// Time Complexity: O(N)
// Space Complexity: O(1)

#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    long long val = 1;
    long long MOD = 1e9 + 7;
    for (int i = 0; i < n; i++) {
        val = val * 2 % MOD;
    }
    cout << val << "\n";
}