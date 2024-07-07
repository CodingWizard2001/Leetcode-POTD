// There are numBottles water bottles that are initially full of water. You can exchange numExchange empty water bottles from the market with one full water bottle. The operation of drinking a full water bottle turns it into an empty bottle. Given the two integers numBottles and numExchange, return the maximum number of water bottles you can drink.

 

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        return numBottles + (numBottles - 1) / (numExchange - 1);
    }
};

int main(){
    Solution solve;
    
    int numBottles = 15,numExchange = 4;
    cout<<"The maximum number of water bottles will be : "<<solve.numWaterBottles(numBottles,numExchange)<<endl;

    numBottles = 9,numExchange = 3;
    cout<<"The maximum number of water bottles will be : "<<solve.numWaterBottles(numBottles,numExchange)<<endl;
}