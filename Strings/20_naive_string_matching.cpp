/* C++ program of a naive solution for string matching
*/
// the below code will print only the first index of the substring matched.
#include<bits/stdc++.h>
using namespace std;

int string_matching(string &s1, string &s2){
	if(s1.length()<s2.length()) return -1;
	if(s1 == s2) return 0; // return first index
	int start_index = -1;
	for(int i = 0; i<s1.size(); i++){
		if(s2[0] == s1[i]){
			int flag = 0;
			int temp = i;
			for(int j = 0; j<s2.size();j++){
				if(temp< s1.length() && s2[j] == s1[temp]){
					temp++;
				}else {
					flag = 1;
					break;
				}
			}
			if(flag == 0) {
				start_index = i;
				cout<<i<<endl;
				break; // to find all the indexes where the string matches, then comment the break statement
			}
		}
	}
	return start_index;
}

int main(){
	string s1 = "AAAA";
	string s2 = "AA";
	cout<<string_matching(s1,s2)<<endl;
	return 0;
}

