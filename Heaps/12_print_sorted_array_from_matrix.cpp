/* C++ program to print all elements in sorted order from row and column wise sorted matrix.
Problem Statement - https://www.geeksforgeeks.org/print-elements-sorted-order-row-column-wise-sorted-matrix/
*/

#include<iostream>
#include<vector>
using namespace std;

void swap(vector<pair<int,int>>& arr, int i, int j){
	pair<int, int> temp = arr[i];
	arr[i] = arr[j];
	arr[j] = temp;
}

void Min_heapify(vector<vector<int>>& nums, vector<pair<int,int>>& arr, int smallest, int N){
	int left = 2*smallest+1;
	int right = 2*smallest+2;
	int m = smallest;
	if(left < N && nums[arr[left].first][arr[left].second] < nums[arr[m].first][arr[m].second])
		m = left;
	if(right < N && nums[arr[right].first][arr[right].second] < nums[arr[m].first][arr[m].second])
		m = right;
	if(m == smallest)
		return;
	else{
		swap(arr, m, smallest);
		Min_heapify(nums, arr, m, N);
	}
}

void build_min_heap(vector<vector<int>>& nums, vector<pair<int,int>>& arr, int N){
	for(int i = N/2-1; i>=0;i--)
		Min_heapify(nums, arr, i, N);
}

void sort_col_row(vector<vector<int>>& nums, int N){
	int i, j;
	vector<pair<int, int>> arr;// our heap will store the matrix index
	for(i=0;i<N;i++)
		arr.push_back(make_pair(0, i)); // copying the first row elements in the heap vector
	build_min_heap(nums, arr, N); // building the min heap of N elements.
	
	int count = 0;
	while(count < N*N){
		cout<<nums[arr[0].first][arr[0].second]<<" ";
		arr[0].first++;
		if(arr[0].first >= N){ // if one of the column is processed fully, then make the element of matrix INT_MAX
			nums[arr[0].first][arr[0].second] = INT_MAX;
		}
		Min_heapify(nums, arr, 0, N);
		count++;
	}
}

int main(){
	int N, i, j, num;
	cout<<"Enter the value of N "<<endl;
	cin>>N;
	vector<vector<int>> nums(N);
	cout<<"Enter the values in the matrix "<<endl;
	for(i = 0; i<N; i++)
		for(j =0; j<N; j++){
			cin>>num;
			nums[i].push_back(num);
		}
		
	cout<<"The sorted array from the matrix is "<<endl;
	sort_col_row(nums, N);
	return 0;
}

