/* C++ program to Count all possible paths in a Grid, using recursion and bottom up DP
Problem Statement - https://www.geeksforgeeks.org/count-possible-paths-top-left-bottom-right-nxm-matrix/
I have solved this using 2 approaches, both approaches recursive and bottom up DP code is written
*/

#include<iostream>
using namespace std;

int count_path_recursive(int m, int n){
	if(m-1 == 0 || n-1 == 0) return 1;
	else return count_path_recursive(m-1, n-1) + count_path_recursive(m, n-1) + count_path_recursive(m-1, n);
}

int count_path_recursive_2(int i, int j, int m, int n){
	if(i == n-1 && j == n-1) return 1;
	else if(i>n-1 || j > m-1) return 0;
	else return count_path_recursive_2(i+1, j+1, m, n) + count_path_recursive_2(i, j+1, m, n) + count_path_recursive_2(i+1, j, m,n);
}

int count_path_bottom_up(int m, int n){
	int table[m][n];
	table[0][0] = 1;
	int i, j;
	for(i=1;i<m;i++) table[i][0] = 1;
	for(i=1;i<n;i++) table[0][i] = 1;
	for(i=1;i<m;i++) for(j=1;j<n;j++) table[i][j] = table[i-1][j-1] + table[i-1][j] + table[i][j-1];
	return table[m-1][n-1];
}

int count_path_bottom_up_2(int m, int n){
	int table[m][n];
	table[m-1][n-1] = 1;
	int i, j;
	for(i=m-2;i>=0;i--) table[i][n-1] = 1;
	for(j=n-2;j>=0;j--) table[m-1][j] = 1;
	for(i=m-2; i>= 0; i--) for(j=n-2; j>=0; j--) table[i][j] = table[i+1][j+1] + table[i][j+1] + table[i+1][j];
	return table[0][0];
}

int main(){
	cout<<"Using recursion approach 1, the total number of paths in 3*3 matrix are "<<count_path_recursive(3,3)<<endl;
	cout<<"Using recursion approach 2, the total number of paths in 3*3 matrix are "<<count_path_recursive_2(0,0,3,3)<<endl;
	cout<<"Using Bottom up DP approach 1, The total number of paths in 3*3 matrix are "<<count_path_bottom_up(3,3)<<endl;
	cout<<"Using Bottom up DP approach 2, the total number of paths in 3*3 matrix are "<<count_path_bottom_up_2(3,3)<<endl;
	return 0;
}
