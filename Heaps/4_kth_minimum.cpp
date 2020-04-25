/* C++ program to find the kth smallest element in the array */

#include<iostream>
using namespace std;

void swap(int* arr, int i, int j){
	int temp = arr[i];
	arr[i] = arr[j];
	arr[j] = temp;
}

void Min_heapify(int* arr, int smallest, int N){
	int left = 2*smallest+1;
	int right = 2*smallest + 2;
	int m = smallest;
	if(left<N && arr[left]<arr[m])
		m = left;
	if(right<N && arr[right]<arr[m])
		m = right;
	if(m == smallest)
		return;
	else{
		swap(arr, smallest, m);
		Min_heapify(arr, m, N);
	}
}

void build_min_heap(int* arr, int N){
	for(int i = N/2-1; i>=0;i--)
		Min_heapify(arr, i, N);
}

int find_kth_min(int* arr, int k, int N){
	if(k>N)
		return INT_MIN;
	build_min_heap(arr, N);
	for(int i = 0; i<k-1;i++){
		swap(arr, 0, N-1);
		N--;
		Min_heapify(arr, 0, N);
	}
	return arr[0];
}

int main(){
	int N, i, k;
	cout<<"Enter the number of elements and the value of k "<<endl;
	cin>>N>>k;
	int* arr = new int[N];
	cout<<"Enter the elements "<<endl;
	for(i = 0; i<N; i++)
		cin>>arr[i];
	cout<<"The kth minimum in the array is "<<find_kth_min(arr, k, N)<<endl;
	return 0;
}

