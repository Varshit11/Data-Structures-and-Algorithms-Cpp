/* C++ program to merge intervals
*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
 
bool sortcol( const vector<int>& v1, const vector<int>& v2 ) { 
    return v1[0] < v2[0]; 
 
}
 
vector<vector<int>> merge(vector<vector<int>>& intervals) {
    if(intervals.size() == 0 || intervals.size() == 1)
        return intervals;
 
    sort(intervals.begin(), intervals.end(), sortcol);
    int i, j = 0;
    vector<vector<int>> ans;
    ans.push_back(intervals[0]);
    for(i=1;i<intervals.size();i++){
        if(intervals[i][0] <= ans[j][1])
            ans[j][1] = max(intervals[i][1], ans[j][1]);
        else{
            ans.push_back(intervals[i]);
            j++;
        }
    }
    return ans;
}
 
int main(){
	vector<vector<int>> intervals = {{1,3}, {2,6}, {8,10}, {15,18}};
	vector<vector<int>> ans = merge(intervals);
	for(int i = 0; i<ans.size(); i++){
		for(int j = 0; j<ans[i].size(); j++)
			cout<<ans[i][j]<<" ";
		cout<<endl;
	}
	return 0;
}
