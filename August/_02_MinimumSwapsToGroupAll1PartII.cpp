// A swap is defined as taking two distinct positions in an array and swapping the values in them.

// A circular array is defined as an array where we consider the first element and the last element to be adjacent.

// Given a binary circular array nums, return the minimum number of swaps required to group all 1's present in the array together at any location.





#include <iostream>
#include <vector>
#include <numeric> // For accumulate
#include <algorithm> // For max

using namespace std;

class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int k = accumulate(nums.begin(), nums.end(), 0);
        int n = nums.size();

        int cnt = accumulate(nums.begin(), nums.begin() + k, 0);
        int mx = cnt;
    
        for (int i = k; i < n + k; ++i) {
            cnt += nums[i % n] - nums[(i - k + n) % n];
            mx = max(mx, cnt);
        }
        
        return k - mx;
    }
};

int main() {
    vector<int> nums = {1, 0, 1, 0, 1, 0, 0, 1, 1, 0};
    
    Solution solution;
    int result = solution.minSwaps(nums);
    cout << "Minimum number of swaps required: " << result << endl;
    
    return 0;
}