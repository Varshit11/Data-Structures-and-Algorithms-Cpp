/* C++ program Find the smallest window in a string containing all characters of another string
*/

#include<iostream>
#include<string>
#include<vector>
using namespace std;

void find_smallest_window(string &str, string &pattern){
	string temp;
	string temp2;
	string ans;
	vector<int> indexes;
	int i;
	for(i = 0; i<str.length(); i++){ // this will store all the indexes of characters which are found in pattern
		if(pattern.find(str[i]) != string::npos) indexes.push_back(i);
	}
	i = 0;
	while(i < indexes.size()){ // now we will start from the index stored in indexes vector and find the substring if it exists
		int j = indexes[i];
		temp = pattern; // we copy pattern in temp variable, and each time we find character in original string matching with pattern we will delete that character from temp until temp is empty
		while(j<str.length()){
			if(temp.find(str[j]) != string::npos){
				temp.erase(temp.find(str[j]), 1);
				temp2+= str[j];
				if(temp.length() == 0 && ans.length() == 0){ // now temp is empty so temp2 can be one of the substring which contains all the characters of pattern
					ans = temp2; // ans string is initially empty so when we find the first substring we will directly copy temp2 to ans
					temp2.clear();
					break;
				}
				else if(temp.length() == 0){ // temp is empty so temp2 can be one of the final substring, now since ans string is not empty we will compare the length of ans and temp2 and copy the minimum of them to ans
					if(temp2.length() < ans.length())
						ans = temp2;
					temp2.clear();
					break;
				}
			}
			else if(temp2.length()>0) temp2+= str[j]; // if we dont find the character in the pattern but our temp2 string length is greater than 1, it means we just have to append the character in temp2
			++j; // moving to next character index
		}
		++i; // moving to next index where the character matches with one of the pattern characters
	}
	
	cout<<"The smallest window in a string containing all characters of another string is \n"<<ans<<endl;
}

int main(){
	string str("Applied course");
	string pattern("eou");
	find_smallest_window(str, pattern);
	return 0;
}

