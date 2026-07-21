// Problem: Codeforces 69A - Young Physicist
// Link: https://codeforces.com/problemset/problem/69/A
// Topics: Math, Implementation, Vector Geometry
// Time Complexity: O(N)
// Space Complexity: O(1)

#include <iostream>
using namespace std;

int main(){
    int n;
    cin >> n;
    int xsum = 0, ysum = 0, zsum = 0;
    for (int i = 0; i < n; i++){
        int x, y, z;
        cin >> x >> y >> z;
        xsum += x;
        ysum += y;
        zsum += z;
    }
    if (xsum == 0 && ysum == 0 && zsum == 0) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
}