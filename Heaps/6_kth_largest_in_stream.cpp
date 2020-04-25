/* find Kth largest element in the stream..element will be coming after some time and in this case the 
size of the array is not fixed. */

#include<iostream>
using namespace std;

void swap(int* p, int* q){
	int temp = *p;
	*p = *q;
	*q = temp;
}

void Min_heapify(int* arr, int smallest, int N){
	int left = 2*smallest+1;
	int right = 2*smallest+2;
	int m = smallest;
	if(left<N && arr[left]<arr[m])
		m = left;
	if(right<N && arr[right]<arr[m])
		m = right;
	if(m == smallest)
		return;
	else{
		swap(&arr[m], &arr[smallest]);
		Min_heapify(arr, m, N);
	}
}

void build_min_heap(int* arr, int N){
	for(int i = N/2-1; i>=0;i--)
		Min_heapify(arr, i, N);
}

void kth_largest_stream(int k){
	int* arr = new int[k];
	int num, count = 0;
	while(true){
		cout<<"Enter the new element in stream "<<endl;
		cin>>num;
		count++;
		if(count == k){
			arr[count-1] = num;
			build_min_heap(arr, k);
			cout<<"The kth largest till now is "<<arr[0]<<endl;
		}	
		else if(count < k){
			arr[count-1] = num;
			cout<<"NA"<<endl;
		}
		else{
			if(num > arr[0]){
				arr[0] = num;
				Min_heapify(arr, 0, k);
			}
			cout<<"The kth largest till now is "<<arr[0]<<endl;
		}	
	}
}

int main(){
	int k;
	cout<<"Enter the value of K"<<endl;
	cin>>k;
	cout<<"Type Ctrl+C to end the stream "<<endl;
	kth_largest_stream(k);
	return 0;
}
