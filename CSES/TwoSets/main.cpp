// Problem: CSES - Two Sets
// Link: https://cses.fi/problemset/task/1092
// Topics: Constructive Algorithms, Greedy, Math
// Time Complexity: O(N)
// Space Complexity: O(N)

#include <iostream>
#include <vector>

using namespace std;

int main() {

    int n;
    cin >> n;

    long long A = 0, B = 0;
    vector<int> a = {}, b = {};

    for (int i = n; i > 0; i--) {
        if (A > B) {
            b.push_back(i);
            B += i;
        } else {
            a.push_back(i);
            A += i;
        }
    }
    if (A == B) {
        cout << "YES\n";
        cout << a.size() << "\n";
        for (long long num : a) {
            cout << num << " ";
        }
        cout << "\n" << b.size() << "\n";
        for (long long num : b) {
            cout << num << " ";
        }
    } else {
        cout << "NO\n";
    }

}