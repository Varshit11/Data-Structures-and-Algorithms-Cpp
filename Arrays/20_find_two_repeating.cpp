/* C++ program to Find 2 repeating elements in an array. The elements will be from
1 to N and the array size will be N+2, so there are 2 repeating elements.
*/

#include<iostream>
#include<vector>
using namespace std;

void find_two_repeating(vector<int> &nums){
	int x1 = 0, x2 = 0, i, k = 0;
	for(i=0;i<nums.size();i++)
		x1^= nums[i]; // x1 will store xor of all the elements in array
	for(i=1;i<=nums.size()-2;i++)
		x2^= i; // x2 will store xor of 1 to N
	x1^= x2; // x1 now will store xor of the repeating elements
	
	while(1){ // finding the first bit where the 2 repeating elements are different
	// since the xor will never be 0, we will break from the loop
		if(x1>>k & 1) break;
		else k++;
	}
	
	x2 = 0;
	for(i=1;i<=nums.size()-2;i++)
		if(i>>k & 1) x2^= i; // x2 will contain xor of elements with kth bit set
	for(i=0;i<nums.size();i++)
		if(nums[i]>>k & 1) x2^= nums[i]; // x2 will now contain one of the repeating element
	
	x1^= x2; // x1 will contain the second repeating element
	cout<<"The 2 repeating elements in the array are "<<x1<<" and "<<x2<<endl;
}

int main(){
	vector<int> nums = {2,4,3,1,2,5,4};
	find_two_repeating(nums);
	return 0;
}

