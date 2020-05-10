/* C+ program to find number of unique Binary search trees which can be made from numbers 1...N
Problem Statement - https://leetcode.com/problems/unique-binary-search-trees/
*/

#include<iostream>
using namespace std;

int numTrees(int n) {
    int m[n+1];
    m[0] = 1;
    m[1] = 1;
    for(int i = 2; i<=n;i++){
        m[i] = 0;
        for(int j = 1; j<=i; j++) m[i]+= m[j-1]*m[i-j];
    }
    return m[n];
}

int main(){
	// code passed all test cases on leetcode, one test case is shown here for demonstration
	int n = 3;
	cout<<"The number of unique binary search trees which can be constructed from number 1 to 3 are "<<numTrees(3)<<endl;
	return 0;
}
