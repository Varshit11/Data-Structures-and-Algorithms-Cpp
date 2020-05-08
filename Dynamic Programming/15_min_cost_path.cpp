/* C++ program to Minimum Cost path Problem
*/

#include<iostream>
#include<vector>
using namespace std;

int min_cost_path_recursion(vector<vector<int>> &mat, int m, int n){ // m for rows and n for columns
	if(m == mat.size()-1 && n == mat[0].size()-1) return mat[m][n];
	else if(m >= mat.size() || n >= mat[0].size()) return 999;
	else return min(mat[m][n] + min_cost_path_recursion(mat, m+1, n), mat[m][n] + min_cost_path_recursion(mat, m, n+1)); 
}

int min_cost_path_bottom_up(vector<vector<int>> &mat){
	int m = mat.size(), n = mat[0].size(), i, j;
	vector<vector<int>> temp(mat);
	for(i=m-2; i>=0; i--) temp[i][n-1] = mat[i][n-1] + temp[i+1][n-1];
	for(j=n-2; j>=0; j--) temp[m-1][j] = temp[m-1][j+1] + mat[m-1][j];
	for(i=m-2; i>=0; i--) for(j=n-2; j>=0; j--) temp[i][j] = min(mat[i][j] + temp[i+1][j], mat[i][j] + temp[i][j+1]);
	return temp[0][0];
}

int main(){
	vector<vector<int>> mat = {{2,1,5,1},
								{3,4,2,2},
								{1,2,3,3},
								{1,3,2,4}};
	cout<<"Using recursion the min cost is "<<min_cost_path_recursion(mat, 0, 0)<<endl;
	cout<<"Using bottom up DP the min cost is "<<min_cost_path_bottom_up(mat)<<endl;
	return 0;
}

