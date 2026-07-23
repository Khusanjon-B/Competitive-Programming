// Problem: Codeforces A - Team
// Link: https://codeforces.com/problemset/problem/231/A
// Topics: Implementation, Counting, Elementary Logic
// Time Complexity: O(n)
// Space Complexity: O(1)

#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    int count = 0;
    for (int i = 0; i < n; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        if (a+b+c > 1) count++;
    }
    cout << count << "\n";

}