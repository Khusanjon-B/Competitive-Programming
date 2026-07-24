#include <iostream>
#include <fstream>

using namespace std;

int main() {
    // Redirect stdin and stdout to USACO files
    freopen("mixmilk.in", "r", stdin);
    freopen("mixmilk.out", "w", stdout);

    // <capacity, amount of milk>
    pair<long long, long long> buckets[3];
    for (int i = 0; i < 3; i++) {
        cin >> buckets[i].first >> buckets[i].second;
    }
    
    for (int i = 0; i < 100; i++) {
        int curr = i % 3;
        int next = (i+1) % 3;
        int available = buckets[curr].second;
        int addable = buckets[next].first - buckets[next].second;
        if (available >= addable) {
            int dmilk = min(available , addable);
            buckets[next].second += dmilk;
            buckets[curr].second -= dmilk;
        } else {
            buckets[next].second += available;
            buckets[curr].second -= available;
        }
    }
    cout << buckets[0].second << "\n";
    cout << buckets[1].second << "\n";
    cout << buckets[2].second << "\n";
}