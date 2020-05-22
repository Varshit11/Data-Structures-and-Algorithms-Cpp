/* C++ program to sort characters by frequency
Problem Statement - https://leetcode.com/problems/sort-characters-by-frequency/
*/

#include<bits/stdc++.h>
using namespace std;

string frequencySort(string s) {
    if(s.length() == 0) return s;
    vector<int> freq(256,0);
    for(auto c:s) freq[c]++;
    map<int, string> m;
    for(int i = 0; i<256; i++) if(freq[i]>0) m[freq[i]]+= i;
    string ans;
    for(auto x: m){
        for(auto c: x.second){
            string temp(x.first, c);
            ans+= temp;
        }
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

int main(){
	// code passed all test cases on leetcode, one test case is shown here for demonstration
	string s("tree");
	cout<<"After frequency sorting the string becomes "<<frequencySort(s)<<endl;
	return 0;
}

