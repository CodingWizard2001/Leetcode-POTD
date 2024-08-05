// A distinct string is a string that is present only once in an array. Given an array of strings arr, and an integer k, return the kth distinct string present in arr. If there are fewer than k distinct strings, return an empty string "".




#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        unordered_map<string,int>result;
        for(auto& i : arr) result[i]++;

        for(auto& i : arr){
            if(result[i] == 1){
                k--;
            }
            if(k == 0) return i;
        }
        return "";
    }
};

int main(){
    Solution solve;
    vector<string> arr = {"d","b","c","b","c","a"};
    int k = 2;

    cout<<solve.kthDistinct(arr,k)<<endl;

    // 2nd
    arr = {"aaa","aa","a"};
    k = 1;

    cout<<solve.kthDistinct(arr,k)<<endl;

    // 3rd
    arr = {"a","b","a"};
    k = 3;

    cout<<solve.kthDistinct(arr,k)<<endl;
}