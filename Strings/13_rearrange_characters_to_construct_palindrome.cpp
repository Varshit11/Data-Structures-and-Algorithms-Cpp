/* C++ program to check whether we can contruct the palindrome from the input string or not, if we can
contruct palindrome then contruct any one palindrome out of string */

#include<iostream>
#include<string>
#include<map>
using namespace std;

map<char, int> m; // declared globally for use in all functions

bool check_palindrome(string &str){
	int odd_count = 0, i;
	for(i=0;i<str.length(); i++){
		m[str[i]]++;
		if(m[str[i]]%2 == 1) odd_count++;
		else odd_count--;
	}
	return (odd_count == 1 || odd_count == 0) ? true : false;
}

pair<char, int> count_character(){
	for(auto x = m.begin(); x!= m.end(); x++) if(x->second%2 == 1) return make_pair(x->first, x->second);
	return make_pair(' ', 0);
}

void construct_palindrome(string &str){
	pair<char, int> d = count_character();
	int i, j;
	if(d.second%2 == 1){
		int start = (str.length()-1)/2 - d.second/2;
		i = 0;
		while(i<d.second) {
			str[start++] = d.first;
			++i;
		}
	}
	i = 0, j = str.length()-1;
	for(auto x = m.begin(); x!= m.end(); x++){
		if(x->second%2 == 0){
			int temp = x->second;
			while(temp > 0){
				str[i++] = x->first;
				str[j--] = x->first;
				temp-=2;
			}
		}
	}
}

int main(){
	string str("carraceee");
	if(check_palindrome(str)){
		cout<<"We can create palindrome "<<endl;
		construct_palindrome(str);
		cout<<"One of the palindrome which we can contruct is \n"<<str<<endl;
	}else cout<<"We cannot create palindrome of this string "<<endl;
	return 0;
}

