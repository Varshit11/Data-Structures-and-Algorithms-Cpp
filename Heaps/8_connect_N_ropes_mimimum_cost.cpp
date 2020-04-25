/* C++ program to connect N ropes with minimum cost. An array of size N contains the length of each rope.
When we connect 2 ropes, the cost is the length of 2 ropes. We have to continue adding this till we
have connected all the N ropes. For ex if array is 5,2,3,9. The optimial solution is - 
2+3 + ((2+3)+5) + (((2+3)+5)+9) = 34, first 2 and 3 will be joined so cost is 5, then this recently joined
rope will be connected to rope with length  5 so the cost now becomes, 5+(5+5), and so on */

#include<iostream>
using namespace std;
int length;

void swap(int* p, int* q){
	int temp = *p;
	*p = *q;
	*q = temp;
}

void Min_heapify(int* arr, int smallest, int N){
	int left = 2*smallest + 1;
	int right = 2*smallest + 2;
	int m = smallest;
	if(left<N && arr[left] < arr[m])
		m = left;
	if(right<N && arr[right] < arr[m])
		m = right;
	if(m == smallest)
		return;
	else{
		swap(&arr[m], &arr[smallest]);
		Min_heapify(arr, m , N);
	}
}

void build_min_heap(int* arr){
	for(int i = length/2-1; i>=0;i--)
		Min_heapify(arr, i, length);
}

void insert_min(int* arr, int num){
	arr[length++] = num;
	int index = length-1;
	while(index > 0){
		if(index%2 == 1 && arr[index] < arr[index/2]){
			swap(&arr[index], &arr[index/2]);
			index = index/2;
		}
		else if(index%2 == 0 && arr[index] < arr[index/2-1]){
			swap(&arr[index], &arr[index/2-1]);
			index = index/2-1;
		}
		else
			break;
	}
}

int find_cost(int* arr){
	int cost = 0, min1, min2;
	build_min_heap(arr);
	while(length > 1){
		int cur_cost = 0;
		for(int i = 0; i<2;i++){
			cur_cost += arr[0];
			swap(&arr[0], &arr[length-1]);
			length--;
			Min_heapify(arr, 0, length);
		}
		insert_min(arr, cur_cost);
		cost+= cur_cost;
	}
	return cost;
}

int main(){
	cout<<"Enter the number of elements in the array "<<endl;
	cin>>length;
	int* arr = new int[length];
	cout<<"Enter the elements of the array "<<endl;
	for(int i = 0; i<length; i++)
		cin>>arr[i];
	cout<<"The cost of connecting all the ropes with minimum cost is "<<find_cost(arr)<<endl;
	return 0;
}

