/* C++ program Find two Missing Numbers in a Sequence of Consecutive Numbers 
The numbers are in 1 to N and there will be 2 missing elements 
*/

#include<iostream>
#include<vector>
using namespace std;

void find_two_missing(vector<int> &nums){
	int i, x1 = 0, x2=0, k =0;
	for(i=1;i<=nums.size()+2;i++)
		x1^= i;
	for(i=0;i<nums.size();i++)
		x2^=nums[i];
	x1^=x2; // x1 will be now xor of 2 missing elements
	
	while(1){ // there will always be 1 bit which will be set, so we will break out of loop
		if(x1>>k & 1) break;
		else k++;
	}
	// k will be the first bit in x1 which will be 1
	int num1 = 0;
	for(i=1;i<=nums.size()+2;i++)
		if(i>>k & 1) num1^=i;
	for(i=0;i<nums.size();i++)
		if(nums[i]>>k & 1) num1^=nums[i];
	
	cout<<"The first number is "<<num1<<endl;
	num1^= x1;
	cout<<"The second number is "<<num1<<endl; 
}

int main(){
	vector<int> nums = {1,3,5,6};
	find_two_missing(nums);
	return 0;
}

