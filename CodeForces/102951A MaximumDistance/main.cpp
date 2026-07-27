// Problem: Codeforces Gym 102951A - Maximum Distance
// Link: https://codeforces.com/gym/102951/problem/A
// Topics: Basic Complete Search / Brute Force, Geometry
// Time Complexity: O(N^2)
// Space Complexity: O(N)

#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>


using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<long long> x;
    vector<long long> y;
    for (int i = 0; i < n; i++) {
        long long xin;
        cin >> xin;
        x.push_back(xin);
    }
    for (int i = 0; i < n; i++) {
        long long yin;
        cin >> yin;
        y.push_back(yin);
    }
    long long maxDist = 0;
    for (int i = 0; i < n-1; i++) {
        for (int j = 1; j < n; j++) {
            long long dist = pow(x[i]-x[j],2) + pow(y[i]-y[j],2);
            maxDist = max(maxDist, dist);
        }
    }
    cout << maxDist << "\n";
}