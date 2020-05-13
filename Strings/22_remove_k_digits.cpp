/* C++ program to solve remove K digits problem
Problem Statement - https://leetcode.com/problems/remove-k-digits/
*/

#include<bits/stdc++.h>
using namespace std;

string removeKdigits(string num, int k) {
    if(num.length() == k) return "0";
    stack <char> s;
    int temp = k, i = 0;
    string ans;
    while(i<num.size()){
        if(s.empty() || ((int)num[i]-48) >= ((int)s.top() - 48)) s.push(num[i]);
        else if(temp == 0) s.push(num[i]);
        else{
            while(!s.empty() && ((int)num[i]-48) < ((int)s.top() - 48) && temp>0){
                s.pop();
                temp--;
            }
            s.push(num[i]);
        }
        ++i;
    }
    while(temp > 0 && !s.empty()) {
        s.pop();
        --temp;
    } 
    while(!s.empty()) {
        ans+= s.top();
        s.pop();
    }
    reverse(ans.begin(), ans.end());
    while(ans[0] == '0') {
        ans.erase(ans.begin());
    }
    if(ans.length() == 0) ans+= '0';
    return ans;
}
    
int main(){
	// code passed all test cases on leetcode, one test case is shown here for demonstration
	string num = "10200";
	int k = 1;
	string ans = removeKdigits(num, k);
	cout<<ans<<endl;
	return 0;
}
