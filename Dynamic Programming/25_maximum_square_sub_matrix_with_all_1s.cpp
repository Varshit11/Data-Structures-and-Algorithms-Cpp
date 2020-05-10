/* C++ program to find Maximum size square sub-matrix with all 1s
Problem Statement - https://www.geeksforgeeks.org/maximum-size-sub-matrix-with-all-1s-in-a-binary-matrix/
*/

#include<bits/stdc++.h>
using namespace std;

int min(int a, int b, int c){
	return a>b ? (b>c ? c : b) : (a>c ? c : a);
}

int find_max_size_square_sub_matrix(vector<vector<int>> &v){
	int m[v.size()][v[0].size()], max_size = INT_MIN;
	for(int i = 0; i<v.size();i++) m[i][0] = v[i][0];
	for(int j = 0; j<v[0].size(); j++) m[0][j] = v[0][j];
	for(int i = 1; i<v.size(); i++){
		for(int j = 1; j<v[0].size(); j++){
			if(v[i][j] == 1) m[i][j] = 1+ min(m[i-1][j-1], m[i-1][j], m[i][j-1]);
			else m[i][j] = 0;
			if(max_size < m[i][j]) max_size = m[i][j];
		}
	}
	return max_size;
}

int main(){
	vector<vector<int>> v = {{0,1,1,0,1}, {1,1,0,1,0}, {0,1,1,1,0}, {1,1,1,1,0}, {1,1,1,1,1}, {0,0,0,0,0}};
	cout<<"The maximum size square sub matrix with all 1s is "<<find_max_size_square_sub_matrix(v)<<endl;
	return 0;
}
