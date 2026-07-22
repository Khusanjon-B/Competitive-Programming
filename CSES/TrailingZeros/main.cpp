// Problem: CSES - Trailing Zeros
// Link: https://cses.fi/problemset/task/1618
// Topics: Math, Number Theory
// Time Complexity: O(log_5(N))
// Space Complexity: O(1)

#include <iostream>

using namespace std;

int main() {
    long long n;
    cin >> n;
    int ans = 0;
    while (n > 0) {
        ans += n/5;
        n /= 5;
    }
    cout << ans << "\n";
}
