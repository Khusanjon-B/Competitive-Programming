#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    long long val = 1;
    long long MOD = 1e9 + 7;
    for (int i = 0; i < n; i++) {
        val = val * 2 % MOD;
    }
    cout << val << "\n";
}