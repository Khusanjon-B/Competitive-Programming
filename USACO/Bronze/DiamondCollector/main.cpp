// Problem: USACO 2016 Open Contest, Bronze - Problem 1. Diamond Collector
// Link: http://www.usaco.org/index.php?page=viewproblem1&cpid=639
// Topics: Complete Search / Brute Force
// Time Complexity: O(N^2)
// Space Complexity: O(N)

#include <iostream>
#include <fstream>
#include <vector>
// #include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // Redirect stdin and stdout to USACO files
    freopen("diamond.in", "r", stdin);
    freopen("diamond.out", "w", stdout);

    int n, k;
    cin >> n >> k;
    
    vector<int> diamonds;
    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        diamonds.push_back(num);
    }
    int maxDiam = 0;
    for (int i = 0; i < n; i++) {
        int counter = 0;
        for (int d : diamonds) {
            if (d-diamonds[i] <= k && d >= diamonds[i]) {
                counter++;
            }
        }
        maxDiam = max(counter, maxDiam);
    }
    cout << maxDiam << "\n";
}