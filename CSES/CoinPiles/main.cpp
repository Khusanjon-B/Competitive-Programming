// Problem: CSES - Coin Piles
// Link: https://cses.fi/problemset/task/1754
// Topics: Math, Invariants
// Time Complexity: O(1) per testcase

#include <iostream>
using namespace std;

int main() {

    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        long long a, b;
        cin >> a >> b;


        if ((a + b) % 3 == 0 && a <= 2 * b && b <= 2 * a){
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
}
