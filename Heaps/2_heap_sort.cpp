/* C++ program to do heap sort */

#include<iostream>
using namespace std;

void swap(int* arr, int largest, int m){
	int temp = arr[largest];
	arr[largest] = arr[m];
	arr[m] = temp;
}

void Max_heapify(int* arr, int largest, int N){
	int left = 2*largest + 1;
	int right = 2*largest + 2;
	int m = largest;
	if(left<N && arr[left]>arr[m])
		m = left;
	if(right<N && arr[right]>arr[m])
		m = right;
	if(m == largest)
		return;
	else{
		swap(arr, largest, m);
		Max_heapify(arr, m, N);
	}
}

void build_max_heap(int* arr, int N){
	for(int i = N/2-1; i>=0; i--)
		Max_heapify(arr, i, N);
}

void heap_sort(int* arr, int N){
	build_max_heap(arr, N);
	int i = N-1;
	while(i>=0){
		swap(arr, 0, i);
		i--;
		Max_heapify(arr, 0, i+1);
	}
}

int main(){
	int N, i;
	cout<<"Enter the number of elements in the array "<<endl;
	cin>>N;
	int* arr = new int[N];
	cout<<"Enter the elements of the array "<<endl;
	for(i=0;i<N;i++)
		cin>>arr[i];
	heap_sort(arr, N);
	cout<<"The sorted array is "<<endl;
	for(i=0;i<N;i++)
		cout<<arr[i]<<" ";
	return 0;
}

