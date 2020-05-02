/* C++ program to rotate string
Problem Statement - https://leetcode.com/problems/rotate-string/
*/

#include<iostream>
#include<string>
using namespace std;

bool rotateString(string A, string B) {
    if(A.length()!=B.length()) return false;
    if(A == "" && B == "") return true;
    int i = 0;
    while(i<A.length()){
        if(A == B) return true;
        char temp = A[0];
        A.erase(0,1);
        A+=temp;
        ++i;
    }
    return false;
}

int main(){
	// code passed all test cases on leetcode, one of the test case is shown here for demonstration
	string A = "abcde";
	string B = "cdeab";
	if(rotateString(A, B)) cout<<"A string after rotating becomes B string"<<endl;
	else cout<<"A string after rotating does not becomes B string"<<endl;
	return 0;
}
