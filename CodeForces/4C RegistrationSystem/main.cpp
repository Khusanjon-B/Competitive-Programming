// Problem: Codeforces 4C - Registration System
// Link: https://codeforces.com/problemset/problem/4/C
// Topics: Hashing, Hash Maps, Implementation
// Time Complexity: O(n * L)
// Space Complexity: O(n * L)

#include <iostream>
#include <unordered_set>
#include <string>
#include <unordered_map>

using namespace std;



int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    unordered_set<string> names = {};
    unordered_map<string, int> nameCount = {};
    for (int i = 0; i < n; i++){
        string s;
        cin >> s;
        if (names.insert(s).second){
            cout << "OK" << "\n";
            nameCount[s] = 1;
        } else {
            nameCount[s]++;
            cout << s+to_string(nameCount[s] - 1) << "\n";

        }

    }

}