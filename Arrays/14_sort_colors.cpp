/* C++ program to solve the sort colors problems, given an array of only 0, 1 and 2, you have
to sort them in ascending order using only 1 pass. */

#include<iostream>
#include<vector>
using namespace std;

void swap(int* p, int* q){
	int temp = *p;
	*p = *q;
	*q = temp;
}

void sort(vector<int> &nums){
	int c = 0, l = 0, h = nums.size()-1;
	while(c < h){
		if(nums[c] == 0){
			swap(&nums[c], &nums[l]);
			c++;
			l++;
		}
		else if(nums[c] == 1) c++;
		else{
			swap(&nums[c], &nums[h]);
			h--;
		}
	}
}

int main(){
	vector<int> nums = {0,1,0,1,2,1,2,1};
	sort(nums);
	cout<<"The sorted array is "<<endl;
	for(int i = 0;i<nums.size();i++)
		cout<<nums[i]<<" ";
	return 0;
}

