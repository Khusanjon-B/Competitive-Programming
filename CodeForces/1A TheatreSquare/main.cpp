// Problem: Codeforces 1A - Theatre Square
// Link: https://codeforces.com/problemset/problem/1/A
// Topics: Math, Basic Geometry
// Time Complexity: O(1)
// Space Complexity: O(1)

#include <bits/stdc++.h>
using namespace std;

int main() {
    unsigned long long n, m, a;
    cin >> n >> m >> a;
    unsigned long long sum = ceil((1.0 * n)/a) * ceil((1.0 * m)/a);
    cout << sum << endl;
}