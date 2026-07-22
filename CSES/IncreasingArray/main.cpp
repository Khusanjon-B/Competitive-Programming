// Problem: CSES - Increasing Array
// Link: https://cses.fi/problemset/task/1094
// Topics: Greedy, Implementation
// Time Complexity: O(N)
// Space Complexity: O(1)

#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    long long moves = 0;
    long long lastnum;

    for (int i = 0; i < n; i++) {
        long long num;
        cin >> num;
        if (i == 0){
            lastnum = num;;
        } else {
            if (lastnum > num) {
                moves += lastnum - num;
            } else {
                lastnum = num;
            }
        }
    }
    cout << moves << endl;
}