/* C++ program to sort array by parity 
Problem Statement - https://leetcode.com/problems/sort-array-by-parity/
*/

#include<iostream>
#include<vector>
using namespace std;

void swap(int* p, int* q){
    int temp = *p;
    *p = *q;
    *q = temp;
}
void sortArrayByParity(vector<int>& A) {
    int i = -1, j;
    for(j=0;j<A.size();j++){
        if(A[j]%2 == 0){
            i++;
            swap(&A[i], &A[j]);
        }
    }
}

int main(){
	// code passed all test cases on leetcode, one test case is shown here for demonstration
	vector<int> A = {3,1,2,4};
	sortArrayByParity(A);
	for(int i = 0; i<A.size(); i++)
		cout<<A[i]<<" ";
	return 0;
}

