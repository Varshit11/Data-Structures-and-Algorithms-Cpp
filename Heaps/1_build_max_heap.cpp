/* C++ program to build the max heap from the given array */

#include<iostream>
using namespace std;

void swap(int* arr, int largest, int m){
	int temp = arr[largest];
	arr[largest] = arr[m];
	arr[m] = temp;	
}

void Max_heapify(int* arr, int largest, int length){
	int l = 2*largest + 1;
	int r = 2*largest + 2;
	int m = largest;
	if(l < length && arr[l] > arr[m])
		m = l;
	if(r < length && arr[r] > arr[m])
		m = r;
	if(m == largest)
		return;
	else{
		swap(arr, largest, m);
		Max_heapify(arr, m, length);
	}	
}

void build_heap(int* arr, int length){
	for(int i = length/2-1; i>=0; i--){
		Max_heapify(arr, i, length);
	}
}

int main(){
	int length, i;
	cout<<"Enter the length of the array "<<endl;
	cin>>length;
	cout<<"Enter the elements of the array "<<endl;
	int* arr = new int[length];
	for(i=0;i<length;i++)
		cin>>arr[i];
	build_heap(arr, length);
	cout<<"The array after building heap is "<<endl;
	for(i=0; i<length; i++){
		cout<<arr[i]<<" ";
	}
	return 0;
}

