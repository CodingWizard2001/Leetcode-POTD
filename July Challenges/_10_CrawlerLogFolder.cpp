// The Leetcode file system keeps a log each time some user performs a change folder operation. The operations are described below:

// 1.  "../" : Move to the parent folder of the current folder. (If you are already in the main folder, remain in the same folder).

// 2.  "./" : Remain in the same folder.

// 3.  "x/" : Move to the child folder named x (This folder is guaranteed to always exist).

// You are given a list of strings logs where logs[i] is the operation performed by the user at the ith step. The file system starts in the main folder, then the operations in logs are performed. Return the minimum number of operations needed to go back to the main folder after the change folder operations.



#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int minOperations(vector<string>& logs) {
        int count = 0;
        int n = logs.size();
        for (int i = 0; i < n; i++) {
            if (logs[i] == "../") {
                if (count > 0) count--;
            } else if (logs[i] == "./") {
                continue;
            } else {
                count++;
            }
        }
        return count;
    }
};

int main() {
    Solution sol;
    vector<string> logs1 = {"d1/", "d2/", "../", "d21/", "./"};
    vector<string> logs2 = {"d1/", "d2/", "./", "d3/", "../", "d31/"};
    vector<string> logs3 = {"d1/", "../", "../", "../"};

    int result1 = sol.minOperations(logs1);
    int result2 = sol.minOperations(logs2);
    int result3 = sol.minOperations(logs3);

    cout<<"Minimum operations for logs1: "<<result1 <<endl;  // Output: 2
    cout<<"Minimum operations for logs2: "<<result2<< endl;  // Output: 3
    cout<<"Minimum operations for logs3: "<<result3<< endl;  // Output: 0
}