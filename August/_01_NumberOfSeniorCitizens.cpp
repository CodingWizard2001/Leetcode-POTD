// You are given a 0-indexed array of strings details. Each element of details provides information about a given passenger compressed into a string of length 15. The system is such that:

// 1.   The first ten characters consist of the phone number of passengers.
// 2.   The next character denotes the gender of the person.
// 3.   The following two characters are used to indicate the age of the person.
// 4.   The last two characters determine the seat allotted to that person.

// Return the number of passengers who are strictly more than 60 years old.




#include<bits/stdc++.h>
using namespace std;

 int countSeniors(vector<string>& details) {
    int ans = 0;
    for(auto i : details){
        int temp = stoi(i.substr(11,2));
        if(temp > 60) ans++;
    }
    return ans;
}

int main(){
    vector<string> details = {"7868190130M7522","5303914400F9211","9273338290F4010"};

    cout<<"No. of senior citizens : "<<countSeniors(details)<<endl;
}