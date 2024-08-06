// You are given a string word containing lowercase English letters. Telephone keypads have keys mapped with distinct collections of lowercase English letters, which can be used to form words by pushing them. It is allowed to remap the keys numbered 2 to 9 to distinct collections of letters. The keys can be remapped to any amount of letters, but each letter must be mapped to exactly one key. You need to find the minimum number of times the keys will be pushed to type the string word. Return the minimum number of pushes needed to type word after remapping the keys. Note that 1, *, #, and 0 do not map to any letters.






#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumPushes(string word) {
        int freq[26] = {0};

        for(auto i : word) freq[i - 'a']++;
        sort(freq,freq + 26);

        int size = 25,ans = 0;
        for(;size >= 0 && freq[size] != 0;size--){
            ans += freq[size] * (((25 - size) / 8) + 1);
        }
        return ans;
    }
};

int main(){
    Solution solve;

    string word = "abcde";
    cout<<solve.minimumPushes(word)<<endl;

    // 2nd
    word = "xyzxyzxyzxyz";
    cout<<solve.minimumPushes(word)<<endl;

    // 3rd
    word = "aabbccddeeffgghhiiiiii";
    cout<<solve.minimumPushes(word)<<endl;
}