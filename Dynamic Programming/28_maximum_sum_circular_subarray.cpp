/* C++ program to solve Maximum Sum Circular Subarray problem
Problem Statement - https://leetcode.com/problems/maximum-sum-circular-subarray/
*/

#include<iostream>
#include<vector>
using namespace std;

int kadane(vector<int> &A){
    int max_sum = A[0], max_cur = A[0];
    for(int i = 1; i<A.size(); i++){
        max_cur = max(A[i], A[i]+max_cur);
        max_sum = max(max_cur, max_sum);
    }
    return max_sum;
}
    
int maxSubarraySumCircular(vector<int>& A) {
    int k1 = kadane(A), sum_A = 0;
    for(int i = 0; i<A.size(); i++){
        sum_A+= A[i];
        A[i]*= -1;
    }
    sum_A += kadane(A);
    if(sum_A > k1 && sum_A != 0) return sum_A;
    else return k1;
}

int main(){
	vector<int> A = {3,-2,2, -3};
	cout<<"The maximum sum circular sub array is "<<maxSubarraySumCircular(A)<<endl;
	return 0;
}

