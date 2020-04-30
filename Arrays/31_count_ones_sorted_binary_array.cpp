/* C++ program to Count 1’s in a sorted binary array
Problem Statement - https://www.geeksforgeeks.org/count-1s-sorted-binary-array/
*/

#include<iostream>
#include<vector>
using namespace std;

int c = 0;

void count_ones(vector<int> &nums, int low, int high){
	while(high>=low){
		int mid = (low+high)/2;
		if(nums[mid] == 1) {
			c = mid+1;
			low = mid+1;
		}
		else high = mid-1;
	}
}

int main(){
	vector<int> nums = {1,1,1,1,0,0,0};
	count_ones(nums, 0, nums.size()-1);
	cout<<"The number of ones in the array are "<<c<<endl;
}

