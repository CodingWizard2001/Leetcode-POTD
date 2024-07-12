// You are given a string s and two integers x and y. You can perform two types of operations any number of times.

// 1.  Remove substring "ab" and gain x points.

// 2.  Remove substring "ba" and gain y points.

// Return the maximum points you can gain after applying the above operations on s.




#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maximumGain(string s, int x, int y) {
        return x > y ? gain(s,"ab",x,"ba",y) : gain(s,"ba",y,"ab",x);
    }

    private:
    int gain(const string& s,const string& sub1, int point1, const string& sub2,
    int point2){
        int points = 0;
        vector<char>stack1;
        vector<char>stack2;
        for(const char c : s){
            if (!stack1.empty() && stack1.back() == sub1[0] && c == sub1[1]) {
                stack1.pop_back();
                points += point1;
            }
            else stack1.push_back(c);
        }

        for (const char c : stack1){
            if (!stack2.empty() && stack2.back() == sub2[0] && c == sub2[1]) {
                stack2.pop_back();
                points += point2;
            }
            else  stack2.push_back(c);
        }

        return points;
    }
};

int main(){
    Solution solution;
    int result = solution.maximumGain("cdbcbbaaabab",4,5);
    cout<<result<<endl; // Output: 19

    result = solution.maximumGain("aabbaaxybbaabb",5,4);
    cout<<result<<endl; // Output: 20
}