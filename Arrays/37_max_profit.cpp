/* C++ program to solve Best time to Buy and Sell Stock 2 
Problem Statement - https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/
*/

#include<bits/stdc++.h>
using namespace std;

int maxProfit(vector<int>& prices) {
    int max_profit = 0;
    for(int i = 1; i<prices.size(); i++) if(prices[i] > prices[i-1]) max_profit += prices[i] - prices[i-1];
    return max_profit;
}

int main(){
	// code passed all test cases on leetcode, one test case is shown here for demonstration
	vector<int> prices = {7,1,5,3,6,4};
	cout<<"The maximum profit is "<<maxProfit(prices)<<endl;
	return 0;
}
