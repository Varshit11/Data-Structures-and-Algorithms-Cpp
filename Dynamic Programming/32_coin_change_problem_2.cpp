/* C++ program to solve coin change problem 2
Problem Statement - https://leetcode.com/problems/coin-change-2/
*/

#include<bits/stdc++.h>
using namespace std;

int change(int amount, vector<int>& coins) {
    vector<int> dp(amount+1,0);
    dp[0] = 1;
    for(int i = 0; i<coins.size(); i++){
        for(int j = coins[i]; j<=amount; j++){
                dp[j] += dp[j-coins[i]];
        }
    }
    return dp[amount];
}

int main(){
	// code passed all test cases on leetcode, one test case is shown here for demonstration
	int amount = 5;
	vector<int> coins = {1,2,5};
	cout<<"The number of combinations that make up this amount is "<<change(amount, coins)<<endl;
	return 0;
}

