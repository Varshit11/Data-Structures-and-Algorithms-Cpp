/* C++ program to solve Letter Combinations of a Phone Number problem 
Problem Statement - 
*/

#include<iostream>
#include<vector>
#include<string>
using namespace std;

void find_combin(vector<string> &ans, vector<string> &v, vector<int> &index, int k){
    if(index[0] >= v[0].size()) return;
    string temp;
    for(int i = 0; i<k; i++){
        if(index[i] >= v[i].size()){
            index[i] = 0;
            return;
        }else temp+= v[i][index[i]];
    }
    ans.push_back(temp);
    for(int i = k-1; i>=0;i--){
        index[i]++;
        find_combin(ans, v, index, k);
    }
} 
    
    
vector<string> letterCombinations(string digits) {
    vector<string> ans;
    if(digits.size() == 0) return ans; 
    vector<string> orig = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    vector<int> index(digits.size());
    vector<string> v;
    for(int i = 0; i<digits.size(); i++) v.push_back(orig[(int)digits[i]-50]);
    find_combin(ans, v, index, digits.size());
    return ans;
}

int main(){
	// code passed all test cases on leetcode, one test case is shown here for demonstration
	string digits("23");
	vector<string> ans = letterCombinations(digits);
	cout<<"The letter combinations of the above phone number are "<<endl;
	for(int i = 0; i<ans.size(); i++) cout<<ans[i]<<endl;
	return 0;
}
