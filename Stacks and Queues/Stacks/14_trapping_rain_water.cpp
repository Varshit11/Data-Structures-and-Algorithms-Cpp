/* C++ program to solve trapping rain water problem. 
The problem statement can be found on 
https://leetcode.com/problems/trapping-rain-water/
*/

#include<bits/stdc++.h>
#include<vector>
using namespace std;

stack <int> s;

int trap(vector<int>& height){
	int count = 0, d, i = 0;
	while(i<height.size()){
		if(s.empty() || height[s.top()] > height[i])
			s.push(i++);
		else{
			d = s.top();
			s.pop();
			if(height[d] != height[i]){
				if(!s.empty())
					count+=(min(height[s.top()],height[i]) - height[d])*(i-s.top()-1);
			}
		}
	}
	return count;
}

int main(){
	int N, i, num;
	cout<<"Enter no. of elevation maps"<<endl;
	cin>>N;
	vector <int> height;
	cout<<"Enter the heights"<<endl;
	for(i=0;i<N;i++){
		cin>>num;
		height.push_back(num);
	}
	int ans = trap(height);
	cout<<"It will be able to trap "<<ans<<" units of water"<<endl;
	return 0;
}
