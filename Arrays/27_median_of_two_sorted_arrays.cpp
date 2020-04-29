/* C++ program to find median of 2 sorted arrays.
Problem Statement - https://leetcode.com/problems/median-of-two-sorted-arrays/
*/

#include<bits/stdc++.h>
using namespace std;

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    int min_index = 0, max_index = min(nums1.size(), nums2.size()), i, j, median;
    // assume nums1 has the minimum size
    if(max_index == nums2.size()){
        vector<int> temp = nums1;
        nums1 = nums2;
        nums2 = temp;
    }
    while(min_index<= max_index){
        i = (min_index+max_index)/2;
        j = (nums1.size() + nums2.size() + 1)/2 - i;
        if(j<0){
            max_index = i;
            continue;
        }
        if(i<nums1.size() && j>0 && nums1[i] < nums2[j-1])
            min_index = i+1;
        else if(i > 0 && j<nums2.size() && nums1[i-1] > nums2[j])
            max_index = i-1;
        else{
            if(i == 0)
                median = nums2[j-1];
            else if(j == 0)
                median = nums1[i-1];
            else
                median = max(nums1[i-1], nums2[j-1]);
            break;
        }
    }
    if((nums1.size() + nums2.size())%2 == 1)
        return (double)median;
    if(i == nums1.size())
        return (median + nums2[j])/2.0;
    if(j == nums2.size())
        return (median + nums1[i])/2.0;
    return (median + min(nums1[i], nums2[j]))/2.0;
}

int main(){
	// code passed all test cases on leetcode, one test case is shown here for demonstration
	vector<int> nums1 = {900};
	vector<int> nums2 = {10,13,14};
	double ans = findMedianSortedArrays(nums1, nums2);
	cout<<"The median of 2 sorted arrays is "<<ans<<endl;
	return 0;
}

