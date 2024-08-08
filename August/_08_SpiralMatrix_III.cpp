// You start at the cell (rStart, cStart) of an rows x cols grid facing east. The northwest corner is at the first row and column in the grid, and the southeast corner is at the last row and column. You will walk in a clockwise spiral shape to visit every position in this grid. Whenever you move outside the grid's boundary, we continue our walk outside the grid (but may return to the grid boundary later.). Eventually, we reach all rows * cols spaces of the grid. Return an array of coordinates representing the positions of the grid in the order you visited them.




#include<bits/stdc++.h>
using namespace std;

class Solution {
 public:
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart,int cStart) {
        const vector<int> dx{1, 0, -1, 0};
        const vector<int> dy{0, 1, 0, -1};
        vector<vector<int>> ans{{rStart, cStart}};

        for (int i = 0; ans.size() < rows * cols; ++i)
        for (int step = 0; step < i / 2 + 1; ++step) {
            rStart += dy[i % 4];
            cStart += dx[i % 4];
            if (0 <= rStart && rStart < rows && 0 <= cStart && cStart < cols) ans.push_back({rStart, cStart});
        }

        return ans;
    }
};

int main(){
    int rows, cols, rStart,cStart;
    
    cout<<"Enter rows: ";
    cin>>rows;
    
    cout<<"Enter columns : ";
    cin>>cols;
    
    cout<<"Enter row start : ";
    cin>>rStart;

    cout<<"Enter columns start : ";
    cin>>cStart;

    Solution solve;
    vector<vector<int>> result = solve.spiralMatrixIII(rows,cols,rStart,cStart);

    for(int i = 0;i < result.size();i++){
        for(int j = 0;j < result[i].size();j++){
            cout<<result[i][j]<<" ";
        }
        cout<<endl;
    }
}