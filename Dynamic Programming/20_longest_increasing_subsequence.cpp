/* C++ program to find the longest increasing subsequence using recursion - O(2^N) and DP - O(N^2)
*/

#include<iostream>
using namespace std;

int LIS_recursion(int* arr, int N, int &max_num){
	if(N == 1) return 1;
	int res, max_till_here = 1;
	for(int i = 1; i<N; i++){
		res = LIS_recursion(arr, i, max_num);
		if(arr[i-1] < arr[N-1] && res+1 > max_till_here) max_till_here = res+1;
	}
	if(max_num < max_till_here) max_num = max_till_here;
	return max_till_here;
}

int LIS_DP(int* arr, int N){
	int temp[N];
	for(int i = 0; i<N; i++) temp[i] = 0;
	temp[0] = 1;
	for(int i = 1; i<N; i++){
		for(int j = 0; j<i; j++) if(arr[i] > arr[j] && temp[i] < temp[j]) temp[i] = temp[j];
		temp[i]++;
	}
	return temp[N-1];
}

int main(){
	int arr[8] =  {10, 22, 9, 33, 21, 50, 41, 60};
	int max_num = 1;
	int temp = LIS_recursion(arr, 8, max_num);
	cout<<"Using recursion the longest increasing subsequence is "<<max_num<<endl;
	int ans = LIS_DP(arr, 8);
	cout<<"Using recursion the longest increasing subsequence is "<<ans<<endl;
	return 0;
}

