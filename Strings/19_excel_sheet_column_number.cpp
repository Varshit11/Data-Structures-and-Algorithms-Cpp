/* C++ program to find excel sheet column number
Problem Statement - https://leetcode.com/problems/excel-sheet-column-number/
*/

#include<bits/stdc++.h>
using namespace std;

int titleToNumber(string s) {
    if(s.length() == 0) return 0;
    int num = 0, j = 0;
    for(int i = s.length()-1; i>=0; i--){
        num+= pow(26,j)*((int)s[i]-64);
        j++;
    }
    return num;
}

int main(){
	// code passed all test cases on leetcode, one test case is shown here for demonstration
	string s = "ZY";
	cout<<"The column number for this string in excel will be "<<titleToNumber(s)<<endl;
	return 0;
}

