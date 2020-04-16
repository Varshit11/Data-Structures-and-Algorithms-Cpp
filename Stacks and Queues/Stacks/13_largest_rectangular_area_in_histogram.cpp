/* C++ program to find largest rectangular area in histogram.*/

#include<bits/stdc++.h>
using namespace std;

stack <int> s;

int find_largest_area(int* arr, int N){
	int area, max_area = INT_MIN, i = 0, d;
	while(i<N){
		if(s.empty() || arr[s.top()] <= arr[i])
			s.push(i++);
		else{
			d = s.top();
			s.pop();
			area = arr[d]*(s.empty() ? i:i-s.top()-1);
			if(area > max_area)
				max_area = area;
		}
	}
	while(!s.empty()){
		d = s.top();
		s.pop();
		area = arr[d]*(s.empty()?i:i-s.top()-1);
		if(area > max_area)
			max_area = area;
	}
	return max_area;
}

int main(){
	int N, i;
	cout<<"Enter the number of histogram bars"<<endl;
	cin>>N;
	int* arr = new int[N];
	cout<<"Enter the height of each histogram bars"<<endl;
	for(i=0;i<N;i++){
		cin>>arr[i];
	}
	int ans = find_largest_area(arr, N);
	cout<<"The largest rectangular area in histogram is "<<ans<<endl;
	return 0;
}

