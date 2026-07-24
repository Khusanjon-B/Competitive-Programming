// Problem: USACO 2019 January Contest, Bronze - Problem 1. Shell Game
// Link: http://www.usaco.org/index.php?page=viewproblem2&cpid=891
// Topics: Simulation, Arrays
// Time Complexity: O(N)
// Space Complexity: O(1)

#include <iostream>
#include <fstream>

using namespace std;

int main() {
    // Redirect stdin and stdout to USACO files
    freopen("shell.in", "r", stdin);
    freopen("shell.out", "w", stdout);

    int n;
    cin >> n;
    
    int shells[3] = {0, 0, 0};
    int pos[3] = {1, 2, 3};
    for (int i = 0; i < n; i++) {
        int a, b, g;
        int temp;
        cin >> a >> b >> g;
        temp = pos[a-1];
        pos[a-1] = pos[b-1];
        pos[b-1] = temp;
        shells[pos[g-1]-1]++;
    }
    cout << max(shells[0], max(shells[1], shells[2])) << "\n";

}