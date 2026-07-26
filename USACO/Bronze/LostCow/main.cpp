// Problem: USACO 2017 US Open Contest, Bronze - Problem 1. The Lost Cow
// Link: http://www.usaco.org/index.php?page=viewproblem2&cpid=735
// Topics: Simulation, Number Line Walk
// Time Complexity: O(log(X-Y))
// Space Complexity: O(1)

#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // Redirect stdin and stdout to USACO files
    freopen("lostcow.in", "r", stdin);
    freopen("lostcow.out", "w", stdout);

    int x, y;
    cin >> x >> y;

    // total dist
    int dist = 0;
    // starting position
    int pos = x;
    // exponent counter to keep track of direction
    int i = 0;
    while (pos != y) {
        // get each consecutive search limit with correct direction
        int gotox = x + int(pow(-2, i)) ;
        // iterate each step from curr pos until reach end of limit or reach y;
        int curr = pos;
        for (int j = 0; j < abs(curr - gotox); j++) {
            // increments by 1 for each step, with correct direction, if even moving right
            pos += int(pow(-1, i));
            dist++;
            if (pos == y) {
                break;
            }
        }
        i++;
    }
    cout << dist << endl;
}