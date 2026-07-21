// Problem: Codeforces 230A - Dragons
// Link: https://codeforces.com/problemset/problem/230/A
// Topics: Greedy, Sorting, Data Structures (Map)
// Time Complexity: O(N log N)
// Space Complexity: O(N)

#include <bits/stdc++.h>
using namespace std;

int main(){
    int s, n;
    cin >> s >> n;
    map<int, vector<int>> dragons;
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        dragons[x].push_back(y);
    }

    int c = 0;
    for (auto d : dragons){
        if(d.first >= s) {
            cout << "NO" << endl;
            c = 1;
            break;
        } else {
            for(int i = 0; i < d.second.size(); i++){
                s += d.second[i];
            }
        }
    }
    if (c == 0) cout << "YES" << endl;
}