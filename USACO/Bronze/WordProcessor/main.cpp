// Problem: USACO 2020 January Contest, Bronze - Problem 1. Word Processor
// Link: http://www.usaco.org/index.php?page=viewproblem2&cpid=987
// Topics: Simulation, Strings, Implementation
// Time Complexity: O(N)
// Space Complexity: O(1)

#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

int main() {

    // Redirect stdin and stdout to USACO files
    freopen("word.in", "r", stdin);
    freopen("word.out", "w", stdout);

    int n, k;
    cin >> n >> k;

    vector<string> sentences;

    int currCount = 0;

    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        if (sentences.empty()) {
            sentences.push_back(s);
            currCount = s.length();
        } else if (currCount + s.length() <= k) {
            sentences[sentences.size() - 1] += (" " + s);
            currCount += s.length();
        } else {
            sentences.push_back(s);
            currCount = s.length();
        }
    }
    for (int i = 0; i < sentences.size(); i++) {
        cout << sentences[i] << "\n";
    }

}