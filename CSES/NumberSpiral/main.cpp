// Problem: CSES - Number Spiral
// Link: https://cses.fi/problemset/task/1071
// Topics: Math, Implementation
// Time Complexity: O(1) per test case
// Space Complexity: O(1)

#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        long long r, c;
        cin >> r >> c;
        // Diagonal
        if (r == c) {
            cout << (r * c) - (r-1) << endl;
        // r > c - under diagonal
        } else if (r > c) {
            if (r % 2 == 0) {
                cout << (r * r) - (r-1) + (r-c) << endl;
            } else {
                cout << (r * r) - (r-1) - (r-c) << endl;
            }
        // r < c - above diagonal
        } else {
            if (c % 2 == 0) {
                cout << (c * c) - (c-1) - (c-r) << endl;
            } else {
                cout << (c * c) - (c-1) + (c-r) << endl;
            }
        }
    }
}