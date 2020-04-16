/* C++ program to implement petrol filling problem. Suppose you have N 
petrol pumps which have some amount of petrol. You will be
given an array of amount of petrol required to move from 1 petrol pump to another. For ex. if the array
is 2 4 3 5, it means to travel from pump1 to pump2, we need 2 litres, 
from pump2 to pump3, we need 4 litres, from pump3 to pump4, we need 
3 litres, from pump4 to again pump1, we will require 5 litres. Note this 
is only one direction, you cannot go from pump2 to pump1. We need to find a path
from any one of the pump, so that we can again come to the same pump without exhausting the fuel.
For ex. The amount of petrol in 5 pumps is 1 2 3 4 5, and the petrol required to cover distance from
one petrol pump to another is 3 4 5 1 2. By observing both arrays, if we start from
pump4, then we can again get back to pump4 without exhausting the fuel.
So the final output will be 4 */

#include<bits/stdc++.h>
using namespace std;

int find_path(int* arr1, int* arr2, int n){
	int start = 0, i, sum = 0, diff = 0;
	for(i=0;i<n;i++){
		sum+= arr1[i]-arr2[i];
		if(sum<0){
			diff+=sum;
			start = i+1;
			sum = 0;
		}
	}
	return (sum+diff >= 0)? start : -1;
}

int main(){
	int N, i;
	cout<<"Enter the number of petrol pumps"<<endl;
	cin>>N;
	int* arr1 = new int[N];
	int* arr2 = new int[N];
	cout<<"Enter the capacity and petrol required to travel to next pump"<<endl;
	for(i=0;i<N;i++){
		cin>>arr1[i]>>arr2[i];
	}
	int ans = find_path(arr1, arr2, N);
	(ans == -1)?cout<<"There is no such pump"<<endl : cout<<"Petrol pump "<<(ans+1)<<" satisfies this property"<<endl;
	return 0;
}

