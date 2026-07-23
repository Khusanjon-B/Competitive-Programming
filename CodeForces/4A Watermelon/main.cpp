// Problem: Codeforces 4A - Watermelon
// Link: https://codeforces.com/problemset/problem/4/A
// Topics: Math, Elementary Logic
// Time Complexity: O(1)
// Space Complexity: O(1)

#include <iostream>

using namespace std;

int main() {
    int w;
    cin >> w;
    if ((w-2) % 2 == 0 && (w > 2)) {
        cout << "YES" << "\n"; 
    } else {
        cout << "NO" << "\n";
    }
}