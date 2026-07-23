// Problem: Codeforces 546A - Soldier and Bananas
// Link: https://codeforces.com/problemset/problem/546/A
// Topics: Math, Implementation
// Time Complexity: O(1)
// Space Complexity: O(1)

#include <iostream>

using namespace std;

int main() {
    long long k, w, n;
    cin >> k >> n >> w;
    long long totalCost = (k * w * w  + k * w) / 2;
    long long pay = totalCost - n;
    if (pay <= 0) {
        cout << 0 << "\n";
    } else {
        cout << pay << "\n";
    }

}