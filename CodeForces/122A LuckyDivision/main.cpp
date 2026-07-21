// Problem: Codeforces 122A - Lucky Division
// Link: https://codeforces.com/problemset/problem/122/A
// Topics: Brute Force, Number Theory, Implementation
// Time Complexity: O(digits + K) where K is number of precomputed lucky numbers
// Space Complexity: O(1)

#include <bits/stdc++.h>
using namespace std;

int main () {
    vector<int> nums = {4, 7, 47, 74, 44, 77, 444, 447, 474, 744, 774, 477, 747, 777};
    string numString;
    cin >> numString;

    int track = 0;
    for (int i = 0; i < numString.size(); i++) {
        if(numString[i] == '4' || numString[i] == '7') {
            continue;
        } else {
            track++;
        }
    }

    if (track == 0) {
        cout << "YES" << endl;
    } else {
        track = 0;
        for (int i = 0; i < nums.size(); i++){
            if (stoi(numString) % nums[i] == 0) {
                track++;
            }
        }
        if (track > 0) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
}