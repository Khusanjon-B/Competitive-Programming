// Problem: Codeforces 279B - Books
// Link: https://codeforces.com/problemset/problem/279/B
// Topics: Two Pointers, Sliding Window
// Time Complexity: O(n)
// Space Complexity: O(n)

#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    long long t;
    cin >> n >> t;

    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    long long sum = 0;
    int left = 0, best = 0;
    for (int right = 0; right < n; right++) {
        sum += a[right];
        while (sum > t) {
            sum -= a[left];
            left++;
        }
        best = max(best, right - left + 1);
    }

    cout << best << "\n";
}