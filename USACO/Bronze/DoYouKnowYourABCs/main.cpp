// Problem: USACO 2020 December Contest, Bronze - Problem 1. Do You Know Your ABCs?
// Link: http://www.usaco.org/index.page?page=viewproblem2&cpid=1059
// Topics: Math, Sorting, Greedy
// Time Complexity: O(1)
// Space Complexity: O(1)

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    long long a, b, c;
    vector<long long> nums(7);

    for (int i = 0; i < 7; i++) {
        cin >> nums[i];

    }
    sort(nums.begin(), nums.end());
    a = nums[0];
    b = nums[1];
    c = nums[6] - a - b;

    cout << a <<  " " << b << " " << c << "\n";
}