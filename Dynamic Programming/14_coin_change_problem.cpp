/* C++ program to solve Coin Change Problem 
Suppose Amount 11 and coin denomination = [1,2,5] then find minimum number of coins which can make this amount. 5,5,1 will be optimal
solution so minimum of 3 coins are required to get this amount.
At first looks like greedy problem but it isn't. We will solve using recursion and DP
*/

#include<iostream>
using namespace std;

int find_min_count(int* denom, int A, int N){ // N is the size of the denom array, A is the amount
	if(A == 0) return 0;
	else if(N == 0) return INT_MAX;
	else{
		int best = INT_MAX;
		for(int i = 0; i<N; i++) if(denom[i] <= A) best = min(best, 1+find_min_count(denom, A-denom[i], N));
		return best;
	}
}

int find_min_count_bottom_up(int* denom, int A, int N){
	int p[A+1];
	p[0] = 0;
	for(int i = 1; i<=A; i++){
		p[i] = INT_MAX;
		for(int j = 0; j<N; j++) {
			if(denom[j] <= i) {
				p[i] = min(p[i], 1+p[i-denom[j]]);
			}	
		}
	}
	return p[A];
}

int main(){
	int denom[3] = {1,2,5}, A = 11;
	int min_recur = find_min_count(denom, A, 3);
	int min_bottom_up = find_min_count_bottom_up(denom, A, 3);
	if(min_recur!=INT_MAX) cout<<"Using recursion "<<min_recur<<endl;
	else cout<<"No such combination exists "<<endl;
	if(min_bottom_up != INT_MAX) cout<<"Using bottom up DP "<<min_bottom_up<<endl;
	else cout<<"No such combination exists "<<endl;
	return 0;
}

