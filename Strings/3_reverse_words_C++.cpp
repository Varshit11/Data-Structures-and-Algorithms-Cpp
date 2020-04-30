/* C++ program to reverse the words in a string with and without using 
stringstream */

#include<bits/stdc++.h>
using namespace std;

void reverse_words_stringstream(string &str){
	stringstream ss(str);
	string temp;
	string str2;
	while(ss>>temp){
		reverse(temp.begin(), temp.end());
		str2+= temp;
		str2+= " ";
	}
	reverse(str2.begin(), str2.end());
	str2.erase(0,1); // erase 1 element starting at 0 index
	cout<<str2<<endl;
}

void reverse_words(string &str){
	int N = str.length(), i = 0, b = 0;
	for(i=0; i<N;i++){
		if(str[i] == ' '){
			reverse(str.begin()+b, str.begin()+i);
			b = i+1;
		}
		else if((i+1) == N){
			reverse(str.begin()+b, str.end());
		}
	}
	reverse(str.begin(), str.end());
	cout<<str<<endl;
}

int main(){
	string str("i love algorithms");
//	reverse_words_stringstream(str); // using stringstream
	reverse_words(str); // without stringstream
	return 0;
}

