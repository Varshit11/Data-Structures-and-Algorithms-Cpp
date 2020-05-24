/* C++ program to find Max Dot Product of Two Subsequences
Problem Statement - https://leetcode.com/problems/max-dot-product-of-two-subsequences/
*/

#include<bits/stdc++.h>
using namespace std;

int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
    if(nums1.size() == 0 || nums2.size() == 0) return 0;
    int mat[nums1.size()][nums2.size()];
    mat[0][0] = nums1[0]*nums2[0];
    for(int i = 1; i<nums1.size(); i++) mat[i][0] = max(nums1[i]*nums2[0], mat[i-1][0]);
    for(int i = 1; i<nums2.size(); i++) mat[0][i] = max(nums1[0]*nums2[i], mat[0][i-1]);
    for(int i = 1; i<nums1.size(); i++){
        for(int j = 1; j<nums2.size(); j++){
            int temp = nums1[i]*nums2[j];
            mat[i][j] = max(max(temp + mat[i-1][j-1], temp), max(mat[i-1][j], mat[i][j-1]));
        }
    }
    return mat[nums1.size()-1][nums2.size()-1];
}

int main(){
	// code passed all test cases on leetcode, one test case is shown here for demonstration
	vector<int> nums1 = {2,1,-2,5};
	vector<int> nums2 = {3,0,-6};
	cout<<"The maximum dot product of 2 subsequences is "<<maxDotProduct(nums1, nums2)<<endl;
	return 0;
}

