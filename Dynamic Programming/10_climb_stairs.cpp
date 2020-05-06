/* C++ program to solve climbing stairs problem using recursion and DP
*/
#include<iostream>
using namespace std;

int climb_recursive(int N){ // N will be always non negative
	if(N<=2) return N;
	return climb_recursive(N-1) + climb_recursive(N-2);
}

int climb_dp(int N){
	if(N <= 2) return N;
	int v1 = 1, v2 = 2; // for N = 1 and N = 2 respectively
	int ans;
	for(int i = 3; i<=N; i++){
		ans = v1+v2;
		v1 = v2;
		v2 = ans;
	}
	return ans;
}

int main(){
	int N = 5;
	cout<<"Using recursive approach, the number of ways to climb a stair of 5 steps are "<<climb_recursive(N)<<endl;
	cout<<"Using DP, the number of ways to climb a stair of 5 steps are "<<climb_dp(N)<<endl;
}

