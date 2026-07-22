// Problem: CSES - Two Knights
// Link: https://cses.fi/problemset/task/1072
// Topics: Math, Combinatorics, Geometry
// Time Complexity: O(N)
// Space Complexity: O(1)

#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    for (long long i = 1; i <= n; i++) {
        // Total number of positions
        long long tot = i * i * (i * i - 1) / 2;
        // Attacking positions
        long long rects = 2 * (i-2) * (i-1);
        cout << tot - 2 * rects << endl;
    }


}