// Problem: USACO 2018 December Contest, Bronze - Problem 2. The Bucket List
// Link: http://www.usaco.org/index.php?page=viewproblem2&cpid=856
// Topics: Simulation, Difference Array / Time Bucket Sweeping
// Time Complexity: O(N * Max_Time) -> O(100 * 1000)
// Space Complexity: O(Max_Time)

#include <iostream>
#include <fstream>
#include <vector>
#include <tuple>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // Redirect stdin and stdout to USACO files
    freopen("blist.in", "r", stdin);
    freopen("blist.out", "w", stdout);

    int n;
    cin >> n;

    vector<vector<int>> cows;
    int maxTime = 0;
    for (int i = 0; i < n; i++) {
        vector<int> c(3,0);
        cin >> c[0] >> c[1] >> c[2];
        maxTime = max(maxTime, c[1]);
        cows.push_back(c);
    }
    int totalBuckets = 0;
    int useBuckets = 0;
    for (int i = 0; i < maxTime; i++) {
        for (int j = 0; j < cows.size(); j++) {
            if (cows[j][0] == i) {
                int availableBuckets = totalBuckets - useBuckets;
                if ((availableBuckets) < cows[j][2]) {
                    totalBuckets += cows[j][2] - availableBuckets;
                    useBuckets += cows[j][2];
                } else {
                    useBuckets += cows[j][2];
                }
            } else if (cows[j][1] == i){
                useBuckets -= cows[j][2];
            }
        }
    }
    cout << totalBuckets << "\n";
}