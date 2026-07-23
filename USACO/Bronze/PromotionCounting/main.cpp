// Problem: USACO 2016 January Contest, Bronze - Problem 1. Promotion Counting
// Link: http://usaco.org/index.php?page=viewproblem2&cpid=591
// Topics: Math, Flow / Conservation Logic
// Time Complexity: O(1)
// Space Complexity: O(1)

#include <iostream>
#include <fstream> 
#include <cmath>

using namespace std;

int main() {

        // Redirect stdin and stdout to USACO files
    freopen("promote.in", "r", stdin);
    freopen("promote.out", "w", stdout);

    int pbefore, pafter, gbefore, gafter, sbefore, safter, bbefore, bafter;
    
    cin >> bbefore >> bafter >> sbefore >> safter >> gbefore >> gafter >> pbefore >> pafter;

    cout << (safter + ((gafter + (pafter - pbefore)) - gbefore)) - sbefore << "\n";

    cout << (gafter + (pafter - pbefore)) - gbefore << "\n";

    cout << pafter - pbefore << "\n";
}