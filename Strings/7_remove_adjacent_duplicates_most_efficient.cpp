/* C++ program to remove adjacent duplicates in O(N) time and O(1) space */

#include<bits/stdc++.h>
using namespace std;

string remove_adjacent_duplicates(string &str){
	int s = 0, f;
	for(f = 0; f<str.length(); f++){
		if((s == 0) || str[s-1] != str[f]) str[s++] = str[f];
		else s--;
	}
	string str2(str.begin(), str.begin()+s);
	return str2;
}

int main(){
	string str("abbaca");
	str = remove_adjacent_duplicates(str);
	cout<<str<<endl;
	return 0;
}
