// Problem: CSES - Repetitions
// Link: https://cses.fi/problemset/task/1069
// Topics: Strings, Two Pointers, Implementation
// Time Complexity: O(N)
// Space Complexity: O(1)

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n = 0;
    int maxRep = 1;
    char newL = ' ';
    char oldL = ' ';
    while (cin >> newL) {
        if (n == 0) n=1;
        if (newL == oldL) {
            n++;
        } else {
            n = 1;
        }
        maxRep = max(n, maxRep);
        oldL = newL;
    }
    cout << maxRep << endl;
}