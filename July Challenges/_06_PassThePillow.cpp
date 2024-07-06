// There are n people standing in a line labeled from 1 to n. The first person in the line is holding a pillow initially. Every second, the person holding the pillow passes it to the next person standing in the line. Once the pillow reaches the end of the line, the direction changes, and people continue passing the pillow in the opposite direction. Given the two positive integers n and time, return the index of the person holding the pillow after time seconds.



#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int passThePillow(int n, int time) {
        time %= (n - 1) * 2;
        if(time < n) return (1 + time);
        return n - (time - (n - 1)); // Backward
    }
};

int main(){
    Solution solve;
    
    int n = 4,time = 5;
    cout<<solve.passThePillow(n,time)<<endl;

    n = 3,time = 2;
    cout<<solve.passThePillow(n,time)<<endl;
}