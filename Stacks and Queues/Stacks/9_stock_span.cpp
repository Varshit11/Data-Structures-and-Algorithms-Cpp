/* C++ program for stock span problem, using stack.
Given a particular stock price at particular day, how many consecutive 
days before the present day, the stock price is less than current day price
For ex. if input is 100,80,60,70,60,75,85. The output should be
1,1,1,2,1,4,6. Explanation - The default is 1 for first day, 
For 80, the previous day price (100) is not less than 80 so 1
For 60, the previous day price (80) is not less than 60 so 1
For 70, the previous day(60) is less but (80) is greater so 2
For 60, the previous day(70) is not less than 60 so 1
For 75, the previous 3 days i.e 60,70,60 are less than 75 but not 80 so span is 4
For 85, the previous 5 days i.e 75,60,70,60,80 are less but not 100 so span is 6 */

#include<bits/stdc++.h>
using namespace std;

// we will use C++ built in stack.
stack <int> s;

int* stock_span(int* arr, int n){
	int* span = new int[n];
	for(int i = 0; i<n; i++){
		span[i] = 1;
		if(i == 0){
			s.push(i);
			continue;
		}
		while(!s.empty() && arr[i] > arr[s.top()]){
			span[i] += span[s.top()];
			s.pop();
		}
		s.push(i);
	}
	return span;
}

int main(){
	int n, i;
	cout<<"Enter the number of days"<<endl;
	cin>>n;
	int* price = new int[n];
	cout<<"Enter the stock price for each day"<<endl;
	for(i=0;i<n;i++){
		cin>>price[i];
	}
	
	int* span = stock_span(price, n);
	cout<<"The stock span for each day stock price are"<<endl;
	for(i=0;i<n;i++){
		cout<<span[i]<<" ";
	}
	return 0;
}

