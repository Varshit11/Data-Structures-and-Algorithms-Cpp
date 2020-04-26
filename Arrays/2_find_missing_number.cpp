/* C++ program to find the missing number in an array. The elements in an array are from
0 to N except one element, find this missing element. For ex. if input is [3,0,1] then
the output should return 2. */

#include<iostream>
#include<vector>
using namespace std;

int missingNumber(vector<int>& nums) {
    int v1 = 0, v2 = 0, i;
    for(i=0;i<nums.size();i++)
        v1^= nums[i];
    for(i=0;i<=nums.size();i++)
        v2^= i;
    return v1 ^ v2;
}

int main(){
	vector<int> nums = {9,6,4,2,3,5,7,0,1};
	cout<<"The missing number is "<<missingNumber(nums)<<endl;
	// you can add all the elements of the vector and subtract it from 
	// n*(n+1)/2, it will work, but imagine if n is very large, then n*(n+1)/2
	// can be above the limits of int and give errornous result, thats why bitwise
	// operators help, if we do xor of 2, 32 bit numbers, then the result will be 32 bit
	// number, we can't say the same if we add 2, 32 bit numbers. 
	return 0;
}
