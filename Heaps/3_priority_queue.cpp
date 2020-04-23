/* C++ program to implement priority queue */

#include<iostream>
using namespace std;

int length; // length of the array 

void swap(int* arr, int i, int j){
	int temp = arr[i];
	arr[i] = arr[j];
	arr[j] = temp;
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

void build_max_heap(int* arr){
	for(int i = length/2-1; i>=0;i--)
		Max_heapify(arr, i, length);
}

int max_value(int* arr){
	return arr[0]; // considering we have built the max heap..
}

int extract_max(int* arr){
	int temp = arr[0];
	swap(arr, 0, length-1);
	length--;
	Max_heapify(arr, 0, length);
	return temp;
}

void upward_check(int* arr, int index){
	while(true){
		if(index%2 == 1 && index > 0 && arr[index] > arr[index/2]){
			swap(arr, index, index/2);
			index = index/2;
		}else if(index%2 == 0 && index > 0 && arr[index] > arr[index/2-1]){
			swap(arr, index, index/2-1);
			index = index/2-1;
		}else{
			break;
		}
	}
}

void insert(int* arr, int data){
	arr[length] = data;
	length++;
	upward_check(arr, length-1);
}

void increase_key(int* arr, int x, int k){ // condition k>=x
	int i;
	for(i = 0; i<length;i++){
		if(arr[i] == x){
			arr[i] = k;
			break;
		}
	}
	// i contains the index where x is present and changed to k
	upward_check(arr, i);
}

void print_array(int* arr){
	for(int i = 0; i<length;i++)
		cout<<arr[i]<<" ";
	cout<<endl;
}

int main(){
	int arr[100] = {0}, i;
	cout<<"Enter the number of elements in the array "<<endl;
	cin>>length;
	cout<<"Enter the elements in the array "<<endl;
	for(i=0;i<length;i++)
		cin>>arr[i];
	
	build_max_heap(arr); // construct the max heap;
	while(true){
		cout<<"There are 4 operations in priority queue "<<endl;
		cout<<"1. Find max in array\n 2. Extract max in array "<<endl;
		cout<<"3. Insert a new element in array"<<endl<<" 4. Increase a particular element in array"<<endl;
		cout<<"Type the respective number for the operation you want, if you want to exit type any other number "<<endl;
		int d;
		cin>>d;
		switch(d){
			case 1:
				cout<<"The maximum element in the array is "<<max_value(arr)<<endl;
				break;
			case 2:
				if(length < 0)
					cout<<"The array is empty"<<endl;
				else{
					cout<<"The maximum element extraced from the array is "<<extract_max(arr)<<endl;
					cout<<"The updated array is "<<endl;
					print_array(arr);
				}
				break;
			case 3:
				int data;
				cout<<"Enter the new element to be inserted"<<endl;
				cin>>data;
				insert(arr, data);
				cout<<"The updated array is "<<endl;
				print_array(arr);
				break;
			case 4:
				int k, x;
				cout<<"Enter the element and the value to be increased "<<endl;
				cin>>x>>k;
				increase_key(arr, x, k);
				cout<<"The updated array is "<<endl;
				print_array(arr);
				break;
			default:
				cout<<"Ending the process "<<endl;
				exit(0);
		}
	}
	return 0;	
}

