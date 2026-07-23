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