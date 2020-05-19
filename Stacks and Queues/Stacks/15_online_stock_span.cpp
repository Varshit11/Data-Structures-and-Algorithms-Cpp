/* C++ program to solve Online Stock Span Problem
Problem Statement - https://leetcode.com/problems/online-stock-span/
*/

#include<bits/stdc++.h>
using namespace std;

stack<pair<int, int>> s;
int next(int price) {
    pair<int, int> temp(price, 1);
    while(!s.empty() && s.top().first <= temp.first){
        temp.second += s.top().second;
        s.pop();
    }
    s.push(temp);
    return temp.second;
}

int main(){
	// code passed all test cases on leetcode, one test case is shown here for demonstration
	// numbers will be continuously going into next function, so we will pass these numbers in a for loop
	vector<int> prices = {100, 80, 60, 70, 60, 75, 85};
	for(int i = 0; i<7;i++) cout<<next(prices[i])<<" ";
	return 0;
}
