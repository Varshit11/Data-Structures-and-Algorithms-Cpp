/* C++ program to find Best Time to Buy and Sell Stock
Problem Statement - https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
*/

#include<bits/stdc++.h>
using namespace std;

int maxProfit(vector<int>& prices) {
    if(prices.size() == 0 || prices.size() == 1) return 0;
    int min_cur = prices[0], max_profit = 0, temp_profit;
    for(int i = 1; i<prices.size(); i++){
        if(min_cur < prices[i]){
            temp_profit = prices[i]-min_cur;
            max_profit = max(max_profit, temp_profit);
        }else min_cur = prices[i];
    }
    return max_profit;
}

int main(){
	// code passed all test cases on leetcode, one test case is shown here for demonstration
	vector<int> prices = {7,1,5,3,6,4};
	cout<<"The maximum profit is "<<maxProfit(prices)<<endl;
	return 0;
}
