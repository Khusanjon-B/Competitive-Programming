// Problem: USACO 2016 February Contest, Bronze - Problem 1. Milk Pails
// Link: http://www.usaco.org/index.php?page=viewproblem1&cpid=615
// Topics: Complete Search / Brute Force
// Time Complexity: O(M / Y) -> At most ~1000 operations
// Space Complexity: O(1)

#include <iostream>
#include <fstream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // Redirect stdin and stdout to USACO files
    freopen("pails.in", "r", stdin);
    freopen("pails.out", "w", stdout);

    int x, y, m;
    cin >> x >> y >> m;

    int maxMilk = 0;
    for (int i = 0; i <= (m/y); i++) {
        int xFills = (m - i * y) / x;
        int tempMilk = (i*y + xFills * x);
        maxMilk = max(maxMilk, tempMilk);
    }
    cout << maxMilk << "\n";
}