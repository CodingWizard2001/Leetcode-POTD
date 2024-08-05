// You are given the array nums consisting of n positive integers. You computed the sum of all non-empty continuous subarrays from the array and then sorted them in non-decreasing order, creating a new array of n * (n + 1) / 2 numbers. Return the sum of the numbers from index left to index right (indexed from 1), inclusive, in the new array. Since the answer can be a huge number return it modulo 109 + 7.





#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        int arr[n * (n + 1) / 2];

        for(int i = 0,k = 0;i < n;i++){
            int s = 0; 
            for(int j = i;j < n;j++){
               s += nums[j];
               arr[k++] = s;
            }
        }

        sort(arr,arr + n * (n + 1) / 2);
        int sum = 0;
        const int mod = 1e9 + 7;
        for(int i = (left - 1);i < right;i++){
            sum = (sum + arr[i]) % mod;
        }
        return sum;
    }
};


int main(){
    Solution solve;
    vector<int>nums = {1,2,3,4};
    int n = 4,left = 1,right = 5;

    cout<<solve.rangeSum(nums,n,left,right)<<endl;

    // 2nd
    nums = {1,2,3,4};
    n = 4,left = 3,right = 4;

    cout<<solve.rangeSum(nums,n,left,right)<<endl;
}