/* C++ program to find fibonacci(N), using recursive approach, top down DP approach, bottom up DP approach  */

#include<iostream>
using namespace std;

int fib_recursive(int N){ // time complexity O(2^N), space complexity O(N) stack space
	if(N<=1) return N;
	return fib_recursive(N-1) + fib_recursive(N-2);
}

int fib_top_down(int N, int* arr){ // time complexity O(N) and space O(N) = stack space and extra array memory
	if(N>0 && arr[N] == 0) arr[N] = fib_top_down(N-1, arr) + fib_top_down(N-2, arr);
	return arr[N];
}

int fib_bottom_up(int N){ // time complexity O(N) and space O(N) = only extra array memory
	int* arr = new int[N+1];
	arr[0] = 0;
	arr[1] = 1;
	for(int i = 2; i<=N; i++) arr[i] = arr[i-1]+arr[i-2];
	return arr[N];
}

int main(){
	int N = 5;
	int* arr = new int[N+1];
	for(int i = 0; i<N;i++) arr[i] = 0;
	arr[1] = 1;
	int recur = fib_recursive(N);
	int top_down = fib_top_down(N, arr);
	int bottom_up = fib_bottom_up(N);
	cout<<"Recursive solution Fib(5) "<<recur<<"\n top down solution Fib(5) "<<top_down<<"\n Bottom up solution "<<bottom_up<<endl;
	return 0;
}

