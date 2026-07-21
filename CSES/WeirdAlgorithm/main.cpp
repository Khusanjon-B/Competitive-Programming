// Problem: CSES - Weird Algorithm
// Link: https://cses.fi/problemset/task/1068
// Topics: Introductory Problems, Simulation, Collatz Conjecture
// Time Complexity: Dependent on Collatz sequence length
// Space Complexity: O(1)

#include <iostream>
using namespace std;

int main()
{
    long long n;
    cin >> n;
    
    while (n != 1) {
        if (n != 1) cout << n << " ";
        else cout << n << endl;
        if (n % 2 == 0) n /= 2;
        else n = 3 * n + 1;
    }
 
    cout << n << endl;
}