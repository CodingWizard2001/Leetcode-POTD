// You are given an integer array nums. In one move, you can choose one element of nums and change it to any value. Return the minimum difference between the largest and smallest value of nums after performing at most three moves.


#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minDifference(vector<int>& nums) {
        int n = nums.size();
        if(n <= 4) return 0; 
        int ans = INT_MAX;

        // ranges::sort(nums);
        sort(nums.begin(),nums.end());
        for (int i = 0; i <= 3; ++i) ans = min(ans, nums[n - 4 + i] - nums[i]);

        return ans;
    }
};

int main(){
    Solution solve;
    
    vector<int>nums= {5,3,2,4};
    cout<<solve.minDifference(nums);

    cout<<endl;
    nums = {1,5,0,10,14};
    cout<<solve.minDifference(nums);
}