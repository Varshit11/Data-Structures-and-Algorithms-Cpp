/* C++ program to solve Queue Reconstruction by Height problem
Problem Statement - https://leetcode.com/problems/queue-reconstruction-by-height/
*/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool sort_cond(vector<int> &v1, vector<int>& v2){
    if(v1[0] == v2[0]) return v1[1] < v2[1];
    else return v1[0] > v2[0];
}
    
vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
    vector<vector<int>> ans;
    sort(people.begin(), people.end(), sort_cond);
    for(int i = 0; i<people.size(); i++){
        ans.insert(ans.begin()+people[i][1], people[i]);
    }
    return ans;
}

int main(){
	// code passed all test cases on leetcode, one test case is shown here for demonstration.
	vector<vector<int>> people = {{7,0}, {4,4}, {7,1}, {5,0}, {6,1}, {5,2}};
	vector<vector<int>> ans = reconstructQueue(people);
	for(int i = 0; i<ans.size(); i++){
		for(int j = 0; j<ans[i].size(); j++)
			cout<<ans[i][j]<<" ";
		cout<<endl;
	}
	return 0;
}

