/* C++ program to all adjacent duplicates characters in a string, for ex. if string is 
"abccbad", then the output should be only "d". First "cc" duplicate will be removed, then the new 
array will be "abbad", now "bb" will be removed, now string will be "aad", so now "aa" will be 
removed. So final output = "d" */

#include<iostream>
#include<string>
#include<stack>
using namespace std;

void remove_adjacent_duplicates(string &str){
	stack<char> s;
	int i = 0;
	while(i<str.length()){
		if(s.empty()) s.push(str[i]);
		else if(str[i] == s.top()) s.pop();
		else s.push(str[i]);
		++i;
	}
	int N = s.size()-1, k = N;
	while(!s.empty()) {
		str[N--] = s.top();
		s.pop();
	}
	str.erase(str.begin()+k+1, str.end());
}

int main(){
	string str("abbaca");
	remove_adjacent_duplicates(str);
	cout<<str<<endl;
	return 0;
}

