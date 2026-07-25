// Problem: USACO 2016 December Contest, Bronze - Problem 3. The Cow-Signal
// Link: http://www.usaco.org/index.php?page=viewproblem2&cpid=665
// Topics: Simulation, String Manipulation
// Time Complexity: O(M * N * K)
// Space Complexity: O(N * K)

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    // Redirect stdin and stdout to USACO files
    freopen("cowsignal.in", "r", stdin);
    freopen("cowsignal.out", "w", stdout);

    int m, n, k;

    cin >> m >> n >> k;

    for (int i = 0; i < m; i++) {
        string s;
        string out = "";
        cin >> s;
        for (int p = 0; p < s.length(); p++) {
            out += string(k, s[p]);
        }   
        for (int j = 0; j < k; j++) {
            cout << out << endl;
        }
    }
}