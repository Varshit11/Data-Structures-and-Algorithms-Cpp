/* C++ program to find smallest window, using a hash table, most efficient solution */

#include<iostream>
#include<string>
#include<vector>
using namespace std;

int num_char = 256; // to create a hash table of 256 characters

string find_smallest_window(string &str, string &pattern){
	if(str.length() < pattern.length()) return "";
	vector<int> hash_str(num_char);
	vector<int> hash_pat(num_char);
	int i, start = 0, start_index = -1, min_len = INT_MAX;
	for(i=0;i<pattern.length();i++)
		hash_pat[(int)pattern[i]]++;
	
	int count = 0;
	for(i=0;i<str.length();i++){
		hash_str[(int)str[i]]++;
		if(hash_pat[(int)str[i]] != 0 && hash_str[(int)str[i]] <= hash_pat[(int)str[i]]) count++;
		
		if(count == pattern.length()){
			while(hash_str[(int)str[start]] > hash_pat[(int)str[start]] || hash_pat[(int)str[start]] == 0){
				if(hash_str[(int)str[start]] > hash_pat[(int)str[start]]) hash_str[(int)str[start]]--;
				start++;
			}
			int window_len = i-start+1;
			if(min_len > window_len){
				min_len = window_len;
				start_index = start;
			}
		}
	}
	if(start_index == -1) return "";
	string ans(str.begin()+start_index, str.begin()+start_index+min_len);
	return ans;
}

int main(){
	string str("Applied course");
	string pattern("ppe");
	string ans = find_smallest_window(str, pattern);
	cout<<ans<<endl;
	return 0;
}

