// You are given two integer arrays of equal length target and arr. In one step, you can select any non-empty subarray of arr and reverse it. You are allowed to make any number of steps. Return true if you can make arr equal to target or false otherwise.




#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {

        // 1st Approach
        // sort(target.begin(),target.end());
        // sort(arr.begin(),arr.end());
        // return target == arr;

        // 2nd Approach
        return is_permutation(arr.begin(),arr.end(),target.begin()); 
    }
};

int main(){
    vector<int>arr = {1,2,3,4};
    vector<int>target = {2,1,4,3};

    Solution solve;
    if(solve.canBeEqual(target,arr)) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;

    arr = {7,9,11};
    target = {3,7,9};
    if(solve.canBeEqual(target,arr)) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
}