// Problem: USACO 2015 December Contest, Bronze - Problem 2. Speeding Ticket
// Link: http://www.usaco.org/index.php?page=viewproblem2&cpid=568
// Topics: Simulation, Array Flattening / Unrolling
// Time Complexity: O(N + M) or O(1) since total miles = 100
// Space Complexity: O(1) - fixed 100-element array

#include <iostream>
#include <fstream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // Redirect stdin and stdout to USACO files
    freopen("speeding.in", "r", stdin);
    freopen("speeding.out", "w", stdout);

    int n, m;
    cin >> n >> m;
    int roadSpeed[100];
    int mile = 0;
    for (int i = 0; i < n; i++) {
        int l, s;
        cin >> l >> s;
        for (int j = 0; j < l; j++) {
            roadSpeed[mile] = s;
            mile++;
        }
    }
    int fastest = 0;

    mile = 0;
    for (int i = 0; i < m; i++) {
        int l, s;
        cin >> l >> s;
        for (int j = 0; j < l; j++) {
            fastest = max(fastest, s - roadSpeed[mile]);
            mile++;
        }
    }
    cout << fastest << endl;

    
}