/* C++ program to find the K closest points to the origin 
Problem statement - https://leetcode.com/problems/k-closest-points-to-origin/
*/

#include<iostream>
#include<vector>
using namespace std;

int find_dist(vector<int> &a){
    return a[0]*a[0] + a[1]*a[1];
}
    
void swap(vector<vector<int>> &ans, int i, int j){
    vector<int> temp = ans[i];
    ans[i] = ans[j];
    ans[j] = temp;
}
    
void max_heapify(vector<vector<int>>& ans, int largest, int N){
    int left = 2*largest+1;
    int right = 2*largest+2;
    int m = largest;
    if(left<N && find_dist(ans[left]) > find_dist(ans[m]))
        m = left;
    if(right<N && find_dist(ans[right]) > find_dist(ans[m]))
        m = right;
    if(m == largest)
        return;
    else{
        swap(ans, m, largest);
        max_heapify(ans, m, N);
    }
}
    
void build_max_heap(vector<vector<int>>& ans){
    for(int i = ans.size()/2-1; i>=0;i--)
        max_heapify(ans, i, ans.size());
}
    
vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
    vector<vector<int>> ans(points.begin(), points.begin()+K);
    build_max_heap(ans);
    for(int i = K; i<points.size(); i++){
            
        if(find_dist(points[i]) < find_dist(ans[0])){
            ans[0] = points[i];
            max_heapify(ans, 0, ans.size());
        }
    }
    return ans;
}

int main(){
	// the above code is already tested on leetcode, passed all test cases, here for the sake
	// of demonstration, I will take one test case */
	vector <vector<int>> points{{3,3},
								{5,-1},
								{-2,4}};
	vector<vector<int>> ans = kClosest(points, 2);
	for(int i = 0; i<ans.size(); i++){
		for(int j = 0; j<ans[i].size(); j++)
			cout<<ans[i][j]<<" ";
		cout<<endl;
	}
	return 0;
}

