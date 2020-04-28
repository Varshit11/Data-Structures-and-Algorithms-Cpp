/* C++ program to find negative number in sorted matrix 
Problem Statement - https://leetcode.com/problems/count-negative-numbers-in-a-sorted-matrix/
*/

#include<bits/stdc++.h>
using namespace std;

int countNegatives(vector<vector<int>>& grid) {
    int count = 0, i = grid.size()-1, j = 0;
    while(i>=0){
        if(j > grid[0].size()-1) return count;
        else if(grid[i][j] >= 0) j++;
        else{
            count+= grid[0].size()-j;
            i--;
        }
    }
    return count;
}

int main(){
	// code passed all test cases on leetcode, one test case is shown here for demonstration
	vector<vector<int>> grid = {{4,3,2,-1}, {3,2,1,-1}, {1,1,-1,-2}, {-1,-1,-2,-3}};
	cout<<"The number of negatives in this sorted matrix is "<<countNegatives(grid)<<endl;
	return 0;
}

