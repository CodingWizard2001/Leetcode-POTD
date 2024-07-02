// Given an integer array arr, return true if there are three consecutive odd numbers in the array. Otherwise, return false.
 

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        bool flag = false;
        int n = arr.size();
        for(int i = 0;i < (n - 2);i++){
            if(arr[i] % 2 != 0 && arr[i + 1] % 2 != 0 && arr[i + 2] % 2 != 0) flag = true;
        }
        return flag;
    }
};

int main(){
    Solution solve;
    
    vector<int>arr = {2,6,4,1};
    if(solve.threeConsecutiveOdds(arr)) cout<<"false"<<endl;
    else cout<<"true"<<endl;

    arr = {1,2,34,3,4,5,7,23,12};
    if(solve.threeConsecutiveOdds(arr)) cout<<"false"<<endl;
    else cout<<"true"<<endl;
}