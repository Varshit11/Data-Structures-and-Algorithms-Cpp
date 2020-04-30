/* C++ program to remove all the duplicates from the string. I will use solve this with map
and with bitwise vector */

#include<iostream>
#include<string>
#include<map>
using namespace std;

void remove_duplicates_using_map(string &str){
	map<char, int> m;
	for(int i =0; i<str.length();i++)
		m[str[i]]++;
	str.clear();
	for(auto x = m.begin(); x!=m.end();x++)
		str+= x->first;
}

void remove_duplicates_bitwise_vector(string &str){
	int i = 0, l = 0, B = 0;
	cout<<str.length()<<endl;
	for(i=0;i<str.length(); i++){
		int x = str[i] - 97;
		if((B & (1<<x)) == 0){
			str[l++] = str[i];
			B = (B | (1<<x));
		}
	}
	str.erase(str.begin()+l, str.end());
}

int main(){
	string str("bbaccdefatafaz");
//	remove_duplicates_using_map(str); // call this if you want map based approach
	remove_duplicates_bitwise_vector(str);
	cout<<str<<endl;
	return 0;
}

