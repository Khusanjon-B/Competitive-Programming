// Problem: Codeforces 520B - Two Buttons
// Link: https://codeforces.com/problemset/problem/520/B
// Topics: Greedy, Math (reverse simulation); also solvable with BFS
// Time Complexity: O(log m)
// Space Complexity: O(1)

#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    int presses = 0;
    while (m > n) {
        if (m % 2 == 1) m++;   // reverse of blue: odd can't be halved, so go up 1
        else m /= 2;           // reverse of red
        presses++;
    }
    presses += n - m;          // now m <= n: only blue presses remain
    cout << presses << "\n";
}