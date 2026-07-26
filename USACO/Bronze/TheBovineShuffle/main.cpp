// Problem: USACO 2017 December Contest, Bronze - Problem 2. The Bovine Shuffle
// Link: http://www.usaco.org/index.php?page=viewproblem2&cpid=760
// Topics: Simulation, Array Manipulation / Permutation Inversion
// Time Complexity: O(N)
// Space Complexity: O(N)

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // Redirect stdin and stdout to USACO files
    freopen("shuffle.in", "r", stdin);
    freopen("shuffle.out", "w", stdout);

    long long n;
    cin >> n;
    vector<long long> shuffles;
    long long s;
    // Read in
    for (int i = 0; i< n; i++){
        cin >> s;
        shuffles.push_back(s);
    }
    vector<long long> pos(n,0);
    for (int i = 0; i < n; i++){
        cin >> pos[i];
    }

    // Shuffle 
    for (int i = 0; i < 3; i++) {
        vector<long long> temp = pos;
        for (int j = 0; j < n; j++) {
            pos[j] = temp[shuffles[j]-1];
        }
    }
    for (long long num : pos) {
        cout << num << "\n";
    }

}