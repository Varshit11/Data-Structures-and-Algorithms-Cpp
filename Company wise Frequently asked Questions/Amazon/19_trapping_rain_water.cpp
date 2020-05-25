/* C++ program to solve trapping rain water problem
Problem Statement - https://leetcode.com/problems/trapping-rain-water/
*/

#include<bits/stdc++.h>
using namespace std;

int trap(vector<int>& height) {
    int ans = 0, cur_index = 0;
    stack<int> st;
    while(cur_index < height.size()){
        while(!st.empty() && height[cur_index] > height[st.top()]){
            int top = st.top();
            st.pop();
            if(st.empty()) break;
            ans+= (min(height[st.top()], height[cur_index]) - height[top])*(cur_index - st.top()-1);
        }
        st.push(cur_index++);
    }
    return ans;
}

int main(){
	vector<int> height = {0,1,0,2,1,0,1,3,2,1,2,1};
	cout<<"The water which can be trapped is "<<trap(height)<<endl;
	return 0;
}
