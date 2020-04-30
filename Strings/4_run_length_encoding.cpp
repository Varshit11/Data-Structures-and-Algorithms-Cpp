/* C++ program to implement run length encoding
*/

#include<bits/stdc++.h>
using namespace std;

void run_length(string &str){
	stringstream ss;
	int count = 1, i;
	for(i = 1; i<str.length(); i++){
		if(str[i] == str[i-1]) count++;
		else{
			ss<<str[i-1];
			ss<<count;
			count = 1;
		}
	}
	ss<<str[i-1];
	ss<<count;
	ss>>str;
}

int main(){
	string str("aaaabbbccdeaaaffmmmmmmmmmmm");
	run_length(str);
	cout<<str<<endl;
	return 0;
}

