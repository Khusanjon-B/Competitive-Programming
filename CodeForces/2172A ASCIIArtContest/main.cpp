// Problem: Codeforces 2172A - Score Variance Check
// Topics: Implementation, Vectors
// Time Complexity: O(1)
// Space Complexity: O(1)

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int max(vector<int> nums) {
    int num = nums[0];
    for (int i : nums) {
        if (i > num) num = i;
    }
    return num;
}

int min(vector<int> nums) {
    int num = nums[0];
    for (int i : nums) {
        if (i < num) num = i;
    }
    return num;
}

int main()
{
    int g, c, l;
    cin >> g >> c >> l;
    vector<int> nums = { g, c, l };
    if ((max(nums) - min(nums)) >= 10) {
        cout << "check again" << endl;
    }
    else {
        remove(nums.begin(), nums.end(), max(nums));
        remove(nums.begin(), nums.end(), min(nums));
        cout << "final " << nums[0] << endl;
    }
}