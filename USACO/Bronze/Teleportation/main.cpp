// Problem: USACO 2018 February Contest, Bronze - Problem 1. Teleportation
// Link: http://www.usaco.org/index.php?page=viewproblem2&cpid=807
// Topics: Math, Greedy, Geometry (1D)
// Time Complexity: O(1)
// Space Complexity: O(1)

#include <iostream>
#include <fstream> 
#include <cmath>

using namespace std;

int main() {

    // Redirect stdin and stdout to USACO files
    freopen("teleport.in", "r", stdin);
    freopen("teleport.out", "w", stdout);

    // start, end, telx, tely
    int a, b, x, y;
    cin >> a >> b >> x >> y;
    int rawDist = abs(b-a);
    int telDistx = abs(x-a) + abs(y-b);
    int telDisty = abs(y-a) + abs(x-b);
    ofstream outFile("teleport.out");
    cout << min(rawDist, min(telDistx, telDisty)) << "\n";

}