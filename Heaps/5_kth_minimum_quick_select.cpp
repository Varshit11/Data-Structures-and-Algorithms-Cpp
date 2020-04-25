/* C++ program to find kth minimum element using quick select */

#include<iostream>
using namespace std;

void swap(int* arr, int i, int j){
	int temp = arr[i];
	arr[i] = arr[j];
	arr[j] = temp;
}

int partition(int* arr, int l, int r){
	int x = arr[r], i = l;
	for(int j = l; j<=r-1;j++){
		if(arr[j] <= x){
			swap(arr, i, j);
			i++;
		}
	}
	swap(arr, i, r);
	return i;
}

int find_k_min(int* arr, int l, int r, int k){
	if(k>0 && k<=r){
		int pos = partition(arr, l, r);
		if(pos == k-1)
			return arr[pos];
		if(pos > k-1)
			return find_k_min(arr, l, pos-1, k);
		else
			return find_k_min(arr, pos+1, r, k);
	}else{
		return INT_MAX;
	}
}

int main(){
	int N, i, k;
	cout<<"Enter the number of elements in the array and the value of k "<<endl;
	cin>>N>>k;
	int* arr= new int[N];
	cout<<"Enter the elements "<<endl;
	for(i=0;i<N;i++){
		cin>>arr[i];
	}
	cout<<"The kth smallest element in the array is "<<find_k_min(arr, 0, N-1, k);
	return 0;
}
