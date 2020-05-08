/* C++ program to find Longest increasing subsequence in O(N*logN) time
We are not using DP here, with DP we can solve this problem in O(N^2) time.
*/

#include<iostream>
using namespace std;

int binary_search(int* arr, int left, int right, int num){
	while(right - left > 1){
		int middle = (right+left)/2;
		if(arr[middle] >= num) right = middle;
		else left = middle;
	}
	return right;
}

int LIS(int* arr, int N){
	int max_elem[N], len = 1;
	max_elem[0] = arr[0];
	for(int i = 1; i<N; i++){
		if(arr[i] < max_elem[0]) max_elem[0] = arr[i];
		else if(arr[i] > max_elem[len-1]) max_elem[len++] = arr[i];
		else max_elem[binary_search(max_elem, 0, len-1, arr[i])] = arr[i];
	}
	return len;
}

int main(){
	int arr[9] = {2, 5, 3, 7, 11, 8, 10, 13, 6 };
	cout<<"The longest common subsequence in the above array is "<<LIS(arr, 9)<<endl;
	return 0;
}
