// Problem: CSES - Palindrome Reorder
// Link: https://cses.fi/problemset/task/1755
// Topics: Strings, Greedy, Frequency Counting
// Time Complexity: O(N)
// Space Complexity: O(N)

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {

    int letters[26] = {0};
    string left = "";
    char c;

    while (cin >> c) {
        letters[c - 'A']++;
    }

    int numOdd = 0;
    int indexOdd;

    for (int i = 0; i < 26; i++) {
        if (letters[i] % 2 == 1) {
            numOdd++;
            if (numOdd > 1) {
                break;
            }
            indexOdd = i;
        } else {
            left += string(letters[i] / 2, 'A' + i);
        }
    }

    if (numOdd > 1) {
        cout << "NO SOLUTION\n";
    } else {
        string middle = "";
        if (numOdd == 1) {
            middle = string(letters[indexOdd], 'A' + indexOdd);
        }
        string right = left;
        reverse(right.begin(),right.end());
        string ans = left + middle + right;
        cout << ans << "\n";
    }

}