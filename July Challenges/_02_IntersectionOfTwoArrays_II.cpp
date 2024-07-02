// Given two integer arrays nums1 and nums2, return an array of their intersection. Each element in the result must appear as many times as it shows in both arrays and you may return the result in any order.


#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());

        vector<int> ans;
        int i = 0;  // nums1's index
        int j = 0;  // nums2's index

        while (i < nums1.size() && j < nums2.size())
            if (nums1[i] < nums2[j]) ++i;
            else if (nums1[i] > nums2[j]) ++j;
            else {
                ans.push_back(nums1[i]);
                ++i;
                ++j;
            }
        return ans;
    }
};

int main(){
    Solution solve;
    
    vector<int>nums1 = {1,2,2,1};
    vector<int>nums2 = {2,2};

    vector<int>result = solve.intersect(nums1,nums2);
    for(int i = 0;i < result.size();i++) cout<<result[i]<<" ";

    cout<<endl;
    nums1 = {4,9,5};
    nums2 = {9,4,9,8,4};

    result = solve.intersect(nums1,nums2);
    for(int i = 0;i < result.size();i++) cout<<result[i]<<" ";
}