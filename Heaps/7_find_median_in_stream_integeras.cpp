/* C++ program to find median in stream of integers (running integers) */
// we will use heap in this code. And we will assume all the element in stream are unique
// I have not used STL in this code
#include<iostream>
using namespace std;
#define MAX 100

int arr1[MAX]; // max heap
int arr2[MAX]; // min heap
int length1 = 0; // track number of elements in max heap
int length2 = 0; // track number of elements in min heap

void swap(int* p, int* q){
	int temp = *p;
	*p = *q;
	*q = temp;
}

int left_child(int d){
	return 2*d+1;
}

int right_child(int d){
	return 2*d+2;
}

void Min_heapify(int* arr, int smallest, int N){
	int left = left_child(smallest);
	int right = right_child(smallest);
	int m = smallest;
	if(left<N && arr[left]<arr[m])
		m = left;
	if(left<N && arr[right]<arr[m])
		m = right;
	if(m == smallest)
		return;
	else{
		swap(&arr[smallest], &arr[m]);
		Min_heapify(arr, m, N);
	}
}

void Max_heapify(int* arr, int largest, int N){
	int left = left_child(largest);
	int right = right_child(largest);
	int m = largest;
	if(left<N && arr[left] > arr[m])
		m = left;
	if(right<N && arr[right] > arr[m])
		m = right;
	if(m == largest)
		return;
	else{
		swap(&arr[largest], &arr[m]);
		Max_heapify(arr, m, N);
	}
}

void insert_max(int* arr, int num, int* length){
	if(*length>MAX)
		return;
	arr[(*length)++] = num;
	int index = *length-1;
	while(true){
		if(index%2 == 1 && index > 0 && arr[index] > arr[index/2]){
			swap(&arr[index], &arr[index/2]);
			index = index/2;
		}
		else if(index%2 == 0 && index > 0 && arr[index] > arr[index/2-1]){
			swap(&arr[index], &arr[index/2-1]);
			index = index/2-1;
		}
		else
			break;
	}
}

void insert_min(int* arr, int num, int* length){
	if(*length>MAX)
		return;
	arr[(*length)++] = num;
	int index = *length-1;
	while(true){
		if(index%2 == 1 && index > 0 && arr[index] < arr[index/2]){
			swap(&arr[index], &arr[index/2]);
			index = index/2;
		}
		else if(index%2 == 0 && index > 0 && arr[index] < arr[index/2-1]){
			swap(&arr[index], &arr[index/2-1]);
			index = index/2-1;
		}
		else
			break;
	}
}

void find_median(){
	int num, cur_median, temp;
	while(true){
		cout<<"Enter the new integer "<<endl;
		cin>>num;
		if(length1 == 0 && length2 == 0){
			arr1[length1++] = num; // adding to max heap
			cur_median = num;
			cout<<"The current median is "<<num<<endl;
		}
		else if(num > cur_median){ // insert in min heap
			insert_min(arr2, num, &length2);
			if(length2-length1 == 0){
				cout<<"The current median is "<<(arr1[0]+arr2[0])/2<<endl;
				cur_median = (arr1[0]+arr2[0])/2;
			}
			else if(length2-length1 == 1){
				cout<<"The current median is "<<arr2[0]<<endl;
				cur_median = arr2[0];
			}else{
				temp = arr2[0];
				swap(&arr2[0], &arr2[length2-1]);
				length2--;
				Min_heapify(arr2, 0, length2);
				insert_max(arr1, temp, &length1);
				cout<<"The current median is "<<(arr1[0]+arr2[0])/2<<endl;
				cur_median = (arr1[0]+arr2[0])/2;
			}
		}
		else{ // since num < cur_median
			insert_max(arr1, num, &length1);
			if(length1-length2 == 0){
				cout<<"The current median is "<<(arr1[0]+arr2[0])/2<<endl;
				cur_median = (arr1[0]+arr2[0])/2;
			}
			else if(length1 - length2 == 1){
				cout<<"The current median is "<<arr1[0]<<endl;
				cur_median = arr1[0];
			}
			else{
				temp = arr1[0];
				swap(&arr1[0], &arr1[length1-1]);
				length1--;
				Max_heapify(arr1, 0, length1);
				insert_min(arr2, temp, &length2);
				cout<<"The current median is "<<(arr1[0]+arr2[0])/2<<endl;
				cur_median = (arr1[0]+arr2[0])/2;
			}
		}
	}
}

int main(){
	cout<<"Type CTRL+C to exit "<<endl;
	find_median();
	return 0;
}

