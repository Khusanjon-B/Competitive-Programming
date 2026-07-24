// Problem: USACO 2019 Open Contest, Bronze - Problem 1. Bucket Brigade
// Link: http://www.usaco.org/index.php?page=viewproblem2&cpid=938
// Topics: Geometry, Grid, Manhattan Distance
// Time Complexity: O(1) - 10x10 Grid
// Space Complexity: O(1)

#include <iostream>
#include <fstream>

using namespace std;

int main() {
    // Redirect stdin and stdout to USACO files
    freopen("buckets.in", "r", stdin);
    freopen("buckets.out", "w", stdout);

    int Bx, By;
    int Rx, Ry;
    int Lx, Ly;
    for (int i = 0; i < 10; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < s.length(); j++) {
            switch (s[j]){
                case 'B':
                    Bx = i;
                    By = j;
                    break;
                case 'R':
                    Rx = i;
                    Ry = j;
                    break;
                case 'L':
                    Lx = i;
                    Ly = j;
                    break;
            }
        }
    }
    if ((Bx == Rx && Rx == Lx && ((By < Ry && Ry < Ly) || (Ly < Ry && Ry < By))) || (By == Ry && Ry == Ly && ((Bx < Rx && Rx < Lx) || (Lx < Rx && Rx < Bx))) ) {
        cout << abs(Bx-Lx) + abs(By - Ly) - 1 + 2 << "\n";
    } else {
        cout << abs(Bx-Lx) + abs(By - Ly) - 1 << "\n";
    }
}