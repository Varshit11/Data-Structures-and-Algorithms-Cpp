/* C++ program to find the maximum size rectangle binary matrix with all 1s
Problem statement - https://www.geeksforgeeks.org/maximum-size-rectangle-binary-sub-matrix-1s/
*/

#include<iostream>
#include<stack>
#include<vector>
using namespace std;

int find_area_hist(vector<int> &v){
	int max_area = INT_MIN, i = 0;
	stack<int> s;
	while(i<v.size()){
		if(s.empty() || v[s.top()]<=v[i]) s.push(i++);
		else{
			int temp = s.top();
			s.pop();
			int cur_area = v[temp]*(s.empty()?i:i-s.top()-1);
			max_area = max(max_area, cur_area);
		}
	}
	while(!s.empty()){
		int temp = s.top();
		s.pop();
		int cur_area = v[temp]*(s.empty()?i:i-s.top()-1);
		max_area = max(max_area, cur_area);
	}
	return max_area;
}

int max_size_rectangle(vector<vector<int>> mat){
	int max_size = INT_MIN;
	for(int i = 1; i<mat.size(); i++){
		for(int j = 0; j<mat[i].size(); j++) if(mat[i][j] == 1) mat[i][j] += mat[i-1][j];
		max_size = max(max_size, find_area_hist(mat[i]));
	}
	return max_size;
}

int main(){
	vector<vector<int>> mat = {{0,1,1,0}, {1,1,1,1}, {1,1,1,1}, {1,1,0,0}};
	cout<<"The maximum size rectangle binary matrix with all 1s is "<<max_size_rectangle(mat)<<endl;
	return 0;
}

