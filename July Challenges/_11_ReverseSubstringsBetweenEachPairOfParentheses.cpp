// You are given a string s that consists of lower case English letters and brackets. Reverse the strings in each pair of matching parentheses, starting from the innermost one. Your result should not contain any brackets.




#include <iostream>
#include <string>
#include <stack>
#include <unordered_map>
using namespace std;

class Solution {
public:
    string reverseParentheses(string s) {
        int n = s.length();
        string ans;
        stack<int> stack;
        unordered_map<int, int> pair;

        // Find all pairs of parentheses
        for (int i = 0; i < n; i++) {
            if (s[i] == '(') stack.push(i);
            else if (s[i] == ')') {
                const int j = stack.top();
                stack.pop();
                pair[i] = j;
                pair[j] = i;
            }
        }

        // Traverse the string and reverse the substrings within parentheses
        for (int i = 0, d = 1; i < s.length(); i += d) {
            if (s[i] == '(' || s[i] == ')') {
                i = pair[i];
                d = -d;
            } else {
                ans += s[i];
            }
        }
        return ans;
    }
};

int main() {
    Solution sol;

    string s1 = "(abcd)";
    string s2 = "(u(love)i)";
    string s3 = "(ed(et(oc))el)";
    string s4 = "a(bcdefghijkl(mno)p)q";

    string result1 = sol.reverseParentheses(s1);
    string result2 = sol.reverseParentheses(s2);
    string result3 = sol.reverseParentheses(s3);
    string result4 = sol.reverseParentheses(s4);

    cout << "Reversed string for s1: " << result1 << endl;  // Output: "dcba"
    cout << "Reversed string for s2: " << result2 << endl;  // Output: "iloveu"
    cout << "Reversed string for s3: " << result3 << endl;  // Output: "leetcode"
    cout << "Reversed string for s4: " << result4 << endl;  // Output: "apmnolkjihgfedcbq"
}