// There is a restaurant with a single chef. You are given an array customers, where customers[i] = [arrivali, timei]:

// 1.  arrivali is the arrival time of the ith customer. The arrival times are sorted in non-decreasing order.
// 2.  timei is the time needed to prepare the order of the ith customer.

// When a customer arrives, he gives the chef his order, and the chef starts preparing it once he is idle. The customer waits till the chef finishes preparing his order. The chef does not prepare food for more than one customer at a time. The chef prepares food for customers in the order they were given in the input. Return the average waiting time of all customers. Solutions within 10-5 from the actual answer are considered accepted.




#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        double wait = 0,curr = 0;

        for(vector<int>&c : customers){
            curr = max(curr, 1.0 * c[0]) + c[1];
            wait += curr - c[0];
        }

        return (1.0) * wait / customers.size();
    }
};

int main() {
    Solution sol;
    vector<vector<int>> customers1 = {{1, 2}, {2, 5}, {4, 3}};

    double result1 = sol.averageWaitingTime(customers1);

    cout << "Average waiting time for customers1: " << result1 << endl;  // Output: 5.0
}