/* C++ program to Generate Parentheses
Problem Statement - https://leetcode.com/problems/generate-parentheses/
*/

#include<bits/stdc++.h>
using namespace std;

void compute(vector<string> &ans, string word, int leftStock, int rightStock){
    if(leftStock == 0 && rightStock == 0) ans.push_back(word);
    else{
        if(leftStock > 0) compute(ans, word+"(", leftStock-1, rightStock+1);
        if(rightStock > 0) compute(ans, word+")", leftStock, rightStock-1);
    }
}
    
vector<string> generateParenthesis(int n) {
    vector<string> ans;
    if(n == 0) return ans;
    else{
        string word;
        compute(ans, word, n, 0);
        return ans;
    }
}

int main(){
	// code passed all test cases on leetcode, one test case is shown here for demonstration
	int n = 3;
	vector<string> ans = generateParenthesis(n);
	for(int i = 0; i<ans.size(); i++) cout<<ans[i]<<endl;
	return 0;
}

