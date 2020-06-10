/* C++ program to solve Maximize Sum Of Array After K Negations problem
Problem Statement - https://leetcode.com/problems/maximize-sum-of-array-after-k-negations/
*/

#include<bits/stdc++.h>
using namespace std;

// there are 2 solutions, the first one used priority queue and the code runs in O(NlogN) time
int largestSumAfterKNegations(vector<int>& A, int K) { // O(NlogN)
    priority_queue<int, vector<int>, greater<int>> pq;
    for(int i = 0; i<A.size(); i++) pq.push(A[i]);
    int i = 1, temp, ans = 0;
    while(i<=K){
        temp = pq.top();
        pq.pop();
        temp *= -1;
        pq.push(temp);
        ++i;
    }
    while(!pq.empty()){
        ans+= pq.top();
        pq.pop();
    }
    return ans;
}

// the below code is more efficient than the first and time complexity is O(N) time
int largestSumAfterKNegations_efficient(vector<int>& A, int K) { // O(N)
    sort(A.begin(), A.end());
    if(A[0]>=0){
        if(K%2 != 0) A[0]*= -1;
    }
    else{
        int h = 0;
        while(h<A.size() && A[h]<0 && K>0){
            A[h]*= -1;
            --K;
            ++h;
        }
        if(h==A.size() && K>0){
            if(K%2 != 0) A[h-1] *= -1;
        }
        else{
            if(K%2 != 0){
                if(A[h] < A[h-1]) A[h]*= -1;
                else A[h-1] *= -1;
            }
        }
    }
        
    return accumulate(A.begin(), A.end(), 0);
}

int main(){
	// code passed all test cases on leetcode, one test case is shown here for demonstration
	vector<int> A = {2,-3,-1,5,-4};
	int K = 2;
	cout<<largestSumAfterKNegations_efficient(A, K)<<endl;
	return 0;
}

