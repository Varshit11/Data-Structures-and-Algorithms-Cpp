/* C++ program to find first non repeating character in a string, in O(N) and O(1) space and
in 1 single pass. Since there are 256 characters, so the hash table of 256 is considered
constant, thats why space complexity is O(1) */

#include<iostream>
#include<string>
#include<map>
using namespace std;

char first_non_repeating(string &str){
	map<char, int> m1; // for storing count of each character
	map<char, int>m2; // for storing the first index of the character
	int i, min_index = INT_MAX;
	for(i=0;i<str.length(); i++){
		m1[str[i]]++;
		if(m2.find(str[i]) == m2.end()) m2[str[i]] = i;
	}
	map<char, int>::iterator it;
	for(it = m1.begin();it != m1.end(); it++)
		if(it->second == 1 && m2[it->first]<min_index) min_index = m2[it->first];
	
	return str[min_index];
}

int main(){
	string str("abcbadabaa");
	char ans = first_non_repeating(str);
	cout<<"The first non repeating character in the array is "<<ans<<endl;
	return 0;
}

