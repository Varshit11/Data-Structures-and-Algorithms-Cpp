/* C++ program to implement rod cutting problem using recursion, top down DP and bottom up DP*/

#include<iostream>
using namespace std;

int rod_cutting_recursion(int* price, int N){
	if(N <= 0) return 0;
	int best = INT_MIN;
	for(int i = 0; i<N;i++) best = max(best, price[i]+rod_cutting_recursion(price, N-i-1));
	return best;
}

int rod_cutting_top_down(int* price, int* r, int N){
	if(r[N-1] > 0) return r[N-1];
	if(N == 0) return 0;
	int best = INT_MIN;
	for(int i = 0; i<N;i++) best = max(best, price[i] + rod_cutting_top_down(price, r, N-i-1));
	r[N-1] = best;
	return r[N-1];
}

int rod_cutting_bottom_up(int* price, int N){
	int r[N+1];
	r[0] = 0;	
	for(int i = 1; i<=N; i++){
		int best = INT_MIN;
		for(int j = 0; j<i; j++) {
			best = max(best, price[j]+r[i-j-1]);	
		}
		r[i] = best;
	}
	return r[N];
}

int main(){
	int price[5] = {2,3,7,8,9}, N = 5;
	int r[5] = {INT_MIN};
	r[0] = 0;
	cout<<"max rod using recursive "<<rod_cutting_recursion(price, N)<<endl;
	cout<<"max rod using top down DP "<<rod_cutting_top_down(price, r, N)<<endl;
	cout<<"max rod using bottom up DP "<<rod_cutting_bottom_up(price, N)<<endl;
	return 0;
}

