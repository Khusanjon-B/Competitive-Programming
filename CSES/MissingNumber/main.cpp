// Problem: CSES - Missing Number
// Link: https://cses.fi/problemset/task/1083
// Topics: Math, Implementation, Bit Manipulation
// Time Complexity: O(N)
// Space Complexity: O(1)

#include <iostream>
using namespace std;

int main() {
    long long n;
    cin >> n;

    long long exp = n * (n + 1) / 2;
    long long act = 0;

    for (int i = 0; i < n - 1; i++) {
        long long num;
        cin >> num;
        act += num;
    }

    cout << exp - act << endl;

}