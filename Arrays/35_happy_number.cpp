/* C++ program to find if given number is happy number or not
Problem Statement - https://leetcode.com/problems/happy-number/
*/

#include<bits/stdc++.h>
using namespace std;

int find_square(int N){
	int sum = 0;
	while(N > 0){
		sum+= (N%10)*(N%10);
		N/=10;
	}
	return sum;
}

bool happy_number(int N){
	int slow = N, fast = N;
	do{
		slow = find_square(slow);
		fast = find_square(find_square(fast));
	}while(slow!=fast);
	return slow == 1;
}

int main(){
	// code passed all test cases on leetcode, one test case is shown here for demonstration
	int N = 19;
	if(happy_number(N)) cout<<"The given number is a happy number "<<endl;
	else cout<<"The given number is not a happy number "<<endl;
	return 0;
}

